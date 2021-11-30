#include "Bottom_Up_Fibonacci.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

unsigned long long BottomUpFib::BUF(int n)
{
    unsigned long long* fibArray = new unsigned long long[n + 1];
    fibArray[0] = 0;
    fibArray[1] = 1;

    for (int i = 2; i <= n; i++)
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];

    return fibArray[n];
}

void BottomUpFib::RunAlgorithm()
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
            inputArray[j] = x;
            startTime[j] = std::chrono::high_resolution_clock::now();
            outputArray[j] = this->BUF(inputArray[j]);
            stopTime[j] = std::chrono::high_resolution_clock::now();
            this->FileWriter(j, inputArray, outputArray, startTime, stopTime);
            j++;
        }
        delete[] inputArray, outputArray, startTime, stopTime;
    }
}

void BottomUpFib::FileWriter(int iteration, size_t input[], unsigned long long output[], std::chrono::time_point<std::chrono::steady_clock> start[], std::chrono::time_point<std::chrono::steady_clock> stop[])
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
