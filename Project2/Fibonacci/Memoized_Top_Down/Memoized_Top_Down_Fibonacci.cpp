#include "Memoized_Top_Down_Fibonacci.h"
#include <iostream>
#include <map>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

unsigned long long MTDFibonacci::MTDF(int n, unsigned long long cache[])
{
    if (cache[n] == 0)
    {
        if (n <= 1)
        {
            cache[n] = n;
        }
        else
        {
            cache[n] = MTDF(n - 1, cache) + MTDF(n - 2, cache);
        }
    }
    return cache[n];
}

void MTDFibonacci::RunAlgorithm()
{
    std::ifstream inFile;
    inFile.open("Fibonacci/Fibonacci_Input.txt");
    std::string temp;

    for (int i = 0; i < this->GetNumLines(); i++)
    {
        getline(inFile, temp);
        stringstream line(temp);
        size_t* inputArray = new size_t[temp.size()];
        unsigned long long* outputArray = new unsigned long long[temp.size()];
        std::chrono::time_point<std::chrono::steady_clock>* startTime = new std::chrono::time_point<std::chrono::steady_clock>[temp.size()];
        std::chrono::time_point<std::chrono::steady_clock>* stopTime = new std::chrono::time_point<std::chrono::steady_clock>[temp.size()];

        int x, j = 0;
        while (line >> x)
        {
            unsigned long long* cache = new unsigned long long[x+1];
            inputArray[j] = x;
            startTime[j] = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < x+1; i++)
            {
                cache[i] = 0;
            }
            outputArray[j] = this->MTDF(inputArray[j], cache);
            stopTime[j] = std::chrono::high_resolution_clock::now();
            this->FileWriter(j, inputArray, outputArray, startTime, stopTime);
            delete[] cache;
            j++;
        }
        delete[] inputArray, outputArray, startTime, stopTime;
    }
}

void MTDFibonacci::FileWriter(int iteration, size_t input[], unsigned long long output[], std::chrono::time_point<std::chrono::steady_clock> start[], std::chrono::time_point<std::chrono::steady_clock> stop[])
{
    std::ofstream outFile;
    outFile.open("Fibonacci/Fibonacci_Output.txt", ios::app);

    if (outFile.is_open())
    {
        if (iteration == 0)
        {
            outFile << endl << this->GetAlgName() << endl;
            outFile << left << setw(30) << setfill(' ') << "Input"
                << left << setw(30) << setfill(' ') << "Output"
                << left << setw(30) << setfill(' ') << "Nanoseconds"
                << endl;
        }

        outFile << left << setw(30) << setfill(' ') << input[iteration]
            << left << setw(30) << setfill(' ') << output[iteration]
            << left << setw(30) << setfill(' ')
            << std::chrono::duration_cast<std::chrono::nanoseconds>(stop[iteration] - start[iteration]).count()
            << endl;
    }
    else {
        cerr << "Cannot create or find file!" << endl;
    }
    outFile.close();
}