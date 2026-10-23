#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int main()
{
    int num;
    cin >> num;
    auto start = high_resolution_clock::now();

    ofstream file("multiplication_" + to_string(num) + ".txt");

    for (int i = 0; i < 100000; i++)
    {
        // file << i * num << endl;
        file << i * num << "\n";
    }

    file.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << duration.count() << endl;

    return 0;
}