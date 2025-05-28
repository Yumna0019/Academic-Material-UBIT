#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

long *balance; // Shared memory among multiple processes

// Credit function
void credit(int arg) {
    int amount = arg;
    printf("Credit: balance = balance + %d\n", arg);
    for (long i = 0; i < 5000000; i++) {
        *balance = *balance + amount;
    }
}

// Debit function
void debit(int arg) {
    int amount = arg;
    printf("Debit: balance = balance - %d\n", arg);
    for (long i = 0; i < 5000000; i++) {
        *balance = *balance - amount;
    }
}

int main() {
    // IPC - Shared Memory technique is used to store variable balance
    key_t key = ftok("sm_bal", 65);
    int shm_id = shmget(key, 8, IPC_CREAT | 0666);
    balance = (long*)shmat(shm_id, NULL, 0);
    *balance = 0;  // initializing balance

    int cpid = fork();
    if (cpid == 0) {
        credit(1);
        shmdt(balance);
        exit(0);
    } else {
        debit(1);
        waitpid(cpid, NULL, 0);
        // debit(1); // optional second debit
        printf("Value of balance is: %ld\n", *balance);
        shmdt(balance);
        shmctl(shm_id, IPC_RMID, NULL);
        return 0;
    }
}
