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

    if (rank == 0) {
        cout << "Number of processors: " << num_proc << endl;
    }

    MPI_Barrier(MPI_COMM_WORLD);

    cout << "Processor " << rank << " - Hello World" << endl;

    MPI_Finalize();
}