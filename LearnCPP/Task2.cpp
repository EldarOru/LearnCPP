/*
 * Ќапишите функцию, котора€
 * называетс€ IsPalindrom
 * возвращает bool
 * принимает параметр типа string и возвращает, €вл€етс€ ли переданна€ строка палиндромом
 * ѕалиндром - это слово или фраза, которые одинаково читаютс€ слева направо и справа налево.
 * ѕуста€ строка €вл€етс€ палиндромом.
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