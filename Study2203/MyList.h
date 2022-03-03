#pragma once


using dataType = int;
class MyList
{
private:
	class MyNode
	{
	public:
		dataType value_;
		MyNode* beforeNode_;
		MyNode* nextNode_;

	public:
		MyNode()
			: value_(0)
			, beforeNode_(nullptr)
			, nextNode_(nullptr)
		{
		}
		MyNode(dataType _value)
			: value_(_value)
			, beforeNode_(nullptr)
			, nextNode_(nullptr)
		{
		}
		~MyNode()
		{

		}
	};

public:
	class iterator
	{
		friend MyList;
	private:
		MyNode* curNode_;

	public:
		iterator& operator++()
		{
			curNode_ = curNode_->nextNode_;
			return *this;
		}
		iterator operator++(int)
		{
			iterator tmpIter = iterator(curNode_);
			curNode_ = curNode_->nextNode_;
			return tmpIter;
		}
		bool operator==(const iterator& _other) const
		{
			return curNode_ == _other.curNode_;
		}
		bool operator!=(const iterator& _other) const
		{
			return curNode_ != _other.curNode_;
		}
		dataType operator*()
		{
			return curNode_->value_;
		}

	public:
		iterator()
			: curNode_(nullptr)
		{

		}
		iterator(MyNode* _node)
		{
			curNode_ = _node;
		}
		~iterator()
		{

		}
	};

private:
	int size_;
	MyNode* beginNode_;
	MyNode* endNode_;

public:
	void Push_Front(const dataType& _value)
	{
		size_ += 1;
		MyNode* newNode = new MyNode(_value);
		newNode->beforeNode_ = beginNode_;
		newNode->nextNode_ = beginNode_->nextNode_;

		beginNode_->nextNode_->beforeNode_ = newNode;
		beginNode_->nextNode_ = newNode;
	}
	void Push_Back(const dataType& _value)
	{
		size_ += 1;
		MyNode* newNode = new MyNode(_value);
		newNode->beforeNode_ = endNode_->beforeNode_;
		newNode->nextNode_ = endNode_;

		endNode_->beforeNode_->nextNode_ = newNode;
		endNode_->beforeNode_ = newNode;
	}
	iterator Erase(iterator _iter) const
	{
		MyNode* tmpNode = _iter.curNode_->nextNode_;
		_iter.curNode_->nextNode_->beforeNode_ = _iter.curNode_->beforeNode_;
		_iter.curNode_->beforeNode_->nextNode_ = _iter.curNode_->nextNode_;

		if (nullptr != _iter.curNode_)
		{
			delete _iter.curNode_;
			_iter.curNode_ = nullptr;
		}
		return iterator(tmpNode);
	}
	inline dataType& Front()
	{
		return beginNode_->nextNode_->value_;
	}

	int GetSize()
	{
		return size_;
	}
	iterator Begin() 
	{
		return MyList::iterator(beginNode_->nextNode_);
	}
	iterator End()
	{
		return MyList::iterator(endNode_);
	}


public:
	MyList()
		: size_(0)
		, beginNode_(new MyNode())
		, endNode_(new MyNode())
	{
		beginNode_->nextNode_ = endNode_;
		endNode_->beforeNode_ = beginNode_;
	}
	~MyList()
	{
		MyNode* curNode = beginNode_;
		while (nullptr != curNode)
		{
			MyNode* tmpNode = curNode->nextNode_;
			if (nullptr != curNode)
			{
				delete curNode;
				curNode = nullptr;
			}
			curNode = tmpNode;
		}
	}
};
