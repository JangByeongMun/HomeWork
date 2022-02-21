#include "Head.h"
#include "Body.h"
#include <conio.h>
#include "Engine/ConsoleMath.h"
#include "GlobalGameLogic.h"

Head::Head()
	: AllBody(0)
	, BeforeVector(0)
{
}

Head::~Head() 
{
	std::list<Body*>::iterator iter = AllBody.begin();
	while (AllBody.end() != iter)
	{
		delete* iter;
		iter = AllBody.erase(iter);
	}
	AllBody.clear();

	std::list<ConsoleVector*>::iterator iter2 = BeforeVector.begin();
	while (BeforeVector.end() != iter2)
	{
		delete *iter2;
		iter2 = BeforeVector.erase(iter2);
	}
	BeforeVector.clear();
}


bool Head::CrashBody(const ConsoleVector* _vector) const
{
	std::list<Body*>::const_iterator iter = AllBody.begin();
	while (AllBody.end() != iter)
	{
		if ((*iter)->GetPos() == *_vector)
		{
			return true;
		}
		iter++;
	}
	return false;
}

void Head::Render()
{
	ConsoleObject::Render();

	std::list<Body*>::iterator iter = AllBody.begin();
	while (AllBody.end() != iter)
	{
		(*iter)->Render();
		iter++;
	}
}

void Head::Update()
{
	// �ٵ� ����������ϱ����� ��ġ����
	BeforeVector.push_front(new ConsoleVector(GetPos().x_, GetPos().y_));

	// ������ ��ġ�� �ٵ�� �̵�
	BodySetPos();

	int Value = _getch();
	switch (Value)
	{
	case 'a':
	case 'A':
		InScreenMovement({ -1, 0 });
		break;
	case 'd':
	case 'D':
		InScreenMovement({ 1, 0 });
		break;
	case 'w':
	case 'W':
		InScreenMovement({ 0, -1 });
		break;
	case 's':
	case 'S':
		InScreenMovement({ 0, 1 });
		break;
	case 'q':
	case 'Q':
		Death();
		return;
	default:
		break;
	}

	// �ε������� üũ
	CheckBodyCrash();
	return;
}

void Head::OverLap(ConsoleObject* _Link)
{
	AllBody.push_back((Body*)_Link);
	_Link->SetRenderChar("��");
	BodySetPos();

	ConsoleVector tmpVec = ConsoleScreen::GetInst().GetSize();
	if (AllBody.size() >= (tmpVec.x_ * tmpVec.y_) - 1)
	{
		GlobalGameLogic::isClear = true;
	}
}

void Head::BodySetPos()
{
	std::list<Body*>::iterator bodyIter = AllBody.begin();
	std::list<ConsoleVector*>::iterator vectorIter = BeforeVector.begin();
	while (AllBody.end() != bodyIter && BeforeVector.end() != vectorIter)
	{
		(*bodyIter)->SetPos(**vectorIter);
		
		++bodyIter;
		++vectorIter;
	}
}

void Head::CheckBodyCrash()
{
	// �ٵ� 1���� ������� �ٷ� �ڷΰ��� ���� ��ġ�� �ٲ�鼭 ��ư��°� ����ó��
	if (AllBody.size() >= 1 && OverLapCheck(*(++BeforeVector.begin())))
	{
		Death();
		return;
	}

	// �������� �ڱ� �ٵ�� �ε������ ���
	std::list<Body*>::iterator bodyIter = AllBody.begin();
	while (AllBody.end() != bodyIter)
	{
		if (OverLapCheck(*bodyIter))
		{
			Death();
			return;
		}
		++bodyIter;
	}
}
