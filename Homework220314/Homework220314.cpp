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
	// TestArr는 char포인터형이므로 주소값과 "Test"는 문자열로 취급하기 때문에 값 == 주소 이므로 false가 나온다.
}