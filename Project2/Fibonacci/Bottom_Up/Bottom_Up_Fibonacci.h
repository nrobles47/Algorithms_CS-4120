#pragma once
#include "../Fibonacci.h"

using namespace std;

class BottomUpFib : public Fibonacci
{
public:
	BottomUpFib() : Fibonacci("Bottom Up Fibonacci") {};

	unsigned long long BUF(int n);

	void RunAlgorithm();

	void FileWriter(int iteration, size_t input[], unsigned long long output[], std::chrono::time_point<std::chrono::steady_clock> start[], std::chrono::time_point<std::chrono::steady_clock> stop[]);
};