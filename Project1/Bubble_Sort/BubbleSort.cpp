#include "BubbleSort.h"

void BubbleSort::Sort(int arr[], int n)
{
    int i, j;
    bool isSwapped;
    for (i = 0; i < n - 1; i++)
    {
        isSwapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (this->IncrementComparisons() && arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j + 1]);
                isSwapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break 
        if (isSwapped == false)
            break;
    }
}

void BubbleSort::Sort(int arr[])
{
    this->Sort(arr, this->GetTestSize());
}

void BubbleSort::Swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
