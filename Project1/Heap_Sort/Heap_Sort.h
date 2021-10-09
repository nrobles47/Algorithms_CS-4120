#pragma once
#include "../Algorithm_Base/Algorithm_Base.h"
#include <cstdlib> 

/*
	This code was inspired by Project 5 from CS 3350
*/

class HeapSort : public Algorithm_Base
{
public:
	HeapSort(std::string algName, int testSize) : Algorithm_Base(algName, testSize) {};
	void Sort(int[], size_t);
	void Sort(int[]);
	void Swap(int, int);
	size_t Parent(size_t);
	size_t LChild(size_t);
	size_t RChild(size_t);
	void MakeHeap(int[], size_t);
	void ReheapifyDown(int[], size_t);
};