#include <iostream>
#include <vector>
#include "MyArray.h"
#include "MyVector.h"

using namespace std;
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	MyArray arr = MyArray(5);
	for (int i = 0; i < arr.GetSize(); i++)
	{
		arr[i] = i + 1;
	}
	arr.Resize(10);
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << arr[i] << endl;
	}
	cout << "--arr--------" << arr.GetSize() << "-------------------" << endl;


	MyVector vec = MyVector();
	vec.Reserve(5);
	vec.Resize(3);
	vec.Push_Back(77);
	vec.Push_Back(77);
	vec.Push_Back(77);
	vec.Push_Back(77);
	vec.Pop_Back();
	MyVector::iterator myIter = vec.Begin();
	for (; myIter != vec.End(); ++myIter)
	{
		cout << *myIter << endl;
	}
	cout << "--MyVec--------" << vec.GetSize() << "---------" << vec.GetCapacity() << "----------" << endl;


	vector<int> stdVec = vector<int>();
	stdVec.reserve(5);
	stdVec.resize(3);
	stdVec.push_back(77);
	stdVec.push_back(77);
	stdVec.push_back(77);
	stdVec.push_back(77);
	stdVec.pop_back();

	vector<int>::iterator stdIter = stdVec.begin();
	for (; stdIter != stdVec.end(); ++stdIter)
	{
		cout << *stdIter << endl;
	}
	cout << "--stdVec--------" << stdVec.size() << "---------" << stdVec.capacity() << "----------" << endl;
}