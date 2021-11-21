#include "MCM.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

void MCM::SetNumInputLines()
{
	std::ifstream inFile;
	inFile.open("MatrixChainMultiplication/MCM_Input.txt");
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