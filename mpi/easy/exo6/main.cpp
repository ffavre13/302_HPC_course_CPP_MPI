#include <mpi.h>
#include <iostream>


using namespace std;

int main()
{
    MPI_Init(NULL, NULL);

    int num_proc;
    MPI_Comm_size(MPI_COMM_WORLD, &num_proc);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int num_elem = 1000000;
    long long* random_arr = nullptr;
    long long max_num = 0;

    srand(rank);
    random_arr = new long long[num_elem]();
    for (long long i = 0; i < num_elem; i++) {
        random_arr[i] = rand();

        if (max_num < random_arr[i]) {
            max_num = random_arr[i];
        }
    }

    cout << "Rank: " << rank << ", maximum is: " << max_num << endl;

    long long* result = nullptr;

    if (rank == 0) {
        result = new long long[num_proc]();
    }

    MPI_Gather(&max_num, 1, MPI_LONG_LONG, result, 1, MPI_LONG_LONG, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        cout << "All max: ";
        for (int i = 0; i < num_proc; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    delete[] result;
    delete[] random_arr;
    MPI_Finalize();
}