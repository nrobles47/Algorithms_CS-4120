#pragma once
#include "../Fibonacci.h"

using namespace std;

class BottomUpFib : public Fibonacci
{
public:
	BottomUpFib() : Fibonacci("Bottom Up Fibonacci") {};

	int BUF(int n);

	void RunAlgorithm();

	void FileWriter(int iteration, size_t input[], size_t output[], std::chrono::time_point<std::chrono::steady_clock> start[], std::chrono::time_point<std::chrono::steady_clock> stop[]);
};