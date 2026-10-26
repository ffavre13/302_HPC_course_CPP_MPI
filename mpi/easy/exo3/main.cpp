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

    int token;

    if (rank == 0) {
        cout << "Number of processors: " << num_proc << endl;
        cout << "Processor " << rank << " - Hello World" << endl;
        token = 1;

        if (num_proc > 1) {
            MPI_Send(&token, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
        }
    }
    else {
        MPI_Recv(&token, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Processor " << rank << " - Hello World" << endl;

        if (num_proc > rank + 1) {
            MPI_Send(&token, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
        }
    }


    MPI_Finalize();
}