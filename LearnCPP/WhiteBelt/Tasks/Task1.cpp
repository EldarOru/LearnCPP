/*
* Вывести количество уникальных значений слов, записанных пользователем
* 
*/
#include <set>
#include <iostream>

using namespace std;

int mainT1() {
	int n;
	cin >> n;
	set<string> mySet;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		mySet.insert(str);
	}
	cout << mySet.size();

	return 0;
}