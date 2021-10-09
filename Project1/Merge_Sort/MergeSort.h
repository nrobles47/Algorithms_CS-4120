#pragma once
#include "../Algorithm_Base/Algorithm_Base.h"

/*
	This code was inspired by https://www.geeksforgeeks.org/3-way-merge-sort/
*/

class MergeSort : public Algorithm_Base
{
public:
	MergeSort(std::string algName, unsigned int testSize) : Algorithm_Base(algName, testSize) {};
	void Sort(unsigned int[], int);
	void Sort(unsigned int[]);
	void MergeSort3Way(unsigned int[], int, int, unsigned int[]);
	void Merge(unsigned int[], int, int, int, int, unsigned int[]);
};