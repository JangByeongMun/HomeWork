#include <iostream>

void Cut(const char* _Text, int _Start, int _End, char* _Result)
{
	int iCount = 0;
	for (int i = _Start; i <= _End; i++)
	{
		_Result[iCount] = _Text[i];
		iCount += 1;
	}
}

int main()
{
	char Text[100] = { };
	Cut("0123456789", 2, 5, Text);
	std::cout << Text << std::endl;
}