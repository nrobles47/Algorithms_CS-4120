#pragma once
#include <chrono>
#include <string>
#include <iostream>

using namespace std;

class MCM
{
public:
	MCM(std::string algName)
	{
		this->_algName = algName;
		this->SetNumInputLines();
	}

	void SetNumInputLines();

	int GetNumLines()
	{
		return this->_numLines;
	};

	string GetAlgName()
	{
		return this->_algName;
	}

	virtual void RunAlgorithm() {};

	virtual void FileWriter() {};


private:
	int _numLines = 0;
	std::string _algName;
};