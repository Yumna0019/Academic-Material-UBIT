#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

int main() {
    int n = 1000000;  // Example array size
    std::vector<int> arr(n);
    int sum = 0; // Shared sum variable

    // Initialize the array with random values between 1 and 100
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // Serial sum for baseline comparison
    double start_time = omp_get_wtime();
    int serial_sum = 0;
    for (int i = 0; i < n; ++i) {
        serial_sum += arr[i];
    }
    double end_time = omp_get_wtime();
    std::cout << "Serial Sum: " << serial_sum << std::endl;
    std::cout << "Serial Execution Time: " << end_time - start_time << " seconds." << std::endl;

    // Parallel sum with reduction
    start_time = omp_get_wtime();
    sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    end_time = omp_get_wtime();
    std::cout << "Parallel Sum with Reduction: " << sum << std::endl;
    std::cout << "Parallel Execution Time (Reduction): " << end_time - start_time << " seconds." << std::endl;

    // Parallel sum with atomic
    start_time = omp_get_wtime();
    sum = 0;
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        #pragma omp atomic
        sum += arr[i];
    }
    end_time = omp_get_wtime();
    std::cout << "Parallel Sum with Atomic: " << sum << std::endl;
    std::cout << "Parallel Execution Time (Atomic): " << end_time - start_time << " seconds." << std::endl;

    // Parallel sum with critical section
    start_time = omp_get_wtime();
    sum = 0;
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        #pragma omp critical
        sum += arr[i];  // Only one thread at a time can update 'sum'
    }
    end_time = omp_get_wtime();
    std::cout << "Parallel Sum with Critical: " << sum << std::endl;
    std::cout << "Parallel Execution Time (Critical): " << end_time - start_time << " seconds." << std::endl;

    // Parallel sum with locks
    start_time = omp_get_wtime();
    sum = 0;
    omp_lock_t lock;
    omp_init_lock(&lock);
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        omp_set_lock(&lock);
        sum += arr[i];
        omp_unset_lock(&lock);
    }
    omp_destroy_lock(&lock);
    end_time = omp_get_wtime();
    std::cout << "Parallel Sum with Locks: " << sum << std::endl;
    std::cout << "Parallel Execution Time (Locks): " << end_time - start_time << " seconds." << std::endl;

    // Parallel sum without synchronization (Data Race)
    start_time = omp_get_wtime();
    sum = 0;
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        sum += arr[i];  // No synchronization, potential data race
    }
    end_time = omp_get_wtime();
    std::cout << "Parallel Sum without Synchronization (Data Race): " << sum << std::endl;
    std::cout << "Parallel Execution Time (No Sync): " << end_time - start_time << " seconds." << std::endl;

    return 0;
}