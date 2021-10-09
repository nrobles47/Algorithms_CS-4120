#include "Heap_Sort.h"
#include <algorithm>
#include <cstdlib> 

void HeapSort::Sort(int arr[], size_t n)
{
    size_t unsorted;

    this->MakeHeap(arr, n);

    unsorted = n;

    while (unsorted > 1)
    {
        --unsorted;
        this->Swap(arr[0], arr[unsorted]);
        this->ReheapifyDown(arr, unsorted);
    }
}

void HeapSort::Sort(int arr[])
{
    size_t n = this->GetTestSize();
    this->Sort(arr, n);
}

size_t HeapSort::Parent(size_t k)
{
    return (k - 1) / 2;
}

size_t HeapSort::LChild(size_t k)
{
    return 2 * k + 1;
}

size_t HeapSort::RChild(size_t k)
{
    return 2 * k + 2;
}

void HeapSort::MakeHeap(int arr[], size_t n)
{
    size_t i;  // Index of next element to be added to heap
    size_t k;  // Index of new element as it is being pushed upward through the heap

    for (i = 1; i < n; ++i)
    {
        k = i;
        while ((k > 0) && (arr[k] > arr[this->Parent(k)]))
        {
            this->IncrementComparisons();
            this->Swap(arr[k], arr[this->Parent(k)]);
            k = this->Parent(k);
        }
    }
}

void HeapSort::ReheapifyDown(int arr[], size_t n)
{
    size_t current;          // Index of the node that's moving down
    size_t big_child_index;  // Index of the larger child of the node that's moving down
    bool heap_ok = false;    // Will change to true when the heap becomes correct

    current = 0;

    // Note: The loop keeps going while the heap is not okay, and while the current node has
    // at least a left child. The test to see whether the current node has a left child is
    // left_child(current) < n.
    while ((!heap_ok) && (this->LChild(current) < n))
    {
        // Compute the index of the larger child:
        if (this->RChild(current) >= n) {
            // There is no right child, so left child must be largest
            big_child_index = this->LChild(current);
        }
        else if (arr[this->LChild(current)] > arr[this->RChild(current)]) {
            // The left child is the bigger of the two children
            big_child_index = this->LChild(current);
            this->IncrementComparisons();
        }
        else {
            // The right child is the bigger of the two children
            big_child_index = this->RChild(current);
            this->IncrementComparisons();
        }

        // Check whether the larger child is bigger than the current node. If so, then swap
        // the current node with its bigger child and continue; otherwise we are finished.
        if (arr[current] < arr[big_child_index])
        {
            this->IncrementComparisons();
            this->Swap(arr[current], arr[big_child_index]);
            current = big_child_index;
        }
        else
            heap_ok = true;
    }
}

void HeapSort::Swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}