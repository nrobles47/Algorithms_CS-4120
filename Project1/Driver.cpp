#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "Driver_Functions/Driver_Functions.h"
#include "Bubble_Sort/BubbleSort.h"
#include "Insertion_Sort/Insertion_Sort.h"
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
void ExecuteSort(string algName, int testSize, int makeCopy[]) 
{
	// Instantiate sort object
	T* algorithm = new T(algName, testSize);
	// Make copy of array we wish to sort
	int* testCopy = algorithm->CopyArray(makeCopy);
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
	int* random = new int[TEST_SIZE];
	fill_random_numbers(random, TEST_SIZE);
	FileWriter(random, TEST_SIZE, "Random Test Data");

	/**
	* Bubble Sort Random
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

	/**
	* Insertion Sort Random
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

	// Delete random test array for memory
	delete[] random;
	
	int* ascending = new int[TEST_SIZE];
	int* descending = new int[TEST_SIZE];
	fill_sorted_numbers(ascending, descending, TEST_SIZE);
	FileWriter(ascending, TEST_SIZE, "\nAscending Test Data");
	FileWriter(descending, TEST_SIZE, "\nDescending Test Data");

	/**
	* Bubble Sort Ascending
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
	* Bubble Sort Descending
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

	// Delete ascending test array for memory
	delete[] ascending;
	// Delete descending test array for memory
	delete[] descending;

	return 0;
}

