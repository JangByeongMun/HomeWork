#pragma once

enum class MyType
{
	Root,
	Left,
	Right,
	Error,
};

using dataType1 = int;
using dataType2 = int;
class MyPair
{
public:
	dataType1 first_;
	dataType2 second_;

	MyPair() 
		: first_(0)
		, second_(0)
	{
	}
	MyPair(const dataType1& _first, const dataType2& _second)
		: first_(_first)
		, second_(_second)
	{
	}
	~MyPair() 
	{
	}
};
MyPair Make_Pair(const dataType1& _key, const dataType2& _value)
{
	return { _key, _value };
}

class MyMap
{
	class iterator;
private:
	class MyNode
	{
		friend MyMap;
	private:
		MyType type_;
		MyPair pair_;
		MyNode* parentNode_;
		MyNode* leftNode_;
		MyNode* rightNode_;

	public:
		MyPair* GetPair() 
		{
			return &pair_;
		}
		bool Insert(const MyPair& _pair)
		{
			if (pair_.first_ == _pair.first_)
			{
				return false;
			}
			if (pair_.first_ > _pair.first_)
			{
				if (nullptr == leftNode_)
				{
					leftNode_ = new MyNode();
					leftNode_->pair_ = _pair;
					leftNode_->type_ = MyType::Left;
					leftNode_->parentNode_ = this;
					return true;
				}
				else
				{
					return leftNode_->Insert(_pair);
				}
			}
			if (pair_.first_ < _pair.first_)
			{
				if (nullptr == rightNode_)
				{
					rightNode_ = new MyNode();
					rightNode_->pair_ = _pair;
					rightNode_->type_ = MyType::Right;
					rightNode_->parentNode_ = this;
					return true;
				}
				else
				{
					return rightNode_->Insert(_pair);
				}
			}

			return false;
		}

		void FirstOrder()
		{
			std::cout << pair_.first_ << std::endl;

			if (nullptr != leftNode_)
			{
				leftNode_->FirstOrder();
			}
			if (nullptr != rightNode_)
			{
				rightNode_->FirstOrder();
			}
		}
		void MidOrder()
		{
			if (nullptr != leftNode_)
			{
				leftNode_->MidOrder();
			}
			std::cout << pair_.first_ << std::endl;
			if (nullptr != rightNode_)
			{
				rightNode_->MidOrder();
			}
		}
		void LastOrder()
		{
			if (nullptr != leftNode_)
			{
				leftNode_->LastOrder();
			}
			if (nullptr != rightNode_)
			{
				rightNode_->LastOrder();
			}
			std::cout << pair_.first_ << std::endl;
		}

		MyNode* BigParent(dataType1 _otherFirst)
		{
			if (nullptr == parentNode_)
			{
				return nullptr;
			}
			else
			{
				if (parentNode_->pair_.first_ > _otherFirst)
				{
					return parentNode_;
				}
				else
				{
					// 부모가 자기보다 작을경우이므로 자기부모보다 큰 부모를 찾아야한다.
					// return BigParent();

					// 이렇게하면 시작노드보다 큰노드 라기보단 시작노드의 부모보다 큰 부모를 찾게된다.
					// 그게 시작노드보다 작을수는 없으므로 사실상 부모의 다음 노드를 찾을순 있으나 뭘 찾는지 확실히 알아보기 힘드므로 수정
					//return parentNode_->BigParent();

					return parentNode_->BigParent(_otherFirst);
				}
			}
		}
		MyNode* Next() 
		{
			if (nullptr != rightNode_)
			{
				// 오른쪽 자식의 왼쪽자식이 있다면 오른쪽자식이 아니라 그 자식의 최소값을 넣어야된다. 
				// return rightNode_;

				return rightNode_->MinNode();
			}
			else
			{
				// 자신의 부모가 자기보다 크다는 보장이없다.
				// return parentNode_;

				return BigParent(pair_.first_);
			}
		}

