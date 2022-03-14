#pragma once
#include <iostream>
#include <queue>
#include "MyQueue.h"

using namespace std;

int main()
{
	queue<int> stdQue = queue<int>();

	stdQue.push(2);
	stdQue.push(10);
	stdQue.push(5);
	stdQue.push(7);
	stdQue.push(9);
	
	cout << "---" << stdQue.size() << "---" << endl;
	int size = stdQue.size();
	for (int i = 0; i < size; i++)
	{
		cout << stdQue.front() << endl;
		stdQue.pop();
	}
	cout << "---------" << endl;

	MyQueue myQue = MyQueue();

	myQue.Push(2);
	myQue.Push(10);
	myQue.Push(5);
	myQue.Push(7);
	myQue.Push(9);

	cout << "---" << myQue.Size() << "---" << endl;

	for (; !myQue.Empty(); myQue.Pop())
	{
		cout << myQue.Front() << endl;
	}
	cout << "---------" << endl;
}