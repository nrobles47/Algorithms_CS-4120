#include "Randomized_Quick_Sort.h"

/**
* Implementation of the Ranomized Quick Sort
* * Parameters:
*		arr[]<int> : array to be sorted
*		low<int> : starting index
*		high<int> : ending index
**/
void RandomizedQuickSort::Sort(unsigned int arr[], int low, int high)
{
	if (low < high)
	{
		int partIndex = this->RandPartition(arr, low, high);
		this->Sort(arr, low, partIndex - 1);
		this->Sort(arr, partIndex + 1, high);
	}
}

void RandomizedQuickSort::Sort(unsigned int arr[])
{
	this->Sort(arr, 0, this->GetTestSize() - 1);
}

/**
* Partition
* * Takes the last element as the pivot
* * Correctly positions pivot element in the sorted array
* * Places all elements smaller than pivot to the left of the pivot
* * Places all elements greater than pivot to the right of the pivot
**/
int RandomizedQuickSort::Partition(unsigned int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (this->IncrementComparisons() && arr[j] <= pivot)
		{
			i++;
			this->Swap(arr[i], arr[j]);
		}
	}
	this->Swap(arr[i + 1], arr[high]);
	return (i + 1);
}

/**
* RandPartition
* * Generates a random pivot
* * Swaps pivot with end element
* * Calls RandomizedQuickSort::Partition(int arr[], int low, int high)
**/
int RandomizedQuickSort::RandPartition(unsigned int arr[], int low, int high)
{
	// Generate a random number r, where low < r < high
	srand(time(NULL));
	int r = low + rand() % (high - low);
	// Swap random index with the highest index
	this->Swap(arr[r], arr[high]);

	return this->Partition(arr, low, high);
}

void RandomizedQuickSort::Swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}
