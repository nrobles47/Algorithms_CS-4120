#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "Fibonacci/Fibonacci.h"
#include "Fibonacci/Recursive/RecursiveFibonacci.h"

using namespace std;

int main() 
{
	RecursiveFibonacci* RF = new RecursiveFibonacci();
	RF->RunAlgorithm();
	delete RF;
	return 0;
}