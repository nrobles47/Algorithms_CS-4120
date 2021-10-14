#include "MergeSort.h"

void MergeSort::Sort(unsigned int arr[], int n)
{
    if (n == 0)
        return;

    unsigned int* dupArray = new unsigned int[n];

    for (int i = 0; i < n; i++)
        dupArray[i] = arr[i];

    this->MergeSort3Way(dupArray, 0, n, arr);

    for (int i = 0; i < n; i++)
        arr[i] = dupArray[i];
}

void MergeSort::Sort(unsigned int arr[])
{
    this->Sort(arr, this->GetTestSize());
}

void MergeSort::MergeSort3Way(unsigned int arr[], int low, int high, unsigned int destArr[])
{
    if (high - low < 2)
        return;

    // Splitting array into 3 parts 
    int mid1 = low + ((high - low) / 3);
    int mid2 = low + 2 * ((high - low) / 3) + 1;

    // Sorting 3 arrays recursively 
    this->MergeSort3Way(destArr, low, mid1, arr);
    this->MergeSort3Way(destArr, mid1, mid2, arr);
    this->MergeSort3Way(destArr, mid2, high, arr);

    // Merging the sorted arrays 
    this->Merge(destArr, low, mid1, mid2, high, arr);
}

void MergeSort::Merge(unsigned int arr[], int low, int mid1, int mid2, int high, unsigned int destArr[])
{
    int i = low, j = mid1, k = mid2, l = low;

    // choose smaller of the smallest in the three ranges 
    while ((i < mid1) && (j < mid2) && (k < high))
    {
        if (this->IncrementComparisons() && arr[i] < arr[j])
        {
            if (this->IncrementComparisons() &&  arr[i] < arr[k])
            {
                destArr[l++] = arr[i++];
            }
            else
            {
                destArr[l++] = arr[k++];
            }
        }
        else
        {
            if (this->IncrementComparisons() && arr[j] < arr[k])
            {
                destArr[l++] = arr[j++];
            }
            else
            {
                destArr[l++] = arr[k++];
            }
        }
    }

    // case where first and second ranges
    // have remaining values 
    while ((i < mid1) && (j < mid2))
    {
        if (this->IncrementComparisons() && arr[i] < arr[j])
        {
            destArr[l++] = arr[i++];
        }
        else
        {
            destArr[l++] = arr[j++];
        }
    }

    // case where second and third ranges
    // have remaining values 
    while ((j < mid2) && (k < high))
    {
        if (this->IncrementComparisons() && arr[j] < arr[k])
        {
            destArr[l++] = arr[j++];
        }
        else
        {
            destArr[l++] = arr[k++];
        }
    }

    // case where first and third ranges have 
    // remaining values 
    while ((i < mid1) && (k < high))
    {
        if (this->IncrementComparisons() && arr[i] < arr[k])
        {
            destArr[l++] = arr[i++];
        }
        else
        {
            destArr[l++] = arr[k++];
        }
    }

    // copy remaining values from the first range 
    while (i < mid1)
        destArr[l++] = arr[i++];

    // copy remaining values from the second range 
    while (j < mid2)
        destArr[l++] = arr[j++];

    // copy remaining values from the third range 
    while (k < high)
        destArr[l++] = arr[k++];
}
