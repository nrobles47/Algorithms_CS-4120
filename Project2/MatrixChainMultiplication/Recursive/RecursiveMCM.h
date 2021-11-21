#pragma once
#include "../MCM.h"
#include <chrono>
#include <string>
#include <iostream>

using namespace std;

class RecursiveMCM : public MCM
{
public:
	RecursiveMCM() : MCM("Recursive MCM") {};

	size_t RMCM(size_t p[], int i, int j, size_t* s[], size_t* m[]);

	void PrintOptParens(size_t* s[], int i, int j, std::ofstream& parenFile);

	void RunAlgorithm();

	void FileWriter(size_t input[], int SIZE, int iteration, size_t output[], std::chrono::time_point<std::chrono::steady_clock> start[], std::chrono::time_point<std::chrono::steady_clock> stop[]);
};


