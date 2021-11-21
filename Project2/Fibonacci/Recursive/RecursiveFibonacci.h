#pragma once
#include "../Fibonacci.h"

using namespace std;

class RecursiveFibonacci : public Fibonacci
{
public:
	RecursiveFibonacci() : Fibonacci("Recursive Fibonacci") {};

	int RecFib(int n);

	void RunAlgorithm();

	void FileWriter(int iteration, size_t input[], size_t output[], std::chrono::time_point<std::chrono::steady_clock> start[], std::chrono::time_point<std::chrono::steady_clock> stop[]);
};