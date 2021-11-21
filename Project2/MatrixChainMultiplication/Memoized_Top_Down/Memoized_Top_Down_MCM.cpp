#include "Memoized_Top_Down_MCM.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

int MemoizedMCM::LookUpChain(size_t* m[], size_t p[], int i, int j, size_t* s[]) {
	if (m[i][j] < INT_MAX)
	{
		return m[i][j];
	}
	if (i == j) 
	{
		m[i][j] = 0;
	}
	else 
	{
		for (int k = i; k <= j - 1; k++)
		{
			int q = LookUpChain(m, p, i, k, s) 
				+ LookUpChain(m, p, k + 1, j, s) 
				+ p[i - 1] * p[k] * p[j];
			if (q < m[i][j]) 
			{
				m[i][j] = q;
				s[i][j] = k;
			}

		}
	}
	return m[i][j];
}

size_t MemoizedMCM::MemMCM(size_t p[], int n, size_t* s[], size_t* m[])
{
	int i;
	for (i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			m[i][j] = INT_MAX;
		}
	}
	return this->LookUpChain(m, p, 1, n, s);
}

void MemoizedMCM::PrintOptParens(size_t* s[], int i, int j, std::ofstream& parenFile)
{
	if (i == j)
	{
		parenFile << "A" << to_string(i);
	}
	else
	{
		parenFile << "(";
		this->PrintOptParens(s, i, s[i][j], parenFile);
		this->PrintOptParens(s, s[i][j] + 1, j, parenFile);
		parenFile << ")";
	}
}

void MemoizedMCM::RunAlgorithm()
{
	size_t* outputArray = new size_t[this->GetNumLines()];
	std::chrono::time_point<std::chrono::steady_clock>* startTime = new std::chrono::time_point<std::chrono::steady_clock>[this->GetNumLines()];
	std::chrono::time_point<std::chrono::steady_clock>* stopTime = new std::chrono::time_point<std::chrono::steady_clock>[this->GetNumLines()];

	std::ifstream inFile;
	inFile.open("MatrixChainMultiplication/MCM_Input.txt");
	std::string temp;

	for (int i = 0; i < this->GetNumLines(); i++)
	{
		if (inFile.is_open())
		{
			getline(inFile, temp);
			stringstream line(temp);

			int x, y, l = 0;
			line >> x;

			size_t* pArray = new size_t[x + 1];
			size_t** m = new size_t * [x + 1];
			size_t** s = new size_t * [x];

			for (int j = 0; j <= x; j++)
			{
				s[j] = new size_t[x];
			}
			for (int k = 0; k <= x + 1; k++)
			{
				m[k] = new size_t[x];
			}

			while (line >> y && l < x + 1)
			{
				pArray[l] = y;
				l++;
			}

			std::ofstream parenFile;
			parenFile.open("MatrixChainMultiplication/MCM_Paren_Output.txt", ios::app);

			startTime[i] = std::chrono::high_resolution_clock::now();
			outputArray[i] = MemMCM(pArray, x, s, m);
			if (parenFile.is_open())
			{
				this->PrintOptParens(s, 1, x, parenFile);
				parenFile << "\n";
			}
			else
			{
				cerr << "Cannot create or find file!" << endl;
			}
			parenFile.close();
			stopTime[i] = std::chrono::high_resolution_clock::now();
			this->FileWriter(pArray, x + 1, i, outputArray, startTime, stopTime);
			delete[] pArray, m, s;
		}
		else
		{
			cerr << "Cannot open or find file!" << endl;
		}
	}
	delete[] outputArray, startTime, stopTime;
}

void MemoizedMCM::FileWriter(size_t input[], int SIZE, int iteration, size_t output[], std::chrono::time_point<std::chrono::steady_clock> start[], std::chrono::time_point<std::chrono::steady_clock> stop[])
{
	std::ofstream outFile;
	outFile.open("MatrixChainMultiplication/MCM_Output.txt", ios::app);
	if (outFile.is_open())
	{
		std::ifstream parenFile;
		std::string parens;
		parenFile.open("MatrixChainMultiplication/MCM_Paren_Output.txt");
		if (parenFile.is_open())
		{
			int iterator = 0;
			while (iterator <= iteration)
			{
				getline(parenFile, parens);
				iterator++;
			}
		}

		std::string temp;

		for (int j = 0; j < SIZE; j++)
		{
			auto x = std::to_string(input[j]);
			temp.append(x);
			if (j != SIZE - 1)
			{
				temp.append(",");
			}
		}

		int setInputW = temp.size() + 10;
		int setOutputW = sizeof(output) + 10;
		int setParensW = parens.size() + 10;

		if (iteration == 0)
		{
			outFile << endl << this->GetAlgName() << endl;
			outFile << left << setw(setInputW) << setfill(' ') << "Input"
				<< left << setw(setOutputW) << setfill(' ') << "Scalar Mults"
				<< left << setw(setParensW) << setfill(' ') << "Optimal Parens"
				<< left << setw(15) << setfill(' ') << "Microseconds"
				<< endl;
		}

		outFile << left << setw(setInputW) << setfill(' ') << temp
			<< left << setw(setOutputW) << setfill(' ') << output[iteration]
			<< left << setw(setParensW) << setfill(' ') << parens
			<< left << setw(15) << setfill(' ')
			<< std::chrono::duration_cast<std::chrono::microseconds>(stop[iteration] - start[iteration]).count()
			<< endl;
		parenFile.close();
	}
	else {
		cerr << "Cannot create or find file!" << endl;
	}
	outFile.close();
}