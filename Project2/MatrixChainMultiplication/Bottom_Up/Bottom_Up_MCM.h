#pragma once
#include "../MCM.h"
#include <chrono>
#include <string>
#include <iostream>

using namespace std;

class BottomUpMCM : public MCM
{
public:
	BottomUpMCM() : MCM("Bottom Up MCM") {};

	size_t BUMCM(size_t p[], int i, size_t* s[], size_t* m[]);

	void PrintOptParens(size_t* s[], int i, int j, std::ofstream& parenFile);

	void RunAlgorithm();

	void FileWriter(size_t input[], int SIZE, int iteration, size_t output[], std::chrono::time_point<std::chrono::steady_clock> start[], std::chrono::time_point<std::chrono::steady_clock> stop[]);
};

