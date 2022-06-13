#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct Person {
	string name;
	string surname;
	int age;
};

int Sum(int x, int y) {
	return x + y;
}

void PrintWords(vector<string> words) {
	for (auto w : words) {
		cout << w << " ";
	}
}

//��������� ������, ��� ��������� ����� ������������ �� ������ � ������ ��� ����� ����� ��������������
void Swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void Sort(vector<int>& v) {
	sort(begin(v), end(v));
}

/*
* ���� �� ��������� �������� ������ � ������� �� ��������, 
* �� ��-�� ��������� ����������� ��� ����� ������ ����� �������.
* ����� ������ ��� �������� ���� ���������� ������
* ����� �� �� ����� � �������� ������� �������� ��������� ������ ������ �������
* �� �� ����� ������� ����������� ������, ������� ������ ����� ��������������
*/
void PrintGiantVectorSize(const vector<Person>& vec) {
	cout << "Size is " << vec.size() << endl;
}

int mainW2() {
	//��������� ������� ���������� �� ��������
	int x, y;
	cin >> x >> y;
	cout << Sum(x, y) << endl;

	PrintWords({ "Hello", "World", "!" });

	//�������� x � y, ������� ���� ����, ���������� ��-�� ������������� ����������.
	//� ���� ������ ��� �������� �� ��������
	Swap(x, y);
	cout << x << " " << y << endl;

	vector<int> v = { 1,4,2,6,3 };
	Sort(v);
	for (auto num : v) {
		cout << num << " ";
	}

	//��� ��������� ������
	int n;
	cin >> n;
	vector<string> myVector(n);
	for (string& n : myVector) {
		cin >> n;
	}
	PrintWords(myVector);

	vector<string> myVector2(n, "Default");

	//�������� ������ �������
	myVector2.resize(20);

	//�������� ������ ������� � ������ ��� �������� �� ���������
	myVector2.assign(20, "New default");

	vector<string> numberVector = { "one", "two", "three" };
	map<char, vector<string>> myMap;

	for (const string& n : numberVector) {
		myMap[n[0]].push_back(n);
	}

	for (const auto& item : myMap) {
		cout << item.first << endl;
		for (const string& word : item.second) {
			cout << word << " ";
		}
		cout << endl;
	}
	return 0;
}

