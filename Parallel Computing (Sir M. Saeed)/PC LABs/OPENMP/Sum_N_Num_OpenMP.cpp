#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int N = 100;
    int sum = 0;

    // Parallel loop with atomic to prevent race conditions
    #pragma omp parallel for shared(sum)
    for (int i = 1; i <= N; i++) {
        #pragma omp atomic
        sum += i;
    }

    cout << "Final sum = " << sum << endl;
    return 0;
}