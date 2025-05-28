#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
#include <time.h>

#define NUM_THREADS 4
#define N 100000000 // Size of the array

// Global array
int array[N];

// Mutex for thread synchronization
pthread_mutex_t mutex_sum = PTHREAD_MUTEX_INITIALIZER;
long long sum_pthread = 0;

// Function to set CPU affinity to core 0 (same core for all threads)
void set_cpu_affinity_same_core() {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);        // Initialize cpuset to be empty
    CPU_SET(0, &cpuset);      // Assign thread to core 0

    pthread_t current_thread = pthread_self();
    if (pthread_setaffinity_np(current_thread, sizeof(cpu_set_t), &cpuset) != 0) {
        perror("pthread_setaffinity_np");
        exit(EXIT_FAILURE);
    }
    printf("Thread %lu is now running on core 0\n", current_thread);
}

// Function to set CPU affinity to different cores (0, 1, 2, ...)
void set_cpu_affinity(int core_id) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(core_id, &cpuset);

    pthread_t current_thread = pthread_self();
    if (pthread_setaffinity_np(current_thread, sizeof(cpu_set_t), &cpuset) != 0) {
        perror("pthread_setaffinity_np");
        exit(EXIT_FAILURE);
    }
    printf("Thread %lu is now running on core %d\n", current_thread, core_id);
}

// Function to simulate work (sum array values)
void* sum_pthread_func(void* arg) {
    int thread_id = *((int*)arg);

    // Bind threads to cores (for same-core or different cores)
    if (thread_id < NUM_THREADS) {
        set_cpu_affinity(thread_id); // Bind thread to different cores (option 2)
    } else {
        set_cpu_affinity_same_core(); // Bind all threads to core 0 (option 1)
    }

    long long local_sum = 0;
    for (int i = thread_id * (N / NUM_THREADS); i < (thread_id + 1) * (N / NUM_THREADS); i++) {
        local_sum += array[i];
    }

    // Locking shared sum
    pthread_mutex_lock(&mutex_sum);
    sum_pthread += local_sum;
    pthread_mutex_unlock(&mutex_sum);

    return NULL;
}

// Function to initialize the array with random values
void init_array() {
    for (int i = 0; i < N; i++) {
        array[i] = rand() % 1000;
    }
}

int main() {
    init_array();

    // Time comparison
    struct timespec start, end;

    // Option 1: Pthreads on Same Core
    printf("\n=== Pthreads on Same Core ===\n");
    clock_gettime(CLOCK_REALTIME, &start);
    pthread_t threads_same_core[NUM_THREADS];
    int thread_ids_same_core[NUM_THREADS] = {0, 0, 0, 0};

    // Create threads and bind all to core 0
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads_same_core[i], NULL, sum_pthread_func, (void*)&thread_ids_same_core[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads_same_core[i], NULL);
    }
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Pthread sum (same core): %lld\n", sum_pthread);
    printf("Pthread (same core) execution time: %lf seconds\n", 
           (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9);

    // Reset the sum for the next experiment
    sum_pthread = 0;

    // Option 2: Pthreads on Different Cores
    printf("\n=== Pthreads on Different Cores ===\n");
    clock_gettime(CLOCK_REALTIME, &start);
    pthread_t threads_different_cores[NUM_THREADS];
    int thread_ids_different_cores[NUM_THREADS] = {0, 1, 2, 3};

    // Create threads and assign them to different cores
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads_different_cores[i], NULL, sum_pthread_func, (void*)&thread_ids_different_cores[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads_different_cores[i], NULL);
    }
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Pthread sum (different cores): %lld\n", sum_pthread);
    printf("Pthread (different cores) execution time: %lf seconds\n", 
           (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9);

    // Reset the sum for the next experiment
    sum_pthread = 0;

    // Option 3: OpenMP Parallel Execution
    printf("\n=== OpenMP Parallel Execution ===\n");
    clock_gettime(CLOCK_REALTIME, &start);
    long long sum_openmp = 0;

    // Parallelize the summing of the array using OpenMP
    #pragma omp parallel for reduction(+:sum_openmp)
    for (int i = 0; i < N; i++) {
        sum_openmp += array[i];
    }
    clock_gettime(CLOCK_REALTIME, &end);
    printf("OpenMP sum: %lld\n", sum_openmp);
    printf("OpenMP execution time: %lf seconds\n", 
           (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9);

    return 0;
}

