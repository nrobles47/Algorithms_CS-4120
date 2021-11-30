#pragma once
#include "../Fibonacci.h"

using namespace std;

class RecursiveFibonacci : public Fibonacci
{
public:
	RecursiveFibonacci() : Fibonacci("Recursive Fibonacci") {};

	unsigned long long RecFib(unsigned long long n);

	void RunAlgorithm();

	void FileWriter(int iteration, size_t input[], unsigned long long output[], std::chrono::time_point<std::chrono::steady_clock> start[], std::chrono::time_point<std::chrono::steady_clock> stop[]);
};