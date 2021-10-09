#pragma once
#include "../Algorithm_Base/Algorithm_Base.h"

/*
	This code was inspired by geeksforgeeks.org/bubble-sort/
*/

class BubbleSort : public Algorithm_Base {
public:
	BubbleSort(std::string algName, int testSize) : Algorithm_Base(algName, testSize){};
	void Sort(int[], int);
	void Sort(int[]);
	void Swap(int*, int*);
};