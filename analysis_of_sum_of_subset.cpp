#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <fstream>

using namespace std::chrono;
using namespace std;
double avgtime = 0.0;
double timegap = 0.0;

int main()
{

    ofstream fout;
    fout.open("sumofsubset.csv", ios::out | ios::app);
    int n;
    for (int n = 500; n <= 5000; n += 500)
    {
        int arr[n];
        srand(unsigned(time(0)));
        for (int i = 0; i < 10000; i++)
        {
            for (int i = 0; i < n; i++)
            {
                arr[i] = rand() % (n) + 1;
            }

            auto start = chrono::high_resolution_clock::now();
            // call function here
            auto end = chrono::high_resolution_clock::now();
            timegap = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            timegap = timegap * 1e-9;
            avgtime = avgtime + timegap;
            fout << n << "," << timegap << endl;
        }
        std::cout << "Average time(" << n << ")"
                  << "," << fixed << avgtime / 10000 << endl;
    }
}
