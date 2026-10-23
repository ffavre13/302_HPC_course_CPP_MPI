#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void display_results(string name, double r, double g, double b)
{
    cout << name << "\n";
    cout << "Mean red: " << r << "\n";
    cout << "Mean green: " << g << "\n";
    cout << "Mean blue: " << b << "\n";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    auto start = high_resolution_clock::now();

    string filenames[] = {"Pictures/Black_Hole_RGB.txt", "Pictures/Blue_Whirl_RGB.txt", "Pictures/Brinicle_RGB.txt", "Pictures/Bubble_Simulating_Earth_RGB.txt", "Pictures/Drop_Impact_1_RGB.txt", "Pictures/Drop_Impact_2_RGB.txt", "Pictures/Fire_Tornado_1_RGB.txt", "Pictures/Fire_Tornado_2_RGB.txt", "Pictures/Lighting_Balls_RGB.txt", "Pictures/Magnetosphere_RGB.txt", "Pictures/Mammatus_Clouds_RGB.txt", "Pictures/Plasma_Vortex_RGB.txt", "Pictures/Plateau_Rayleigh_Instability_RGB.txt", "Pictures/Plunging_Breaking_Wave_RGB.txt", "Pictures/Quasar_RGB.txt", "Pictures/Sonoluminescence_RGB.txt", "Pictures/Tornado_RGB.txt"};

    for (string filepath : filenames)
    {
        ifstream file(filepath);

        if (!file.is_open())
        {
            cerr << filepath << ": file not found." << endl;
            continue;
        }

        string line;
        double sumr = 0;
        double sumg = 0;
        double sumb = 0;
        int n = 0;

        char comma;
        double r;
        double g;
        double b;
        
        while (getline(file, line))
        {
            n++;

            stringstream ss(line);

            if (ss >> r >> comma >> g >> comma >> b)
            {
                sumr += r;
                sumg += g;
                sumb += b;
            }
        }

        file.close();

        sumr /= n;
        sumg /= n;
        sumb /= n;

        display_results(filepath, sumr, sumg, sumb);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << duration.count() << endl;

    return 0;
}
