#pragma once
#include "../Algorithm_Base/Algorithm_Base.h"

/*
	This code was inspired by https://www.geeksforgeeks.org/3-way-merge-sort/
*/

class MergeSort : public Algorithm_Base
{
public:
	MergeSort(std::string algName, int testSize) : Algorithm_Base(algName, testSize) {};
	void Sort(int[], int);
	void Sort(int[]);
	void MergeSort3Way(int[], int, int, int[]);
	void Merge(int[], int, int, int, int, int[]);
};