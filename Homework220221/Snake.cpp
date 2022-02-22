// Snake.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Engine/ConsoleScreen.h"
#include <conio.h>
#include "Head.h"
#include "Body.h"
#include <vector>
#include "Engine/ConsoleRandom.h"
#include "GlobalGameLogic.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(174);

	ConsoleScreen::GetInst().CreateScreen(4, 4, "□");

	ConsoleObject* NewHead = new Head();
	NewHead->Init({ ConsoleScreen::GetInst().GetSize().x_ / 2, ConsoleScreen::GetInst().GetSize().y_ / 2 }, "★");

	ConsoleObject* NewBody = GlobalGameLogic::CreateBodyLogic(NewHead);

	while (true)
	{
		if (nullptr == NewBody)
		{
			NewBody = GlobalGameLogic::CreateBodyLogic(NewHead);
		} 
	
		ConsoleScreen::GetInst().RenderStart();
	
		NewBody->Render();
		NewHead->Render();
	
		ConsoleScreen::GetInst().RenderEnd();
	
		NewBody->Update();
		NewHead->Update();
	
		if (NewHead->OverLapCheck(NewBody))
		{
			NewHead->OverLap(NewBody);
			NewBody = nullptr;
		}

		if (true == NewHead->GetIsDeath() || true == GlobalGameLogic::isClear)
		{
			break;
		}
	}

	// 마지막 렌더
	ConsoleScreen::GetInst().RenderStart();
	if (nullptr != NewBody)
	{
		NewBody->Render();
		delete (Body*)NewBody;
		NewBody = nullptr;
	}
	if (nullptr != NewHead)
	{
		NewHead->Render();
		delete (Head*)NewHead;
		NewHead = nullptr;
	}
	ConsoleScreen::GetInst().RenderEnd();

	ConsoleScreen::Destroy();
}
