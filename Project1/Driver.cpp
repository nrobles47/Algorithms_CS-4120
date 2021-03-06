#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "Driver_Functions/Driver_Functions.h"
#include "Bubble_Sort/BubbleSort.h"
#include "Insertion_Sort/Insertion_Sort.h"
#include "Randomized_Quick_Sort/Randomized_Quick_Sort.h"
#include "Heap_Sort/Heap_Sort.h"
#include "Merge_Sort/MergeSort.h"
#include "Driver.h"

using namespace std;

const unsigned int TEST_SIZE = 8000;

/**
* ExecuteSort
* * Parameters:
*		algName<string> : Name of the algorithm function is running
*		testSize<int> : Size of array we wish to sort
*		makeCopy<int*> : Array we wish to make a copy of and sort
**/
template<class T>
void ExecuteSort(string algName, unsigned int testSize, unsigned int makeCopy[]) 
{
	// Instantiate sort object
	T* algorithm = new T(algName, testSize);
	// Make copy of array we wish to sort
	unsigned int* testCopy = algorithm->CopyArray(makeCopy);
	// Start timer
	algorithm->SetStartTime();
	// Sort testCopy
	algorithm->Sort(testCopy);
	// End timer
	algorithm->SetStopTime();
	// Free up space
	delete algorithm;
}

