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

    int num_elem = 10;
    long* random_arr = nullptr ;

    if (rank == 0) {
        random_arr = new long[num_elem*num_proc]();

        long real_sum = 0;
        for (int i = 0; i < num_elem*num_proc; i++) {
            random_arr[i] = rand() % 100;
            real_sum += random_arr[i];
        }

        cout << "Real sum: " << real_sum << endl;
    }

    long* sub_random_arr = new long[num_elem];
    MPI_Scatter(random_arr, num_elem, MPI_LONG, sub_random_arr, num_elem, MPI_LONG, 0, MPI_COMM_WORLD);

    long tmp_sum = 0;
    for (int i = 0; i < num_elem; i++) {
        tmp_sum += sub_random_arr[i];
    }


    long global_sum;
    MPI_Reduce(&tmp_sum, &global_sum, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        cout << "Calculated sum: " << global_sum << endl;
        delete[] random_arr;
    }

    delete[] sub_random_arr;
    MPI_Finalize();
}