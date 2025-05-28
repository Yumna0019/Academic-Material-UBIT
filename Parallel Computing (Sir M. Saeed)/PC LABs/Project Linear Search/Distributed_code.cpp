#include <mpi.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int A[] = {4, 2, 7, 9, 5, 8, 3};
    int n = sizeof(A) / sizeof(A[0]);
    int target;

    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Only root process asks for input
    if (world_rank == 0) {
        cout << "Enter the number to search: ";
        cin >> target;
    }

    // Broadcast the target to all processes
    MPI_Bcast(&target, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Determine range for this process
    int local_start = world_rank * n / world_size;
    int local_end = (world_rank + 1) * n / world_size;
    int local_result = -1;

    cout << "Process " << world_rank << " searching indices [" 
        << local_start << ", " << local_end - 1 << "]" << endl;

    for (int i = local_start; i < local_end; ++i) {
        if (A[i] == target) {
            local_result = i;
            break;
        }
    }

    if (local_result != -1) {
        cout << "Process " << world_rank << " found the number at index " << local_result << endl;
    }

    // Gather all local results at root
    int global_results[world_size];
    MPI_Gather(&local_result, 1, MPI_INT, global_results, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Root process prints final result
    if (world_rank == 0) {
        int found_index = -1;
        for (int i = 0; i < world_size; ++i) {
            if (global_results[i] != -1) {
                found_index = global_results[i];
                break;
            }
        }

        if (found_index != -1)
            cout << "Final Result: Number found at index: " << found_index << endl;
        else
            cout << "Final Result: Number not found in array." << endl;
    }

    MPI_Finalize();
    return 0;
}