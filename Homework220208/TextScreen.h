#pragma once
#include "ConsoleMath.h"
#include <assert.h>

// 설명 :
class TextScreen
{
public:
	// constrcuter destructer
	TextScreen(int _Width, int _Height, const char* _DefaultValue);
	~TextScreen();

	// delete Function
	TextScreen(const TextScreen& _Other) = delete;
	TextScreen(TextScreen&& _Other) noexcept = delete;
	TextScreen& operator=(const TextScreen& _Other) = delete;
	TextScreen& operator=(TextScreen&& _Other) noexcept = delete;

	ConsoleVector GetSize() 
	{
		return Size_;
	}

	void CreateScreen(int _Width, int _Height, const char* _DefaultValue);
	void SettingScreen();
	void PrintScreen();

	// X Y위치에 글자를 출력한다.
	void SetPixel(ConsoleVector _Pos, const char* _DefaultValue);
	void SetPixel(int _X, int _Y, const char* _DefaultValue);
	void CheckValidPos(ConsoleVector _pos);
	void CheckValidPos(int _x, int _y);

protected:

private:
	ConsoleVector Size_;
	char** PixelData_;
	char DefaultPixel_[3];
};

