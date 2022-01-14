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

int ToInt(const char* _s)
{
	int iLength = StringLength(_s);
	int iResult = 0;

	int iCount = 0;
	while (0 != _s[iCount])
	{
		int tmpInt = (_s[iCount] - 48);
		for (int i = 0; i < (iLength - iCount - 1); i++)
		{
			tmpInt *= 10;
		}

		iResult += tmpInt;
		iCount += 1;
	}

	return iResult;
}

int main()
{
	int Value = ToInt("567813547");
	std::cout << Value << std::endl;

	int a = 0;
}
