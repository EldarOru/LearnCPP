#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <string>

using namespace std;

template <class T>
class SimpleVector {
public: 
	explicit SimpleVector(size_t size) {
		data = new T[size];
		end_ = data + size;
	};

	~SimpleVector() {
		delete[] data;
	};

	T& operator[](size_t index) {
		return data[index];
	};

	T* begin() { return data; };
	T* end() { return end_;  };

	const T* begin() const { return data; };
	const T* end() const { return end_; };

private:
	T* data;
	T* end_;
};

//��������� ���������� �������� � �����
int mainR3() {
	int a = 20;
	int b = 40;
	int c = 60;

	//cout << *(&b - 1) << *(&b + 1) << endl;

	//�������� ������ � ����
	int* pInt = new int;

	string* s = new string;
	*s = "Hello";
	cout << *s << " " << s->size() << endl;
	string& ref_to_s = *s;
	ref_to_s += ", world";
	cout << *s << endl;
	//�������� new ������� ������ � ����

	//delete ����������� ������
	delete s;

	//��� �������� � ���� N �������� ���� T ������������ �������� new T[N]
	//��� �� ������������ ������������ �������� delete[]

	SimpleVector<int> sv(5);
	for (int i = 0; i < 5; ++i) {
		sv[i] = 5 - i;
	}

	for (int i = 0; i < 5; ++i) {
		cout << sv[i] << endl;
	}

	for (auto i : sv) {
		cout << i << " ";
	}

	int x = 5;
	int* px = &x;
	const int* cpx = &x; //�� ��������� ������ ������, �� ������� ��������� ���������
	int* const pxc = &x; //�� ��������� ���� ���������, �� ����� ������ ������
	const int* const cpxc = &x; //������ �� ��������� 

	//������� � ����� ������������ ������������� ��� ������ �� ������� ���������
	//������� �� ���� ��������� ������� ����� delete � ����� ������, ��� �������, ��������� ��
	return 1;
}