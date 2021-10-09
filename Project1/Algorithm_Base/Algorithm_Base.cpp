#include "Algorithm_Base.h"
#include <chrono>

using namespace std::chrono;

bool Algorithm_Base::IncrementComparisons()
{
	this->_comparisons++;
	return true;
}

int* Algorithm_Base::CopyArray(int arr[])
{
	int* copy = new int[this->_testSize];
	for (int i = 0; i < this->_testSize; i++) {
		copy[i] = arr[i];
	}
	return copy;
}

/**
* SetStartTime
* * Saves the time this method was called
**/
void Algorithm_Base::SetStartTime()
{
	this->_startTime = high_resolution_clock::now();
}

/**
* SetStopTime
* * Saves the time this method was called
**/
void Algorithm_Base::SetStopTime()
{
	this->_stopTime = high_resolution_clock::now();
}

