//#include "Bottom_Up_Fibonacci.h"
//
//int BottomUpFib::BUF(int n)
//{
//    size_t* fibArray = new size_t[n + 1];
//    fibArray[0] = 0;
//    fibArray[1] = 1;
//
//    for (int i = 2; i <= n; i++)
//        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//
//    return fibArray[n];
//}
//
//void BottomUpFib::RunAlgorithm()
//{
//    for (int i = 0; i < 7; i++)
//    {
//        this->SetStartTime(i);
//        this->SetOutputArray(i, BUF(this->GetInputArray(i)));
//        this->SetStopTime(i);
//    }
//}
