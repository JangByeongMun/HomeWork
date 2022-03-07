#include <iostream>

using namespace std;

struct TestStr
{
	int a;
	int b;
};



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int testArr[20] = {};
	int* testIntPtr = new int[10];
	for (int i = 0; i < 20; i++)
	{
		cout << testIntPtr[i] << endl;
	}
	delete[] testIntPtr;

	TestStr ts = {1, 2};
}