		MyNode* MinNode()
		{
			int a = pair_.first_;
			if (nullptr == leftNode_)
			{
				return this;
			}

			return leftNode_->MinNode();
		}
		MyNode* MaxNode()
		{
			if (nullptr != rightNode_)
			{
				return rightNode_->MaxNode();
			}
			else
			{
				return this;
			}
		}
	public:
		MyNode()
			: type_(MyType::Error)
			, pair_{}
			, parentNode_(nullptr)
			, leftNode_(nullptr)
			, rightNode_(nullptr)
		{
		}
		~MyNode()
		{
		}
	};
public:
	class iterator
	{
		friend MyMap;
	private:
		MyNode* Node_;

	public:
		MyPair* operator->() const
		{
			return &(Node_->pair_);
		}
		bool operator==(const iterator& _other) const
		{
			return Node_ == _other.Node_;
		}
		bool operator!=(const iterator& _other) const
		{
			return Node_ != _other.Node_;
		}
		iterator& operator++()
		{
			Node_ = Node_->Next();
			return *this;
		}
		MyNode& operator*()
		{
			return *Node_;
		}

	public:
		iterator()
			: Node_(nullptr)
		{
		}
		iterator(MyNode* _node)
			: Node_(_node)
		{
		}
		~iterator()
		{
		}
	};

private:
	MyNode* rootNode_;
	int size_;

public:
	bool Insert(const MyPair& _pair)
	{
		bool isInsert = false;
		if (nullptr == rootNode_)
		{
			rootNode_ = new MyNode();
			rootNode_->type_ = MyType::Root;
			rootNode_->pair_ = Make_Pair(_pair.first_, _pair.second_);
			rootNode_->parentNode_ = nullptr;
			rootNode_->leftNode_ = nullptr;
			rootNode_->rightNode_ = nullptr;

			isInsert = true;
		}
		else
		{
			isInsert = rootNode_->Insert(_pair);
		}

		if (true == isInsert)
		{
			++size_;
		}
		return isInsert;
	}
	inline int Size() const 
	{
		return size_;
	}

	void FirstOrder() 
	{
		rootNode_->FirstOrder();
	}
	void MidOrder() 
	{
		rootNode_->MidOrder();
	}
	void LastOrder()
	{
		rootNode_->LastOrder();
	}

	iterator Begin()
	{
		return iterator(rootNode_->MinNode());
	}
	iterator End()
	{
		return iterator(nullptr);
	}
	iterator Erase(const iterator& _value)
	{
		MyNode* deleteNode = _value.Node_;
		MyNode* changeNode = nullptr;
		MyNode* returnNode = deleteNode->Next();

		if (nullptr != deleteNode->leftNode_)
		{
			changeNode = deleteNode->leftNode_->MaxNode();
			if (nullptr != changeNode->leftNode_)
			{
				changeNode->leftNode_->parentNode_ = changeNode->parentNode_;
			}
		}
		else if (nullptr != deleteNode->rightNode_)
		{
			changeNode = deleteNode->rightNode_->MinNode();
			if (nullptr != changeNode->rightNode_)
			{
				changeNode->rightNode_->parentNode_ = changeNode->parentNode_;
			}
		}

		if (MyType::Left == deleteNode->type_)
		{
			deleteNode->parentNode_->leftNode_ = changeNode;
		}
		if (MyType::Right == deleteNode->type_)
		{
			deleteNode->parentNode_->rightNode_ = changeNode;
		}
		if (MyType::Left == changeNode->type_)
		{
			changeNode->parentNode_->leftNode_ = nullptr;
		}
		if (MyType::Right == changeNode->type_)
		{
			changeNode->parentNode_->rightNode_ = nullptr;
		}

		changeNode->parentNode_ = deleteNode->parentNode_;
		changeNode->leftNode_ = deleteNode->leftNode_;
		changeNode->rightNode_ = deleteNode->rightNode_;

		if (nullptr != changeNode->leftNode_)
		{
			changeNode->leftNode_->parentNode_ = changeNode;
		}
		if (nullptr != changeNode->rightNode_)
		{
			changeNode->rightNode_->parentNode_ = changeNode;
		}

		delete deleteNode;
		deleteNode = nullptr;
		return iterator(returnNode);
	}

public:
	MyMap()
		: rootNode_(nullptr)
		, size_(0)
	{
	}
	~MyMap()
	{
	}
};
