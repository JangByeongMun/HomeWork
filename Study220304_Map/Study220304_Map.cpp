#include <iostream>
#include <map>
#include "MyMap.h"

using namespace std;

int main()
{
	MyMap myMap;
	MyPair myPair = Make_Pair(0, 1);
	myPair.first_ = 10;
	myPair.second_ = 5;
	myMap.Insert(myPair);
	myMap.Insert(Make_Pair(10, 10));
	myMap.Insert(Make_Pair(10, 2));
	myMap.Insert(Make_Pair(5, 1));
	myMap.Insert(Make_Pair(8, 1));
	myMap.Insert(Make_Pair(3, 1));
	myMap.Insert(Make_Pair(1, 1));
	myMap.Insert(Make_Pair(4, 1));
	myMap.Insert(Make_Pair(6, 1));
	myMap.Insert(Make_Pair(7, 1));
	myMap.Insert(Make_Pair(20, 1));
	myMap.Insert(Make_Pair(25, 1));
	myMap.Insert(Make_Pair(17, 1));
	cout << "----myMap----" << myMap.Size() << "-------------------" << endl;

	cout << "전위 순회" << std::endl;
	myMap.FirstOrder(); // 전위순회
	cout << "-------------------" << endl;

	cout << "중위 순회" << std::endl;
	myMap.MidOrder(); // 중위순회
	cout << "-------------------" << endl;

	cout << "후위 순회" << std::endl;
	myMap.LastOrder(); // 후위순회
	cout << "-------------------" << endl;

	MyMap::iterator beginIter = myMap.Begin();
	MyMap::iterator endIter = myMap.End();
	for (; beginIter != endIter; ++beginIter)
	{
		cout << (*beginIter).GetPair()->first_ << ": Test" << endl;
	}

	int a = 0;
}