#include "ConsoleObject.h"

ConsoleObject::ConsoleObject(
	TextScreen* _Screen,
	const char* _Text,
	const ConsoleVector& _Pos
	)
	: Screen_(_Screen)
	, Pos_(_Pos)
{
	//if (nullptr == _Screen)
	//{
	//	assert(false);
	//}

	if (nullptr == _Text)
	{
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		Text_[i] = _Text[i];
	}
}

ConsoleObject::~ConsoleObject() 
{
}

void ConsoleObject::Render() 
{
	if (nullptr == Screen_)
	{
		assert(false);
	}

	Screen_->SetPixel(Pos_, Text_);
}

bool ConsoleObject::CheckValidPos(ConsoleVector _pos)
{
	return CheckValidPos(_pos.x_, _pos.y_);
}

bool ConsoleObject::CheckValidPos(int _x, int _y)
{
	if (_x >= Screen_->GetSize().x_ || -1 >= _x)
	{
		return false;
	}
	if (_y >= Screen_->GetSize().y_ || -1 >= _y)
	{
		return false;
	}

	return true;
}
