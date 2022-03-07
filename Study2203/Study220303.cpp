#include <iostream>
#include <list>
#include "MyList.h"


using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	list<int> stdList = list<int>();
	stdList.push_back(1);
	stdList.push_front(2);
	stdList.push_front(3);
	stdList.push_back(4);
	stdList.push_back(5);
	stdList.erase(++stdList.begin());
	//stdList.front() = 10;
	stdList.pop_front();
	stdList.pop_back();

	list<int>::iterator stdBeginIter = stdList.begin();
	list<int>::iterator stdEndIter = stdList.end();
	for (; stdBeginIter != stdEndIter; ++stdBeginIter)
	{
		cout << *stdBeginIter << endl;
	}
	cout << "--stdVec--------" << stdList.size() << "-------------------" << endl;
	
	MyList myList = MyList();
	myList.Push_Back(1);
	myList.Push_Front(2);
	myList.Push_Front(3);
	myList.Push_Back(4);
	myList.Push_Back(5);
	myList.Erase(++myList.Begin());
	//myList.Front() = 10;
	myList.Pop_Front();
	myList.Pop_Back();

	MyList::iterator myBeginIter = myList.Begin();
	MyList::iterator myEndIter = myList.End();
	for (; myBeginIter != myEndIter; ++myBeginIter)
	{
		cout << *myBeginIter << endl;
	}
	cout << "--myVec--------" << myList.GetSize() << "-------------------" << endl;
}