#pragma once
#include "../Fibonacci.h"

using namespace std;

class MTDFibonacci : public Fibonacci
{
public:
	MTDFibonacci() : Fibonacci("Memoized Top Down Fibonacci") {};

	unsigned long long MTDF(int n, unsigned long long cache[]);

	void RunAlgorithm();

	void FileWriter(int iteration, size_t input[], unsigned long long output[], std::chrono::time_point<std::chrono::steady_clock> start[], std::chrono::time_point<std::chrono::steady_clock> stop[]);
};