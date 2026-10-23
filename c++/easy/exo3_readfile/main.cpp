#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;
int main(int argc, char const *argv[])
{
    auto start = high_resolution_clock::now();

    if (argc < 2 or argc > 2)
    {
        cerr << "Pls run this program with only the filepath of the file: ./run ../exo2_multiplication/multiplication_n.txt" << endl;
        exit(1);
    }

    string filepath = argv[1];

    ifstream file(filepath);

    if (!file.is_open()) {
        cerr << "file not found" << endl;
        exit(1);
    }

    int i = 0;
    string text;
    while (getline(file, text) && i < 15) {
        i++;
        cout << text << "\n";
    }

    file.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << duration.count() << endl;
    
    return 0;
}
