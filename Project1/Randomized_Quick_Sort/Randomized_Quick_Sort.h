#pragma once
#include "../Algorithm_Base/Algorithm_Base.h"
/*
	This code was inspired by https://www.geeksforgeeks.org/quicksort-using-random-pivoting/
	
	In order to get this class to sort the descending array:
		Right click on Project
		Click Properties
		Follow path: PROJECT->Properties->Configuration Properties->Linker->System->Stack Reserve Size=4194304
		Set Stack Reserve Size = 4194304
*/

class RandomizedQuickSort : public Algorithm_Base
{
public:
	RandomizedQuickSort(std::string algName, int testSize) : Algorithm_Base(algName, testSize) {};
	void Sort(int[], int, int);
	void Sort(int[]);
	void Swap(int, int);
	int Partition(int[], int, int);
	int RandPartition(int[], int, int);
};