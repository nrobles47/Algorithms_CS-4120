#include "Driver_Functions.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void FileWriter(int arr[], int ARR_SIZE, string name)
{
	ofstream outFile;
	if (outFile) {
		outFile.open("Sorts_Out.txt", ios::app);
	}
	else {
		cerr << "Cannot create or find file!" << endl;
	}
	outFile << endl << name << endl;
	for (int i = 0; i < ARR_SIZE && !outFile.eof(); i++) {
		outFile << arr[i] << fixed << setw(10);
	}
	outFile.close();
}


void fill_random_numbers(int arr[], const unsigned int SIZE)
{
	// Pre:  SIZE is no more than a million, arr has been declared to be
	//       an array of at least SIZE elements.
	// Post: The first SIZE elements of the array arr have been populated with
	//       random integers between 0 and one million.

	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = round(rand() / double(RAND_MAX) * 1000000);
	}
}

void fill_sorted_numbers(int asc [], int dsc [], const unsigned int SIZE)
{
	// Pre:  SIZE is no more than a million, and asc and dsc have been declared
	//       to be arrays of at least SIZE elements.
	// Post: The first SIZE elements of the array asc have been populated with
	//       integers between 0 and one million in ascending order, and dsc has
	//       the same numbers in descending order.

	int step = 1000000 / SIZE;

	for (int i = 0; i < SIZE; i++)
	{
		asc[i] = dsc[SIZE - 1 - i] = step * i;
	}
}
