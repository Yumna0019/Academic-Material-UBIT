// value not given
%%writefile hello.cu

#include <stdio.h>
#include <stdlib.h>

#define ROWS_A 2
#define COLS_A 3
#define ROWS_B 3
#define COLS_B 2

_global_ void multiply(int *a, int *b, int *c, int rowsA, int colsA, int colsB) {
    int row = threadIdx.y;
    int col = threadIdx.x;

    if (row < rowsA && col < colsB) {
        int sum = 0;
        for (int k = 0; k < colsA; k++) {
            sum += a[row * colsA + k] * b[k * colsB + col];
        }
        c[row * colsB + col] = sum;
    }
}

int main() {
    int sizeA = ROWS_A * COLS_A * sizeof(int);
    int sizeB = ROWS_B * COLS_B * sizeof(int);
    int sizeC = ROWS_A * COLS_B * sizeof(int);

    // Allocate host memory
    int a = (int)malloc(sizeA);
    int b = (int)malloc(sizeB);
    int c = (int)malloc(sizeC);

    // Fill matrices A and B
    for (int i = 0; i < ROWS_A * COLS_A; i++) a[i] = i + 1;  // A = [1...6]
    for (int i = 0; i < ROWS_B * COLS_B; i++) b[i] = 1;      // B = all 1s

    // Allocate device memory
    int *d_a, *d_b, *d_c;
    cudaMalloc((void**)&d_a, sizeA);
    cudaMalloc((void**)&d_b, sizeB);
    cudaMalloc((void**)&d_c, sizeC);

    // Copy to device
    cudaMemcpy(d_a, a, sizeA, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, sizeB, cudaMemcpyHostToDevice);

    // Launch kernel with 2D grid of threads
    dim3 threadsPerBlock(COLS_B, ROWS_A);
    multiply<<<1, threadsPerBlock>>>(d_a, d_b, d_c, ROWS_A, COLS_A, COLS_B);

    // Copy result back
    cudaMemcpy(c, d_c, sizeC, cudaMemcpyDeviceToHost);

    // Print result matrix
    printf("Result matrix (C = A x B):\n");
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            printf("%d ", c[i * COLS_B + j]);
        }
        printf("\n");
    }

    // Free memory
    free(a); free(b); free(c);
    cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);

    return 0;
}
