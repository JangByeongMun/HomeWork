#include <iostream>

class A
{
public:
    A& operator()()
    {
        return *this;
    }
};

class B
{
public:
    B(A _a)
    {

    }
};

int main()
{
    A NewA;
    B NewB(NewA());
}