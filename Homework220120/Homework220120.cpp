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
    char z = {0};
    int a = 0;
    char b = 0;
    char c = 0;
    char d = 0;
    __int64 e = 0;
};

class Test4
{
public:
    char a;
    Test3 b;
    int c;
    char d;
};

int main()
{
    int TestSize1 = sizeof(Test1);
    int TestSize2 = sizeof(Test2);
    int TestSize3 = sizeof(Test3);

    Test3 newTest3 = Test3();
    __int64 startValue1 = (__int64) & newTest3;
    //__int64 startValue2 = (__int64) & newTest3.z[0];
    //__int64 startValue3 = (__int64) & newTest3.z[1];
    //__int64 startValue4 = (__int64) & newTest3.z[2];
    __int64 startValue10 = (__int64)&newTest3.z;
    __int64 startValue5 = (__int64) & newTest3.a;
    __int64 startValue6 = (__int64) & newTest3.b;
    __int64 startValue7 = (__int64) & newTest3.c;
    __int64 startValue8 = (__int64) & newTest3.d;
    __int64 startValue9 = (__int64) & newTest3.e;


    int TestSize4 = sizeof(Test4);
    Test4 newText4 = Test4();
    __int64 startValue2_0 = (__int64)&newText4;
    __int64 startValue2_1 = (__int64)&newText4.a;
    __int64 startValue2_2 = (__int64)&newText4.b;
    __int64 startValue2_3 = (__int64)&newText4.c;
    __int64 startValue2_4 = (__int64)&newText4.d;

    Test4 testArr[10] = {};
}
6.