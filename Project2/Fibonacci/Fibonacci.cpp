#include "Fibonacci.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/**
* FileWriter(string algName)
* Input: N/A
* Output: Fibonacci_Output.txt
* Creates a table in the output file:
* * input from Fibonacci_Input.txt
* * Output returned from algorithm ran
* * start time
* * stop time
* * running time
*/
void Fibonacci::FileWriter()
{
	std::ofstream outFile;
	outFile.open("Fibonacci/Fibonacci_Output.txt", ios::app);
	if (outFile.is_open()) 
	{
		for (int i = 0; i < 7; i++) {
			if (i == 0)
			{
				outFile << endl << this->_algName << endl;
				outFile << "Input\t"
					<< "Output\t"
					<< "Nanoseconds" << endl;
			}
			outFile << this->_inputArray[i] << "\t\t"
				<< this->_outputArray[i] << "\t\t"
				<< std::chrono::duration_cast<std::chrono::nanoseconds>(this->_stopTime[i] - this->_startTime[i]).count() << endl;
		}
	}
	else 
	{
		cerr << "Cannot create or find file!" << endl;
	}
	outFile.close();
}

/**
* SetInputArray()
* Input: Fibonacci_Input.txt
* Output: N/A
* Sets index 0 to 6 with the non-negative integers found in the input file.
*/
void Fibonacci::SetInputArray()
{
	std::ifstream inFile;
	inFile.open("Fibonacci/Fibonacci_Input.txt");
	if (inFile.is_open())
	{
		int input = 0;
		int n = 0;
		while (!inFile.eof()) 
		{
			inFile >> input;
			this->_inputArray[n] = input;
			n++;
		}
	}
	else 
	{
		cerr << "Cannot find file!" << endl;
	}
	inFile.close();
}

/**
* SetStartTime
* * Saves the time this method was called
**/
void Fibonacci::SetStartTime(int i)
{
	this->_startTime[i] = high_resolution_clock::now();
}

/**
* SetStopTime
* * Saves the time this method was called
**/
void Fibonacci::SetStopTime(int i)
{
	this->_stopTime[i] = high_resolution_clock::now();
}
