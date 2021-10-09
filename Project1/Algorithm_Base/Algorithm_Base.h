#pragma once
#include <chrono>
#include <string>
#include <iostream>

using namespace std::chrono;

class Algorithm_Base {
public:
	/**
	* Constructor
	* * Accepts algName<string> so program knows that algorithm it is running
	* * Sets comparisons<int> to 0
	**/
	Algorithm_Base(std::string algName, int testSize) 
	{ 
		this->_testSize = testSize;
		this->_comparisons = 0;
		this->_algName = algName;
	};
	/**
	* Destructor
	* * Prints execution time and number of comparisons
	**/
	~Algorithm_Base()
	{
		auto duration = duration_cast<microseconds>(this->_stopTime - this->_startTime);
		std::cout << "\n" << this->_algName 
			<< " sorted an array of size: " << this->_testSize 
			<< "\n\tTotal Comparisons: " << this->_comparisons
			<< "\n\tTotal Execution Time (in microseconds): " <<
			duration.count() << std::endl;
	}
	virtual void Sort()
	{
		std::cout << "\nBase Class Called\n";
	};
	bool IncrementComparisons();
	auto GetTestSize()
	{
		return this->_testSize;
	};
	int* CopyArray(int[]);
	/**
	* SetStartTime and SetStopTime
	* * These two methods save the current time the method was called
	* * One designated for the time the sort function is starts, and one for when it ends
	* * The two private fields will be used to calculate the exuction time and print with the destructor
	**/
	void SetStartTime();
	void SetStopTime();
private:
	std::string _algName; // Name of algorithm currently running
	int _comparisons; // Counter for comparisons
	int _testSize; // Size of array we are sorting
	std::chrono::time_point<std::chrono::steady_clock> _startTime;
	std::chrono::time_point<std::chrono::steady_clock> _stopTime;
};