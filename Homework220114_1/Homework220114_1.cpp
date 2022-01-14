#include <iostream>

void ToUpper(const char* _Left, char* _Right)
{
	int iCountLeft = 0;
	int iCountRight = 0;
	while (0 != _Left[iCountLeft])
	{
		if ('a' <= _Left[iCountLeft] && _Left[iCountLeft] <= 'z')
		{
			_Right[iCountRight] = _Left[iCountLeft] - 32;
		}
		else
		{
			_Right[iCountRight] = _Left[iCountLeft];
		}

		iCountRight += 1;
		iCountLeft += 1;
	}
}

int main()
{
	char Text[10000] = {0};
	ToUpper("aBCdeF12gHik", Text);
	printf_s(Text);
}
