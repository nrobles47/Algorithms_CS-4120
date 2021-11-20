#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "Fibonacci/Fibonacci.h"
#include "Fibonacci/Recursive/RecursiveFibonacci.h"
#include "Fibonacci/Memoized_Top_Down/Memoized_Top_Down_Fibonacci.h"
#include "Fibonacci/Bottom_Up/Bottom_Up_Fibonacci.h"

using namespace std;

int main() 
{
	/* FIBONACCI SEQUENCE */
	// Recursive
	RecursiveFibonacci* RF = new RecursiveFibonacci();
	RF->RunAlgorithm();
	delete RF;
	// Memoized Top Down
	MTDFibonacci* TD = new MTDFibonacci();
	TD->RunAlgorithm();
	delete TD;
	// Bottom Up
	BottomUpFib* BU = new BottomUpFib();
	BU->RunAlgorithm();
	delete BU;
	return 0;
}