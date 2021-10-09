#include "Insertion_Sort.h"

void InsertionSort::Sort(unsigned int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (this->IncrementComparisons() && j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void InsertionSort::Sort(unsigned int arr[])
{
	this->Sort(arr, this->GetTestSize());
}
