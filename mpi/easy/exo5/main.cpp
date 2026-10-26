#include <mpi.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    MPI_Init(NULL, NULL);

    int num_proc;
    MPI_Comm_size(MPI_COMM_WORLD, &num_proc);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    const int max_length = 1024;
    char text[max_length];

    if (rank == 0) {
        string filepath = "data.txt";
        ifstream file(filepath);
        
        if (!file.is_open()) {
            cerr << "file not found" << endl;
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        file.getline(text, max_length);
        file.close();
    }
    

    MPI_Bcast(&text, max_length, MPI_CHAR, 0, MPI_COMM_WORLD);

    cout << "Processor " << rank << " received: " << text << endl;

    MPI_Finalize();
}