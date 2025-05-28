// if Matrix values given:

#include <stdio.h>

#define ROWS 2
#define COLS 3

_global_ void add(int *a, int *b, int *c, int rows, int cols) {
    int idx = threadIdx.x;
    if (idx < rows * cols)
        c[idx] = a[idx] + b[idx];
}

int main() {
    int a[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}};
    int b[ROWS][COLS] = {{6, 5, 4}, {3, 2, 1}};
    int c[ROWS][COLS];

    int size = ROWS * COLS * sizeof(int);

    int *d_a, *d_b, *d_c;
    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);
    cudaMalloc((void**)&d_c, size);

    cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);

    add<<<1, ROWS * COLS>>>(d_a, d_b, d_c, ROWS, COLS);
    cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);

    printf("Result matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }

    cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
    return 0;
}


// if matrix values are not given:
%%writefile hello.cu

#include <stdio.h>
#include <stdlib.h>

#define ROWS 2
#define COLS 3

_global_ void add(int *a, int *b, int *c, int rows, int cols) {
    int idx = threadIdx.x;
    if (idx < rows * cols)
        c[idx] = a[idx] + b[idx];
}

int main() {
    int size = ROWS * COLS * sizeof(int);

    // Allocate host memory using malloc
    int a = (int)malloc(size);
    int b = (int)malloc(size);
    int c = (int)malloc(size);

    // Fill matrices a and b using loops
    for (int i = 0; i < ROWS * COLS; i++) {
        a[i] = i + 1;             // a = [1, 2, 3, 4, 5, 6]
        b[i] = (ROWS * COLS) - i; // b = [6, 5, 4, 3, 2, 1]
    }

    // Allocate device memory
    int *d_a, *d_b, *d_c;
    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);
    cudaMalloc((void**)&d_c, size);

    // Copy from host to device
    cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);

    // Launch kernel
    add<<<1, ROWS * COLS>>>(d_a, d_b, d_c, ROWS, COLS);

    // Copy result back to host
    cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);

    // Print result as 2D matrix
    printf("Result matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%d ", c[i * COLS + j]);
        printf("\n");
    }

    // Free memory
    free(a); free(b); free(c);
    cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);

    return 0;
}