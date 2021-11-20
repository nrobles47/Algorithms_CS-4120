#pragma once
#include <chrono>
#include <string>
#include <iostream>

using namespace std::chrono;

class Fibonacci
{
public:
	/**
	* Constructor
	*/
	Fibonacci(std::string algName)
	{
		this->_algName = algName;
		this->SetInputArray();
	};

	/**
	* Destructor
	*/
	~Fibonacci()
	{
		this->FileWriter();
	};

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
	void FileWriter();

	/**
	* SetInputArray()
	* Input: Fibonacci_Input.txt
	* Output: N/A
	* Sets index 0 to 6 with the non-negative integers found in the input file.
	*/
	void SetInputArray();

	/**
	* GetInputArray(int i)
	* Input: i is the index of _inputArray
	* Output: returns ith index value
	*/
	int GetInputArray(int i)
	{
		return this->_inputArray[i];
	};

	/**
	* SetOutputArray()
	* Will save the output of the function that ran.
	*/
	void SetOutputArray(int i, size_t n) 
	{
		this->_outputArray[i] = n;
	};
	
	/**
	* SetStartTime(int i) and SetStopTime(int i)
	* Input: i is the index of the _starTime or _stopTime array 
	* Output: N/A
	* These functions will saved the starting and stopping time into the index provided.
	*/
	void SetStartTime(int i);
	void SetStopTime(int i);

	/**
	* RunAlgorithm()
	* Input: N/A
	* Output: Returns the nth number in the Fibonacci sequence
	*/
	virtual void RunAlgorithm()
	{
		std::cout << "\nBase Class Called\n";
	};

private:
	size_t _inputArray[7];
	size_t _outputArray[7];
	std::string _algName;
	std::chrono::time_point<std::chrono::steady_clock> _startTime[7];
	std::chrono::time_point<std::chrono::steady_clock> _stopTime[7];
};