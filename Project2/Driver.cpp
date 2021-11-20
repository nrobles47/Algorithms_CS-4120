#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "Fibonacci/Fibonacci.h"
#include "Fibonacci/Recursive/RecursiveFibonacci.h"
#include "Fibonacci/Memoized_Top_Down/Memoized_Top_Down_Fibonacci.h"

using namespace std;

int main() 
{
	// Recursive Fibonacci
	RecursiveFibonacci* RF = new RecursiveFibonacci();
	RF->RunAlgorithm();
	delete RF;
	// Memoized Top Down fibonacci
	MTDFibonacci* TD = new MTDFibonacci();
	TD->RunAlgorithm();
	delete TD;
	return 0;
}