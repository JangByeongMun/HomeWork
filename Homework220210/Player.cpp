#include "Player.h"
#include <conio.h>
#include "ConsoleGlobalInst.h"

Player::Player(TextScreen* _Screen, const char* _Text)
	: ConsoleObject(_Screen, _Text, _Screen->GetSize().GetHalfVector())
	, IsContinue_(true)
{
}

Player::~Player() 
{
}


void Player::Update() 
{
	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		SetMove({-1, 0});
		break;
	case 'd':
	case 'D':
		SetMove({ 1, 0 });
		break;
	case 'w':
	case 'W':
		SetMove({ 0, -1 });
		break;
	case 's':
	case 'S':
		SetMove({ 0, 1 });
		break;
	case 'q':
	case 'Q':
		IsContinue_ = false;
		break;
	default:
		break;
	}
}

