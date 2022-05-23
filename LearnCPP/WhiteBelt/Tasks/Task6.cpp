/* �������� ������� MoveStrings, ������� ��������� ��� ������� �����, source � destination, � ���������� ��� ������ �� ������� ������� � ����� �������.
 * ����� ���������� ������� ������ source ������ ��������� ������.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void moveStrings(vector<string>& source, vector<string>& destination) {
	for (auto k : source) {
		destination.push_back(k);
	}
	source.clear();
}

// ������� ������������ �����
void printVector2(const vector<string>& data) {
	for (const auto& value : data) {
		cout << value << ", ";
	}
	cout << endl;
}

int mainT6() {
	
	vector<string> firstVector = { "four", "five", "six" };
	vector<string> secondVector = { "one", "two", "three" };
	moveStrings(firstVector, secondVector);
	printVector2(firstVector);
	printVector2(secondVector);

	return 0;
}