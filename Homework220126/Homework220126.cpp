#include <iostream>

class MyInt
{
public:
    int Value;

public:
    // 전위
    MyInt& operator++()
    {
        this->Value += 1;
        return *this;
    }

    // 후위
    MyInt operator++(int)
    {
        MyInt beforeMyInt = MyInt(this->Value);
        this->Value += 1;
        return beforeMyInt;
    }

    // 전위
    MyInt& operator--()
    {
        this->Value -= 1;
        return *this;
    }

    // 후위
    MyInt operator--(int)
    {
        MyInt beforeMyInt = MyInt(this->Value);
        this->Value -= 1;
        return beforeMyInt;
    }

public:
    MyInt(int _Value)
        : Value(_Value)
    {

    }
};



int main()
{
    int Value = 0;
    int Result = 0;

    Result = ++Value;
    Result = 0;
    Result = Value++;


    MyInt MyValue = MyInt(0);
    MyInt MyResult = 0;

    MyResult = ++MyValue;
    MyResult = 0;
    MyResult = MyValue++;

    MyResult = --MyValue;
    MyResult = 0;
    MyResult = MyValue--;
} 