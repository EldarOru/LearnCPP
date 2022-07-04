#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <string>
#include <deque>
#include <array>

using namespace std;

int mainR4() {
	deque<int> d = { 1 };
	auto it = begin(d);

	cout << *it << endl;

	for (int i = 0; i < 200; ++i) {
		d.push_back(i);
	}
	cout << *it << endl;

	//Выведится ошибка т. к. итератор не знает про новые добавления в деке
	//cout << *(it + d.size() - 1) << endl;

	array<int, 5> arr;
	arr.fill(5);
	//Array хранит информацию в стеке
	//Почитать про string_view
	return 1;
}