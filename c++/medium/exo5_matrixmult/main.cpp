#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

void display_matrix(vector<int> m, int size)
{
    for (int i = 0; i < size * size; i++)
    {
        cout << m.at(i) << " ";

        if ((i + 1) % size == 0)
        {
            cout << endl;
        }
    }

    cout << endl;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cerr << "Pls specify the size of the vectors" << endl;
        exit(1);
    }

    int size = stoi(argv[1]);

    if (size < 1)
    {
        cerr << "pls sepcify a valid size (> 1)" << endl;
        exit(1);
    }

    vector<int> m1(size * size);
    vector<int> m2(size * size);
    vector<int> mres(size * size);

    for (int i = 0; i < size * size; i++)
    {
        m1.at(i) = rand() % 10;
        m2.at(i) = rand() % 10;
    }

    auto start = high_resolution_clock::now();
    int j = 0;

    for (int i = 0; i < size * size; i++)
    {
        int tmpres = 0;

        for (int z = 0; z < size; z++)
        {
            tmpres += m1.at(j * size + z) * m2.at(z * size + i % size);
        }

        mres.at(i) = tmpres;

        if ((i + 1) % size == 0)
        {
            j += 1;
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    // cout << endl;
    // display_matrix(mres, size);

    cout << duration.count() << endl;

    return 0;
}