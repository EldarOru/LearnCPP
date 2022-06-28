/*
�������� ������� PrintVectorPart, ����������� ������ ����� ����� numbers,
	����������� ����� ������� �������������� ����� � �� � ��������� � ����������� ����� ��� �����,
	������������� ����� ����������, � �������� �������.
���� ������ �� �������� ������������� �����, �������� ��� ����� � �������� �������.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(vector<int>& v) {
	auto it = find_if(v.begin(), v.end(), [](int x) {
		return x < 0;
		});

	while (it != v.begin()) {
		--it;
		cout << *it << endl;
	}
}

int mainT1() {
	vector <int> v{ 1, 2, 3 , -5, 6, 7 };
	PrintVectorPart(v);
	return 0;
}