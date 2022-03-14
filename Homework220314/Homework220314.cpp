#include <iostream>

int main()
{
	char TestArr[10] = "Test";

	if ("Test" == TestArr)
	{
		int a = 0;
	}
	else
	{
		int a = 0;
	}
	// TestArr는 char포인터형이므로 주소값과 "Test"의 주소값이 다르기 때문에 false가 나온다.
	// 값과 주소를 비교하는줄 알았는데 주소끼리의 계산이라고함.
}