#pragma once
#include "../Fibonacci.h"
#include <chrono>

using namespace std::chrono;

class RecursiveFibonacci : public Fibonacci 
{
public:
	RecursiveFibonacci() : Fibonacci("Recursive Fibonacci") {};

	/**
	* RunAlgorithm()
	* Input: N/A
	* Output: Returns the nth number in the Fibonacci sequence
	*/
	void RunAlgorithm();

	/**
	* RecFib(int n)
	* Input: receives n from _inputArray
	* Output: nth value from fibonacci sequence
	*/
	int RecFib(int n);
};