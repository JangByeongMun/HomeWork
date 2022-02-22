#include <iostream>
#include "GameVectorSort.h"

int main()
{
    GameVectorSort<int> MyVector = GameVectorSort<int>();

    MyVector.push_back(5);
    MyVector.push_back(10);
    MyVector.push_back(5);
    MyVector.push_back(1);
    MyVector.push_back(2);
    MyVector.push_back(8);
    MyVector.push_back(99);

    MyVector.push_back_NoOverlap(2);
    MyVector.push_back_NoOverlap(8);
    MyVector.push_back_NoOverlap(99);
    MyVector.push_back_NoOverlap(150);
    MyVector.push_back_NoOverlap(7);

    MyVector.CheckInside();
}