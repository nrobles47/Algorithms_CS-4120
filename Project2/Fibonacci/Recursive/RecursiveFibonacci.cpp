#include "RecursiveFibonacci.h"

using namespace std;

int RecursiveFibonacci::RecFib(int n)
{
    if (n <= 1)
        return n;
    return RecFib(n - 1) + RecFib(n - 2);
}

void RecursiveFibonacci::RunAlgorithm()
{
    for (int i = 0; i < 7; i++)
    {
        this->SetStartTime(i);
        this->SetOutputArray(i, RecFib(this->GetInputArray(i)));
        this->SetStopTime(i);
    }
}
