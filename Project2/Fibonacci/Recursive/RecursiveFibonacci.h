#pragma once
#include "../Fibonacci.h"

using namespace std;

class RecursiveFibonacci : public Fibonacci 
{
public:
	RecursiveFibonacci() : Fibonacci("Recursive Fibonacci") {};

	/**
	* RunAlgorithm()
	* This method is in charge of the following.
	* * Recording start time of method.
	* * Calling the chosen implementation of the fibonacci sequence.
	* * Storing returned value in the output array.
	* * Recording the time the method stopped.
	*/
	void RunAlgorithm();

	/**
	* Recursive Fibonacci implementation
	* RecFib(int n)
	* INPUT: takes an integer n
	* OOUTPUT: returns the nth value from the  fibonacci sequence
	*/
	int RecFib(int n);
};