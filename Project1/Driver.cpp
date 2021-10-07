#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "Driver_Functions/Driver_Functions.h"

using namespace std;

const unsigned int TEST_SIZE = 3500;

int main() {
	// Fill Arrays and Output to File
	int* random = new int[TEST_SIZE];
	fill_random_numbers(random, TEST_SIZE);
	FileWriter(random, TEST_SIZE, "Random Test Data");
	delete[] random;
	
	int* ascending = new int[TEST_SIZE];
	int* descending = new int[TEST_SIZE];
	fill_sorted_numbers(ascending, descending, TEST_SIZE);
	FileWriter(ascending, TEST_SIZE, "\nAscending Test Data");
	FileWriter(descending, TEST_SIZE, "\nDescending Test Data");
	delete[] ascending;
	delete[] descending;

	return 0;
}

