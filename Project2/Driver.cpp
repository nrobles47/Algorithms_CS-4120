#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include "Fibonacci/Fibonacci.h"
#include "Fibonacci/Recursive/RecursiveFibonacci.h"
#include "Fibonacci/Memoized_Top_Down/Memoized_Top_Down_Fibonacci.h"
#include "Fibonacci/Bottom_Up/Bottom_Up_Fibonacci.h"

#include "MatrixChainMultiplication/MCM.h"
#include "MatrixChainMultiplication/Recursive/RecursiveMCM.h"
#include "MatrixChainMultiplication/Memoized_Top_Down/Memoized_Top_Down_MCM.h"
#include "MatrixChainMultiplication/Bottom_Up/Bottom_Up_MCM.h"

using namespace std;

int main() 
{
	/* FIBONACCI SEQUENCE */
	std::ofstream outFile;
	outFile.open("Fibonacci/Fibonacci_Output.txt", ios::trunc);
	outFile.close();
	// Recursive
	RecursiveFibonacci* RF = new RecursiveFibonacci();
	RF->RunAlgorithm();
	delete RF;
	// Memoized Top Down
	/*MTDFibonacci* TD = new MTDFibonacci();
	TD->RunAlgorithm();
	delete TD;*/
	// Bottom Up
	/*BottomUpFib* BU = new BottomUpFib();
	BU->RunAlgorithm();
	delete BU;*/
	
	/* Matrix Chain Multiplication */
	/*std::ofstream outFile;
	outFile.open("MatrixChainMultiplication/MCM_Output.txt", ios::trunc);
	outFile.close();*/
	
	// Recursive
	/*RecursiveMCM* RM = new RecursiveMCM();
	RM->RunAlgorithm();
	delete RM;
	std::ofstream parenFile1;
	parenFile1.open("MatrixChainMultiplication/MCM_Paren_Output.txt", ios::trunc);
	parenFile1.close();*/
	
	// Memoized Top Down
	/*MemoizedMCM* MemM = new MemoizedMCM();
	MemM->RunAlgorithm();
	delete MemM;
	std::ofstream parenFile2;
	parenFile2.open("MatrixChainMultiplication/MCM_Paren_Output.txt", ios::trunc);
	parenFile2.close();*/
	
	// Bottom Up
	/*BottomUpMCM* BM = new BottomUpMCM();
	BM->RunAlgorithm();
	delete BM;
	std::ofstream parenFile3;
	parenFile3.open("MatrixChainMultiplication/MCM_Paren_Output.txt", ios::trunc);
	parenFile3.close();*/

	return 0;
}