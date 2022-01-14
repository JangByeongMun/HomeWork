#include <iostream>

int main()
{
	{   // 배열에 1부터 짝수로 가득 채우기.
		int arr[10] = {0};
		int index = 0;
		while (10 > index)
		{
			arr[index] = 2 * (index + 1);
			index += 1;
		}

		int a = 0;
	}

	{	// 배열에 1부터 홀수로 가득 채우기
		int arr[10] = { 0 };
		int index = 0;
		while (10 > index)
		{
			arr[index] = (2 * index) + 1;
			index += 1;
		}

		int a = 0;
	}
}