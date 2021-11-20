#pragma once
#include "../Fibonacci.h"

using namespace std;

class MTDFibonacci : public Fibonacci
{
public:
	MTDFibonacci() : Fibonacci("Memoized Top Down Fibonacci") {};

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
	* Top Down Fibonacci Implementation with Memoization
	* MTDF(int n, int* cache)
	* INPUT: takes an integer n
	* OUTPUT: returns the nth number from the fibonacci sequence.
	*/
	int MTDF(int n);
};