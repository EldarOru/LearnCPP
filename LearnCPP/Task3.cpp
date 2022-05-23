/*
 * �������� ������� UpdateIfGreater, ������� ��������� ��� ������������� ���������: first � second.
 * ���� first �������� ������ second, ���� ������� ������ ���������� � second �������� ��������� first.
 * ��� ���� ��������� ��������� second ������ ���� ����� �� ���������� �������.
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