#pragma once
#include "MyArray.h"

//using dataType = int;
template <typename dataType>
class MyVector 
{
public:
	class iterator
	{
	private:
		dataType* ptr_;
	
	public:
		bool operator==(iterator _other)
		{
			return ptr_ == _other.ptr_;
		}
		bool operator!=(iterator _other)
		{
			return ptr_ != _other.ptr_;
		}
		iterator& operator++()
		{
			ptr_ += 1;
			return *this;
		}
		iterator operator++(int)
		{
			iterator tmpIter = iterator(ptr_);
			ptr_ += 1;
			return tmpIter;
		}
		dataType& operator*()
		{
			return *ptr_;
		}

	public:
		iterator()
			: ptr_(nullptr)
		{
		}
		iterator(dataType* _data)
			: ptr_(_data)
		{
		}
		~iterator()
		{
		}
	};

private:
	int size_;
	int capacity_;
	MyArray arr_;

public:
	int GetSize()
	{
		return size_;
	}
	int GetCapacity()
	{
		return capacity_;
	}
	void Resize(int _size) 
	{
		size_ = _size ;
		if (_size > capacity_)
		{
			capacity_ = _size;
			arr_.Resize(_size);
		}
	}
	void Reserve(int _capacity)
	{
		capacity_ = _capacity;
		arr_.Resize(_capacity);
	}
	void Push_Back(dataType _value)
	{
		if (size_ >= capacity_)
		{
			Reserve(capacity_ * 2);
		}
		arr_[size_] = _value;
		++size_;
	}
	void Pop_Back()
	{
		--size_;
	}

	dataType& operator[](int _index)
	{
		return arr_[_index];
	}

	iterator Begin()
	{
		return MyVector::iterator(&arr_[0]);
	}
	iterator End()
	{
		return MyVector::iterator(&arr_[0] + size_);
	}

public:
	MyVector()
		: size_(0)
		, capacity_(0)
		, arr_(MyArray(0))
	{
	}
	MyVector(int _value)
		: size_(_value)
		, capacity_(_value)
		, arr_(MyArray(_value))
	{
	}
	~MyVector()
	{
		
	}
};