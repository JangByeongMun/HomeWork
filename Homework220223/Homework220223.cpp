#include <iostream>

int Value = 0;
void Func()
{
    if (Value >= 30)
    {
        return;
    }

    std::cout << ++Value << std::endl;
    Func();
}

int main()
{
    Func();
}