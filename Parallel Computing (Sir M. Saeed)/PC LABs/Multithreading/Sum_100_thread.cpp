#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;
int totalSum = 0;

void sumRange(int start, int end, int threadId) {
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += i;
    }

    lock_guard<mutex> lock(mtx);
    cout << "Thread " << threadId << " summing from " << start << " to " << end << ": " << sum << endl;
    totalSum += sum;
}

int main() {
    const int numThreads = 10;
    int rangeSize = 100 / numThreads;

    if (rangeSize > 1) {
        // Create 10 threads
        for (int i = 0; i < numThreads; ++i) {
            int start, end;
            start = i * rangeSize + 1;
            if (i == numThreads - 1) {
                end = 100; // Last thread goes up to 100
            } else {
                end = start + rangeSize - 1; // Other threads end at their assigned range
            }

            thread th(sumRange, start, end, i + 1);
            th.join(); // Join immediately (sequential execution)
        }

        cout << "Total Sum from 1 to 100 using 10 threads: " << totalSum << endl;
    } else {
        cout << "total threads: 1, no multiple threads." << endl;
    }

    return 0;
}