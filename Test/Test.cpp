#include <iostream>
#include <list>
#include <conio.h>

class Player
{
public:
	Player();
	~Player();

	std::list<int*> AllBody;
};
Player::Player()
{
}

Player::~Player()
{
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(157);

	Player* testPlayer = new Player();

	delete testPlayer;
	//testPlayer = nullptr;
}
