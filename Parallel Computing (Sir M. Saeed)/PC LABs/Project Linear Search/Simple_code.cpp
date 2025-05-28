#include <iostream>
using namespace std;

int linearSearch(int A[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (A[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int A[] = {4, 2, 7, 9, 5, 8, 3};
    int n = sizeof(A) / sizeof(A[0]);
    int x = 7;

    int result = linearSearch(A, n, x);
    if (result != -1)
        cout << "Element " << x << " found at index " << result << endl;
    else
        cout << "Element " << x << " not found" << endl;

    return 0;
}
