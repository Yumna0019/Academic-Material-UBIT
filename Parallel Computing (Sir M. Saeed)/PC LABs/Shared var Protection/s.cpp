Here are code examples for shared variable protection in each parallel model:

### 1. **OpenMP (Critical Section and Atomic Operations)**

```c
#include <omp.h>
#include <stdio.h>

int main() {
    int shared_var = 0;

    #pragma omp parallel
    {
        #pragma omp critical
        {
            shared_var++;  // Only one thread will increment at a time
        }

        #pragma omp atomic
        shared_var++;  // Atomic operation for increment
    }

    printf("Shared Variable: %d\n", shared_var);
    return 0;
}
```

### 2. **MPI (Message Passing and Synchronization)**

```c
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int shared_var = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Perform some computation
    shared_var = rank;  // Example: each process sets a value

    // Use MPI_Reduce to get the sum of shared variables
    int total;
    MPI_Reduce(&shared_var, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Total Shared Variable: %d\n", total);
    }

    MPI_Finalize();
    return 0;
}
```

### 3. **CUDA (Atomic Operation and Thread Synchronization)**

```cpp
#include <stdio.h>

_global_ void countThreads(int *result) {
    _shared_ int counter;
    if (threadIdx.x == 0)
        counter = 0;
    __syncthreads();
    atomicAdd(&counter, 1);
    __syncthreads();
    if (threadIdx.x == 0)
        result[blockIdx.x] = counter;
}

int main() {
    int h_result;
    int *d_result;

    cudaMalloc(&d_result, sizeof(int));
    countThreads<<<1, 16>>>(d_result);  // 1 block with 16 threads
    cudaMemcpy(&h_result, d_result, sizeof(int), cudaMemcpyDeviceToHost);

    printf("Total threads counted safely: %d\n", h_result);  // Should print 16

    cudaFree(d_result);
    return 0;
}


### 4. **Multithreading (C++ Mutex Lock)**

```cpp
#include <stdio.h>
#include <pthread.h>

int shared_var = 0;
pthread_mutex_t lock;

void* increment(void* arg) {
    pthread_mutex_lock(&lock);    // Lock the mutex
    shared_var++;                 // Critical section
    pthread_mutex_unlock(&lock);  // Unlock the mutex
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Initialize the mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex init failed\n");
        return 1;
    }

    // Create threads
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Shared Variable: %d\n", shared_var);  // Expected output: 2

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    return 0;
}

```


### Explanation:

* **OpenMP**: `#pragma omp critical` ensures only one thread accesses the critical section, while `#pragma omp atomic` guarantees an atomic increment.
* **MPI**: `MPI_Reduce` is used to gather and sum values across different processes in a safe way.
* **CUDA**: `atomicAdd` ensures that threads in a block safely increment a shared variable.
* **C++ Multithreading**: `std::mutex` is used to protect the shared variable from concurrent access using a lock.

These examples cover basic shared variable protection techniques in each parallel model.

