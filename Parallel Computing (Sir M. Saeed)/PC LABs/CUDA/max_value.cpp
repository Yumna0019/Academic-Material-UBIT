%%writefile hello.cu
// MAX
#include <stdio.h>
#include <stdlib.h>

_global_ void findMax(int *a, int *max) {
    int i = threadIdx.x;
    atomicMax(max, a[i]); // atomic operation ensures no conflicts   
}

int main() {
    int N = 5;
    int a = (int)malloc(N * sizeof(int));  // host memory allocation
    int *d_a, *d_max;
    int result = 0;

    // Fill array with values
    a[0] = 10;
    a[1] = 22;
    a[2] = 50;
    a[3] = 17;
    a[4] = 30;

    // Device memory allocation
    cudaMalloc((void**)&d_a, N * sizeof(int));
    cudaMalloc((void**)&d_max, sizeof(int));

    // Copy data to device
    cudaMemcpy(d_a, a, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_max, &result, sizeof(int), cudaMemcpyHostToDevice);

    // Launch kernel
    findMax<<<1, N>>>(d_a, d_max);

    // Copy result back to host
    cudaMemcpy(&result, d_max, sizeof(int), cudaMemcpyDeviceToHost);

    printf("Max = %d\n", result);

    // Free memory
    free(a);
    cudaFree(d_a);
    cudaFree(d_max);

    return 0;
}




// MIN
%%writefile hello.cu

#include <stdio.h>
#include <stdlib.h>

__global__ void findMin(int *a, int *min) {
    int i = threadIdx.x;
    atomicMin(min, a[i]); // atomic operation to safely update the minimum
}

int main() {
    int N = 5;
    int *a = (int*)malloc(N * sizeof(int));  // host memory allocation
    int *d_a, *d_min;
    int result = INT_MAX; // Initialize with max int value

    // Fill array with values
    a[0] = 10;
    a[1] = 22;
    a[2] = 50;
    a[3] = 17;
    a[4] = 30;

    // Device memory allocation
    cudaMalloc((void**)&d_a, N * sizeof(int));
    cudaMalloc((void**)&d_min, sizeof(int));

    // Copy data to device
    cudaMemcpy(d_a, a, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_min, &result, sizeof(int), cudaMemcpyHostToDevice);

    // Launch kernel
    findMin<<<1, N>>>(d_a, d_min);

    // Copy result back to host
    cudaMemcpy(&result, d_min, sizeof(int), cudaMemcpyDeviceToHost);

    printf("Min = %d\n", result);

    // Free memory
    free(a);
    cudaFree(d_a);
    cudaFree(d_min);

    return 0;
}
