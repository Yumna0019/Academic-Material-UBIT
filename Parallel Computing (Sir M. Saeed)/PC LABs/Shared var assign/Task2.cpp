// 2. Barrier Example with Time
#include <stdio.h>
#include <omp.h>

void task1() {
    printf("Task 1: Thread %d is working...\n", omp_get_thread_num());
    // Simulate some work with a loop
    for (int i = 0; i < 100000000; i++);
    printf("Task 1: Thread %d is done\n", omp_get_thread_num());
}

void task2() {
    printf("Task 2: Thread %d is working...\n", omp_get_thread_num());
    // Simulate some work with a loop
    for (int i = 0; i < 100000000; i++);
    printf("Task 2: Thread %d is done\n", omp_get_thread_num());
}

int main() {
    // Set the number of threads to use
    omp_set_num_threads(4);

    // Parallel region
    #pragma omp parallel
    {
        task1();  // Thread will execute task1

        // Barrier to synchronize threads
        #pragma omp barrier

        task2();  // After barrier, all threads will execute task2
    }

    return 0;
}


Output (may vary in order):
Task 1: Thread 0 is working...
Task 1: Thread 1 is working...
Task 1: Thread 2 is working...
Task 1: Thread 3 is working...
Task 1: Thread 3 is done
Task 1: Thread 1 is done
Task 1: Thread 2 is done
Task 1: Thread 0 is done
Task 2: Thread 0 is working...
Task 2: Thread 1 is working...
Task 2: Thread 2 is working...
Task 2: Thread 3 is working...
Task 2: Thread 3 is done
Task 2: Thread 1 is done
Task 2: Thread 2 is done
Task 2: Thread 0 is done



// In this example, the barrier ensures that task1 is completed by all threads before any thread starts task2.
