#include <iostream>

class Test1
{
    int a = 0;
    int b = 0;
};
class Test2
{
    int a = 0;
    char b = 0;
};
class Test3
{
public:
    int a = 0;
    char b = 0;
    char c = 0;
    char d = 0;
};

int main()
{
    int TestSize1 = sizeof(Test1);
    int TestSize2 = sizeof(Test2);
    int TestSize3 = sizeof(Test3);

    Test3 newTest3 = Test3();
    __int64 startValue1 = (__int64) & newTest3;
    __int64 startValue3 = (__int64) & newTest3.a;
    __int64 startValue2 = (__int64) & newTest3.b;
    __int64 startValue4 = (__int64) & newTest3.c;
    __int64 startValue5 = (__int64) & newTest3.d;
}