#include "Memoized_Top_Down_Fibonacci.h"
#include <iostream>
#include <map>

using namespace std;

size_t cache[100];

int MTDFibonacci::MTDF(int n)
{
    int result = 0;
    if (n <= 1)
    {
        result = cache[n];
    }
    else
    {
        if (cache[n] == 0)
        {
            result = MTDF(n - 1) + MTDF(n - 2);
            cache[n] = result;
        }
        else {
            return result = cache[n];
        }
    }
    return result;
}

void MTDFibonacci::RunAlgorithm()
{
    for (int i = 0; i < 7; i++)
    {
        this->SetStartTime(i);

        int n = this->GetInputArray(i);
        for (int j = 0; j < n; j++)
        {
            j <= 1 ? cache[j] = 1 : cache[j] = 0;
        }

        this->SetOutputArray(i, MTDF(n-1));
        this->SetStopTime(i);
    }
}