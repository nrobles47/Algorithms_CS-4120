#pragma once
#include "../Fibonacci.h"

using namespace std;

class BottomUpFib : public Fibonacci
{
public:
	BottomUpFib() : Fibonacci("Bottom Up Fibonacci") {};

	/**
	* Bottom Up Fibonacci implementation
	* BUF(int n)
	* INPUT: takes an integer n
	* OUTPUT: returns the nth number from the fibonacci sequence.
	*/
	int BUF(int n);

	/**
	* RunAlgorithm()
	* This method is in charge of the following.
	* * Recording start time of method.
	* * Calling the chosen implementation of the fibonacci sequence.
	* * Storing returned value in the output array.
	* * Recording the time the method stopped.
	*/
	void RunAlgorithm();
};