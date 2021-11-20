#include "Memoized_Top_Down_Fibonacci.h"
#include <iostream>
#include <map>

using namespace std;

int MTDFibonacci::MTDF(int n, int* cache)
{
    int result = 0;
    if (n <= 1)
    {
        result = cache[n];
    }
    else
    {
        if (cache[n] == -1)
        {
            result = MTDF(n - 1, cache) + MTDF(n - 2, cache);
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
        int* temp = new int[n];
        for (int j = 0; j < n; j++)
        {
            j <= 1 ? temp[j] = 1 : temp[j] = -1;
        }

        this->SetOutputArray(i, MTDF(n-1, temp));
        this->SetStopTime(i);
        delete[] temp;
    }
}