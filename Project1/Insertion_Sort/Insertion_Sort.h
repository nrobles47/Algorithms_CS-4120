#pragma once
#include "../Algorithm_Base/Algorithm_Base.h"

/*
	This code was inspired by https://www.geeksforgeeks.org/insertion-sort/
*/

class InsertionSort : public Algorithm_Base
{
public:
	InsertionSort(std::string algName, unsigned int testSize) : Algorithm_Base(algName, testSize) {};
	void Sort(unsigned int[], int);
	void Sort(unsigned int[]);
};