#include "Bottom_Up_Fibonacci.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

int BottomUpFib::BUF(int n)
{
    size_t* fibArray = new size_t[n + 1];
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
        size_t* outputArray = new size_t[temp.size()];
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

void BottomUpFib::FileWriter(int iteration, size_t input[], size_t output[], std::chrono::time_point<std::chrono::steady_clock> start[], std::chrono::time_point<std::chrono::steady_clock> stop[])
{
    std::ofstream outFile;
    outFile.open("Fibonacci/Fibonacci_Output.txt", ios::app);

    if (outFile.is_open())
    {
        if (iteration == 0)
        {
            outFile << endl << this->GetAlgName() << endl;
            outFile << left << setw(10) << setfill(' ') << "Input"
                << left << setw(10) << setfill(' ') << "Output"
                << left << setw(10) << setfill(' ') << "Microseconds"
                << endl;
        }

        outFile << left << setw(10) << setfill(' ') << input[iteration]
            << left << setw(10) << setfill(' ') << output[iteration]
            << left << setw(15) << setfill(' ')
            << std::chrono::duration_cast<std::chrono::microseconds>(stop[iteration] - start[iteration]).count()
            << endl;
    }
    else {
        cerr << "Cannot create or find file!" << endl;
    }
    outFile.close();
}
