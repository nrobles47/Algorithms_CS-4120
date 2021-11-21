#include "Fibonacci.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

void Fibonacci::SetNumInputLines()
{
	std::ifstream inFile;
	inFile.open("Fibonacci/Fibonacci_Input.txt");
	std::string temp;
	if (inFile.is_open())
	{
		while (getline(inFile, temp))
		{
			this->_numLines++;
		}
	}
	else
	{
		cerr << "Cannot find file!" << endl;
	}
	inFile.close();
}
