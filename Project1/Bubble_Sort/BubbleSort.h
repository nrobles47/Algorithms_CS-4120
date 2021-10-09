#pragma once
#include "../Algorithm_Base/Algorithm_Base.h"

/*
	This code was inspired by geeksforgeeks.org/bubble-sort/
*/

class BubbleSort : public Algorithm_Base {
public:
	BubbleSort(std::string algName, unsigned int testSize) : Algorithm_Base(algName, testSize){};
	void Sort(unsigned int[], int);
	void Sort(unsigned int[]);
	void Swap(unsigned int*, unsigned int*);
};