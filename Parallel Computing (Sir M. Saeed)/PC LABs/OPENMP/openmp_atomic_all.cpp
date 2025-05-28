// Parallel sum with reduction
#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("Sum (reduction): %d\n", sum);
    return 0;
}



// with time :omp_get_wtime() =>end_time - start_time           (Parallel sum with reduction)
#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0; 
    double start_time, end_time;                                                // <=

    start_time = omp_get_wtime();                                               // <=

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }

    end_time = omp_get_wtime();                                                 // <=

    printf("Sum (reduction): %d\n", sum);
    printf("Execution Time: %.6f seconds\n", end_time - start_time);            // <=

    return 0;
}



// parallel sum with atomic
#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;
    #pragma omp parallel for
    for (int i = 1; i <= 100; i++) {
        #pragma omp atomic
        sum += i;
    }
    printf("Sum (atomic): %d\n", sum);
    return 0;
}



// parallel sum with critical
#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;
    #pragma omp parallel for
    for (int i = 1; i <= 100; i++) {
        #pragma omp critical
        sum += i;
    }
    printf("Sum (atomic): %d\n", sum);
    return 0;
}


// with locks
#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;
    omp_lock_t lock;
    omp_init_lock(&lock);

    #pragma omp parallel for
    for (int i = 1; i <= 100; i++) {
        omp_set_lock(&lock);
        sum += i;
        omp_unset_lock(&lock);
    }

    omp_destroy_lock(&lock);
    printf("Sum (lock): %d\n", sum);
    return 0;
}




// parallel sum without synchronization
#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;
    #pragma omp parallel for
    for (int i = 1; i <= 100; i++) {
        sum += i;  // ❌ Data race likely
    }
    printf("Sum (no sync): %d\n", sum);
    return 0;
}