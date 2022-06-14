#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

void Print(const vector<int>& words) {
	for (auto w : words) {
		cout << w << " ";
	}
	cout << endl;
}

void PrintParity(int x) {
	//��������� ��������
	string parity = (x % 2 == 0) ? "ever" : "odd";
	cout << x << " is " << parity;
}

//��������� ��� ������ ����� �����
struct Lecture {
	string title;
	int duration;
	string author;
};

class Route {
public: 
	//��� const ������� PrintRoute �� ��������� �. �. �� �������� const Route  
	//������ ����� ���� ������������ - �� �������� ������, � ��������� �������� �������
	//��� ����������� ������ �� ������ ����� ������� ������ ����������� ������
	//��� ������������ ������ ����� ������� ����� �����
	
	//����������� ��-���������
	Route() {
		SetSource("Moscow");
		SetDestination("Saint-Petersburg");
	}

	Route(const string& new_source, const string& new_destination) {
		source = new_source;
		destination = new_destination;
	}

	//����������, ���������� ��� ����������� �������
	//����� ������� �� ������� ��������� �������, �� ���������� ���
	~Route() {

	}

	string GetSource() const { return source; }
	string GetDestination() const { return destination; }
	int GetLength() const { return length; }

	void SetSource(const string& new_source) {
		source = new_source;
	}
	void SetDestination(const string& new_destination) {
		source = new_destination;
	}

private: 
	string source;
	string destination;
	int length;
};

void PrintRoute(const Route& route) {
	cout << route.GetSource() << " - " << route.GetDestination();
}
int mainW3() {
	vector<int>numbers = { 1,5,4,2,3,2 };
	sort(begin(numbers), end(numbers));
	Print(numbers);
	cout << count(begin(numbers), end(numbers), 2) << endl;

	int thr = 0;
	cin >> thr;
	//������ �������� ��� ������ ���������
	cout << count_if(begin(numbers), end(numbers), [thr](int x) {
		if (x > thr) {
			return true;
		};
		return false;
		}) << endl;
	//���� ��������� �������������� ������� ��������� ����������

	//�������� �������������������� ���������� ������������
	int number;

	Lecture lecture = { "CPP GUIDE", 322, "ELDAR" };

	Route route = Route("Paris", "London");
	Route route1("Paris", "London");
	PrintRoute(Route("k", "m"));
	PrintRoute(Route());
	PrintRoute({});
	return 1;
}