int main() {
	// Dynamically create a array filled with random numbers and output to file
	unsigned int* random = new unsigned int[TEST_SIZE];
	fill_random_numbers(random, TEST_SIZE);
	FileWriter(random, TEST_SIZE, "Random Test Data");

	/************************** BUBBLE SORT *****************************/
	/**
	* Random
	**/
	cout << "/**\n  * Bubble Sort Random\n**/\n";
	// 1000
	ExecuteSort<BubbleSort>("Bubble Sort Random", 1000, random);
	// 2000
	ExecuteSort<BubbleSort>("Bubble Sort Random", 2000, random);
	// 4000
	ExecuteSort<BubbleSort>("Bubble Sort Random", 4000, random);
	// 8000
	ExecuteSort<BubbleSort>("Bubble Sort Random", 8000, random);
	cout << endl;

	/************************** INSERTION SORT **************************/
	/**
	* Random
	**/
	cout << "/**\n  * Insertion Sort Random\n**/\n";
	// 1000
	ExecuteSort<InsertionSort>("Insertion Sort Random", 1000, random);
	// 2000
	ExecuteSort<InsertionSort>("Insertion Sort Random", 2000, random);
	// 4000
	ExecuteSort<InsertionSort>("Insertion Sort Random", 4000, random);
	// 8000
	ExecuteSort<InsertionSort>("Insertion Sort Random", 8000, random);
	cout << endl;

	/************************** RANDOMIZED QUICK SORT *****************************/
	/**
	* Random
	**/
	cout << "/**\n  * Randomized Quick Sort Random\n**/\n";
	// 1000
	ExecuteSort<RandomizedQuickSort>("Randomized Quick Sort Random", 1000, random);
	// 2000
	ExecuteSort<RandomizedQuickSort>("Randomized Quick Sort Random", 2000, random);
	// 4000
	ExecuteSort<RandomizedQuickSort>("Randomized Quick Sort Random", 4000, random);
	// 8000
	ExecuteSort<RandomizedQuickSort>("Randomized Quick Sort Random", 8000, random);
	cout << endl;

	/************************** HEAP SORT *****************************/
	/**
	* Random
	**/
	cout << "/**\n  * Heap Sort Random\n**/\n";
	// 1000
	ExecuteSort<HeapSort>("Heap Sort Random", 1000, random);
	// 2000
	ExecuteSort<HeapSort>("Heap Sort Random", 2000, random);
	// 4000
	ExecuteSort<HeapSort>("Heap Sort Random", 4000, random);
	// 8000
	ExecuteSort<HeapSort>("Heap Sort Random", 8000, random);
	cout << endl;

	/************************** MERGE SORT **************************/
	/**
	* Random
	**/
	cout << "/**\n  * Merge Sort Random\n**/\n";
	// 1000
	ExecuteSort<MergeSort>("Merge Sort Random", 1000, random);
	// 2000
	ExecuteSort<MergeSort>("Merge Sort Random", 2000, random);
	// 4000
	ExecuteSort<MergeSort>("Merge Sort Random", 4000, random);
	// 8000
	ExecuteSort<MergeSort>("Merge Sort Random", 8000, random);
	cout << endl;

	// Delete random test array for memory
	delete[] random;
	
	unsigned int* ascending = new unsigned int[TEST_SIZE];
	unsigned int* descending = new unsigned int[TEST_SIZE];
	// Dynamically create two arrays filled with random ascending and descending numbers 
	fill_sorted_numbers(ascending, descending, TEST_SIZE);
	// Output both arrays to file
	FileWriter(ascending, TEST_SIZE, "\nAscending Test Data");
	FileWriter(descending, TEST_SIZE, "\nDescending Test Data");

	/************************** BUBBLE SORT **************************/
	/**
	* Ascending
	**/
	cout << "/**\n  * Bubble Sort Ascending\n**/\n";
	// 1000
	ExecuteSort<BubbleSort>("Bubble Sort Ascending", 1000, ascending);
	// 2000
	ExecuteSort<BubbleSort>("Bubble Sort Ascending", 2000, ascending);
	// 4000
	ExecuteSort<BubbleSort>("Bubble Sort Ascending", 4000, ascending);
	// 8000
	ExecuteSort<BubbleSort>("Bubble Sort Ascending", 8000, ascending);
	cout << endl;

	/**
	* Descending
	**/
	cout << "/**\n  * Bubble Sort Descending\n**/\n";
	// 1000
	ExecuteSort<BubbleSort>("Bubble Sort Descending", 1000, descending);
	// 2000
	ExecuteSort<BubbleSort>("Bubble Sort Descending", 2000, descending);
	// 4000
	ExecuteSort<BubbleSort>("Bubble Sort Descending", 4000, descending);
	// 8000
	ExecuteSort<BubbleSort>("Bubble Sort Descending", 8000, descending);
	cout << endl;

	/************************** INSERTION SORT **************************/
	/**
	* Ascending
	**/
	cout << "/**\n  * Insertion Sort Ascending\n**/\n";
	// 1000
	ExecuteSort<InsertionSort>("Insertion Sort Ascending", 1000, ascending);
	// 2000
	ExecuteSort<InsertionSort>("Insertion Sort Ascending", 2000, ascending);
	// 4000
	ExecuteSort<InsertionSort>("Insertion Sort Ascending", 4000, ascending);
	// 8000
	ExecuteSort<InsertionSort>("Insertion Sort Ascending", 8000, ascending);
	cout << endl;

	/**
	* Descending
	**/
	cout << "/**\n  * Insertion Sort Descending\n**/\n";
	// 1000
	ExecuteSort<InsertionSort>("Insertion Sort Descending", 1000, descending);
	// 2000
	ExecuteSort<InsertionSort>("Insertion Sort Descending", 2000, descending);
	// 4000
	ExecuteSort<InsertionSort>("Insertion Sort Descending", 4000, descending);
	// 8000
	ExecuteSort<InsertionSort>("Insertion Sort Descending", 8000, descending);
	cout << endl;

	/************************** RANDOMIZED QUICK SORT **************************/
	/**
	* Ascending
	**/
	cout << "/**\n  * Randomized Quick Sort Ascending\n**/\n";
	// 1000
	ExecuteSort<RandomizedQuickSort>("Randomized Quick Sort Ascending", 1000, ascending);
	// 2000
	ExecuteSort<RandomizedQuickSort>("Randomized Quick Sort Ascending", 2000, ascending);
	// 4000
	ExecuteSort<RandomizedQuickSort>("Randomized Quick Sort Ascending", 4000, ascending);
	// 8000
	ExecuteSort<RandomizedQuickSort>("Randomized Quick Sort Ascending", 8000, ascending);
	cout << endl;

	/**
	* Descending
	**/
	cout << "/**\n  * Randomized Quick Sort Descending\n**/\n";
	// 1000
	ExecuteSort<RandomizedQuickSort>("Randomized Quick Sort Descending", 1000, descending);
	// 2000
	ExecuteSort<RandomizedQuickSort>("Randomized Quick Sort Descending", 2000, descending);
	// 4000
	ExecuteSort<RandomizedQuickSort>("Randomized Quick Sort Descending", 4000, descending);
	// 8000
	ExecuteSort<RandomizedQuickSort>("Randomized Quick Sort Descending", 8000, descending);
	cout << endl;

	/************************** HEAP SORT **************************/
/**
* Ascending
**/
	cout << "/**\n  * Heap Sort Ascending\n**/\n";
	// 1000
	ExecuteSort<HeapSort>("Heap Sort Ascending", 1000, ascending);
	// 2000
	ExecuteSort<HeapSort>("Heap Sort Ascending", 2000, ascending);
	// 4000
	ExecuteSort<HeapSort>("Heap Sort Ascending", 4000, ascending);
	// 8000
	ExecuteSort<HeapSort>("Heap Sort Ascending", 8000, ascending);
	cout << endl;

	/**
	* Descending
	**/
	cout << "/**\n  * Heap Sort Descending\n**/\n";
	// 1000
	ExecuteSort<HeapSort>("Heap Sort Descending", 1000, descending);
	// 2000
	ExecuteSort<HeapSort>("Heap Sort Descending", 2000, descending);
	// 4000
	ExecuteSort<HeapSort>("Heap Sort Descending", 4000, descending);
	// 8000
	ExecuteSort<HeapSort>("Heap Sort Descending", 8000, descending);
	cout << endl;

	/************************** MERGE SORT **************************/
	/**
	* Ascending
	**/
	cout << "/**\n  * Merge Sort Ascending\n**/\n";
	// 1000
	ExecuteSort<MergeSort>("Merge Sort Ascending", 1000, ascending);
	// 2000
	ExecuteSort<MergeSort>("Merge Sort Ascending", 2000, ascending);
	// 4000
	ExecuteSort<MergeSort>("Merge Sort Ascending", 4000, ascending);
	// 8000
	ExecuteSort<MergeSort>("Merge Sort Ascending", 8000, ascending);
	cout << endl;

	/**
	* Descending
	**/
	cout << "/**\n  * Merge Sort Descending\n**/\n";
	// 1000
	ExecuteSort<MergeSort>("Merge Sort Descending", 1000, descending);
	// 2000
	ExecuteSort<MergeSort>("Merge Sort Descending", 2000, descending);
	// 4000
	ExecuteSort<MergeSort>("Merge Sort Descending", 4000, descending);
	// 8000
	ExecuteSort<MergeSort>("Merge Sort Descending", 8000, descending);
	cout << endl;

	// Delete ascending test array for memory
	delete[] ascending;
	// Delete descending test array for memory
	delete[] descending;

	return 0;
}

