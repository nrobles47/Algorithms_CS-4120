#pragma once
#include "../Fibonacci.h"

using namespace std;

class MTDFibonacci : public Fibonacci
{
public:
	MTDFibonacci() : Fibonacci("Memoized Top Down Fibonacci") {};

	/**
	* RunAlgorithm()
	* Input: N/A
	* Output: Returns the nth number in the Fibonacci sequence
	*/
	void RunAlgorithm();

	/**
	* MTDF(int n, int* cache)
	* Input: receives n from _inputArray and initialized cache
	* Output: nth value from fibonacci sequence
	*/
	int MTDF(int n, int* cache);
};