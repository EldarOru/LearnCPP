/*
�������� ������� SplitIntoWords, ����������� ������ �� ����� �� ��������.
�������������, ���:
	1) ������ �������;
	2) ������ ������� ���� �� ��������� ���� � ��������;
	3) ������ � ��������� ������� ������ �� �������� ���������;
	4) ������ �� �������� ���� �������� ������.
���������
������������� ��������� ������ ������� ������:
	1) ������ ��������� ������ � ������� ��������� find;
	2) ��������� ��������� ����� � ������� ������������ ������ �� ���� ����������.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(string& str) {
	vector<string> vector;
	auto str_b = str.begin();
	auto str_e = str.end();

	for (auto i = str.begin(); i < str.end(); ++i) {
		if (*i == ' ') {
			vector.push_back({ str_b, i });
			if (i != str.end()) {
				str_b = ++i;
			}
		}
	}

	vector.push_back({ str_b, str.end() });
	return vector;
}

int mainT2() {
	string s = "C++ KOTLIN JAVA JAVASCRIPT";

	vector<string> a = SplitIntoWords(s);

	for (auto i : a) {
		cout << i << endl;
	}
	return 1;
}