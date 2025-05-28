// 1. Task-Level Parallelism with Time
#include <stdio.h>
#include <omp.h>

void task1(int *result) {
    printf("Task 1 started\n");
    // Simulate some computation
    for (int i = 0; i < 100000000; i++);
    *result = 10; // Simulate some result from task 1
    printf("Task 1 finished\n");
}

void task2(int *result) {
    printf("Task 2 started\n");
    // Simulate some computation
    for (int i = 0; i < 100000000; i++);
    *result = 20; // Simulate some result from task 2
    printf("Task 2 finished\n");
}

void task3(int result1, int result2) {
    printf("Task 3 started\n");
    // Simulate combining results from task 1 and task 2
    int combined_result = result1 + result2;
    printf("Task 3 finished. Combined result: %d\n", combined_result);
}

int main() {
    int result1 = 0, result2 = 0;

    // Set the number of threads to use
    omp_set_num_threads(4);

    // Parallel region where tasks will be defined
    #pragma omp parallel
    {
        #pragma omp single // Ensures that only one thread enters this section
        {
            // Create independent tasks
            #pragma omp task shared(result1)
            task1(&result1);

            #pragma omp task shared(result2)
            task2(&result2);

            // Create a dependent task that depends on both task1 and task2
            #pragma omp task depend(in: result1) depend(in: result2) 
            task3(result1, result2);
        }
    }

    return 0;
}


// result( hmny pointer pass kiye ha) mein value assign hogi, means directly memory location py update horaha,tak1 ko result1 pass kiya ha,jo ky as result accept hua h,but memory mein to result1 hoga , hmny pointer pass kiye ha.

Output (Order may vary based on thread scheduling):
Task 1 started
Task 2 started
Task 1 finished
Task 2 finished
Task 3 started
Task 3 finished. Combined result: 30


