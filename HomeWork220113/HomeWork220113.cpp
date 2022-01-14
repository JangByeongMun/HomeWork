#include <iostream>

// 공백을 제거하는 함수
void StringTrimRemove(const char* _left, char* _right)
{
	int countL = 0;
	int countR = 0;
	while (0 != _left[countL])
	{
		if (' ' != _left[countL])
		{
			_right[countR] = _left[countL];
			countR += 1;
		}

		countL += 1;
	}
}

int main()
{
	char text[10000] = { 0 };
	StringTrimRemove("a    df     s   g    h  j  k     ", text);

	printf_s(text);
}