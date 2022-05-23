/*
 * Напишите функцию UpdateIfGreater, которая принимает два целочисленных аргумента: first и second.
 * Если first оказался больше second, Ваша функция должна записывать в second значение параметра first.
 * При этом изменение параметра second должно быть видно на вызывающей стороне.
 */

#include <set>
#include <iostream>

using namespace std;

void updateIfGreater(const int& first, int& second) {
	if (first > second) {
		second = first;
	}
}

int mainT3() {
	int a, b;
	cin >> a >> b;
	updateIfGreater(a, b);
	cout << "Now first is " << a << endl;
	cout << "And second is " << b << endl;
	return 0;
}