#include <iostream>

using namespace std;

class A
{
	int a;

	// delete Function
	//A(const A& _Other) = delete;
	//A(A&& _Other) noexcept = delete;
	A& operator=(const A& _Other) = delete;
	A& operator=(A&& _Other) noexcept = delete;
};


namespace TestSpace
{
	int a = 0;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	TestSpace::a = 1;
	A newA = A();
}