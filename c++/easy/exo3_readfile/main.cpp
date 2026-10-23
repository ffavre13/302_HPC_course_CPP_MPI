#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char const *argv[])
{
    if (argc < 2 or argc > 2)
    {
        cerr << "Pls run this program with only the filepath of the file: ./run ../exo2_multiplication/multiplication_n.txt" << endl;
        return 1;
    }

    string filepath = argv[1];

    ifstream file(filepath);

    if (!file.is_open()) {
        cerr << "file not found" << endl;
        return 1;
    }

    int i = 0;
    string text;
    while (getline(file, text) && i < 15) {
        i++;
        cout << text << "\n";
    }
    
    return 0;
}
