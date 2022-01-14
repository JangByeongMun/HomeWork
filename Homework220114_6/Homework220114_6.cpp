#include <iostream>

int StringLength(const	char* _s)
{
	int iCount = 0;
	while (0 != _s[iCount])
	{
		iCount += 1;
	}
	return iCount;
}

void TextChange(char* _Text, const char* _Prev, const char* _Next)
{
	char tmpChar[100] = {0};
	int iPrevLength = StringLength(_Prev);
	
	int iCount = 0;
	int iTmpCount = 0;
	// 캐릭터형을 끝까지 돌면서 바꿀 텍스트가 있는지 확인
	while (0 != _Text[iCount])
	{
		// 현재 문자가 바꿀 텍스트의 시작 문자일경우
		if (_Text[iCount] == _Prev[0])
		{
			// 바꿀문자와 일치하는지 확인
			bool bClear = true;
			for (int i = 1; i < iPrevLength; i++)
			{
				if (_Text[iCount + 1] != _Prev[i])
				{
					bClear = false;
					break;
				}
			}

			// 바꿀 텍스트가 맞을경우
			if (true == bClear)
			{
				int iNextCount = 0;
				while (0 != _Next[iNextCount])
				{
					tmpChar[iTmpCount] = _Next[iNextCount];
					iTmpCount += 1;
					iNextCount += 1;
				}
				iCount += iPrevLength;
			}
			else
			{
				tmpChar[iTmpCount] = _Text[iCount];
				iTmpCount += 1;
				iCount += 1;
			}
		}
		else
		{
			tmpChar[iTmpCount] = _Text[iCount];
			iTmpCount += 1;
			iCount += 1;
		}

		//std::cout << tmpChar << std::endl;
	}

	iCount = 0;
	while (0 != tmpChar[iCount])
	{
		_Text[iCount] = tmpChar[iCount];
		iCount += 1;
	}
}

int main()
{
	char Text[100] = "aa, bb, aa, aaaaa cfafaas";

	TextChange(Text, "aa", "fff");
	printf_s(Text);
}