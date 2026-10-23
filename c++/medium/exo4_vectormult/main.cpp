#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

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

    vector<int> v1(size);
    vector<int> v2(size);

    for (int i = 0; i < size; ++i)
    {
        v1.at(i) = rand();
        v2.at(i) = rand();
    }

    auto start = high_resolution_clock::now();
    int result = 0;

    for (int i = 0; i < size; ++i)
    {
        result += v1.at(i) * v2.at(i);
    }

    cout << "Result: " << result << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << duration.count() << endl;

    return 0;
}