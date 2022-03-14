#pragma once
#include "MyList.h"

using dataType = int;
class MyQueue
{
public:
	MyQueue()
	{

	}
	~MyQueue()
	{

	}

	void Push(dataType _value)
	{
		list_.Push_Back(_value);
	}
	void Pop()
	{
		list_.Pop_Front();
	}
	int Size()
	{
		return list_.GetSize();
	}
	dataType& Front()
	{
		return list_.Front();
	}
	bool Empty()
	{
		return (list_.GetSize() == 0);
	}

private:
	MyList list_;

};