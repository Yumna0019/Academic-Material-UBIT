#include <iostream>
#include <omp.h>
using namespace std;

int parallelLinearSearch(int A[], int n, int x) {
    int index = -1;

    #pragma omp parallel for shared(index)
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            #pragma omp critical
            {
                if (index == -1 || i < index)
                    index = i;
            }
        }
    }
    return index;
}

int main() {
    int A[] = {4, 2, 7, 9, 5, 7, 3};
    int n = sizeof(A) / sizeof(A[0]);
    int x = 7;

    int result = parallelLinearSearch(A, n, x);
    if (result != -1)
        cout << "Element " << x << " found at index " << result << endl;
    else
        cout << "Element " << x << " not found" << endl;

    return 0;
}
