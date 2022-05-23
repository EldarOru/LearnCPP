/*
 * �������� �������, �������
 * ���������� IsPalindrom
 * ���������� bool
 * ��������� �������� ���� string � ����������, �������� �� ���������� ������ �����������
 * ��������� - ��� ����� ��� �����, ������� ��������� �������� ����� ������� � ������ ������.
 * ������ ������ �������� �����������.
 */

#include <set>
#include <iostream>

using namespace std;

bool isPalindrom(string str) {

	for (int k = 0; k < str.size(); ++k) {
		if (str[k] != str[str.size() - k - 1]) {
			return false;
		}
		return true;
	}

}

int mainT2() {

	string myWord;
	cin >> myWord;

	cout << isPalindrom(myWord);
	return 0;
}