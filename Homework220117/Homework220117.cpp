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

int CountFirst(const char* _Text, int _Start, const char* _FindStr)
{
    int result = -1;
    int iCount = 0;
    while (0 != _Text[iCount])
    {
        if (_Text[iCount] == _FindStr[0])
        {
            bool isClear = true;
            int stringLength = StringLength(_FindStr);
            for (int i = 0; i < stringLength; i++)
            {
                if (_Text[iCount + i] != _FindStr[i])
                {
                    isClear = false;
                    break;
                }
            }

            if (isClear)
            {
                result = iCount;
                break;
            }
        }

        iCount += 1;
    }
    return result;
}

int CountLast(const char* _Text, int _End, const char* _FindStr)
{
    int result = -1;
    int iCount = StringLength(_Text) - 1;
    while (iCount >= 0)
    {
        if (_Text[iCount] == _FindStr[0])
        {
            bool isClear = true;
            int stringLength = StringLength(_FindStr);
            for (int i = 0; i < stringLength; i++)
            {
                if (_Text[iCount + i] != _FindStr[i])
                {
                    isClear = false;
                    break;
                }
            }

            if (isClear)
            {
                result = iCount;
                break;
            }
        }

        iCount -= 1;
    }

    return result;
}


int main()
{
    int Count1 = CountFirst("aaa ee ttt asdfasd eee", 15, "eee");
    int Count2 = CountLast("aaa eee asdfasd eeee", 15, "eee");

    int a = 0;
}