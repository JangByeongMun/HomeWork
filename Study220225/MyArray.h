#pragma once
#include <assert.h>

using dataType = int;
class MyArray
{
private:
	int size_;
	dataType* dataArr;

public:
	void Resize(int _size)
	{
		dataType* tmpArr = new dataType[_size];
		for (int i = 0; i < _size; i++)
		{
			if (i < size_)
			{
				tmpArr[i] = dataArr[i];
			}
			else
			{
				tmpArr[i] = 0;
			}
		}
		
		if (nullptr != dataArr)
		{
			delete dataArr;
		}

		dataArr = tmpArr;
		size_ = _size;
	}
	int GetSize()
	{
		return size_;
	}

	dataType& operator[](int _index)
	{
		if (_index >= size_)
		{
			assert(false);
		}

		return dataArr[_index];
	}

public:
	MyArray()
		: size_(0)
		, dataArr(new dataType[0])
	{
	}
	MyArray(int _size)
		: size_(_size)
		, dataArr(new dataType[_size])
	{
	}
	~MyArray()
	{
		if (nullptr != dataArr)
		{
			delete dataArr;
			dataArr = nullptr;
		}
	}
};

