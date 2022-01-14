#include <iostream>

void CharChange(char* _Text, char _Prev, char _Next)
{
	int iCount = 0;
	while (0 != _Text[iCount])
	{
		if (_Text[iCount] == _Prev)
		{
			_Text[iCount] = _Next;
		}
		iCount += 1;
	}
}

int main()
{
	char Text[100] = "aa, bb, cc, dd , ee , fd , aa";

	CharChange(Text, ',', '|');

	printf_s(Text);
}