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

void Reverse(const char* _Text, char* _Result)
{
	int iLength = StringLength(_Text);
	int iCount = 0;
	while (0 != _Text[iCount])
	{
		_Result[iLength - iCount - 1] = _Text[iCount];
		iCount += 1;
	}
}

int main()
{
	char Text[100] = { };
	Reverse("0123456789", Text);
	std::cout << Text;
}