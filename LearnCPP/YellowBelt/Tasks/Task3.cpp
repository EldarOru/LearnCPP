/*
�������� ��������� ������� RemoveDuplicates,
	����������� �� ������ ������ elements �������� ���� T � ��������� �� ���� ��� ��������� ���������.
������� ���������� ��������� ����� ���� �����.
�������������, ��� ������� ���� T ����� ���������� � ������� ���������� ==, !=, < � >.
*/

#include "Task3.h";


using namespace std;

int mainT3(){
	vector<int> numbers{ 1, 5, 6, 7, 6, 5 };
	DeleteDuplicates(numbers);
	for (auto i : numbers) {
		cout << i << endl;
	}

	return 1;
}