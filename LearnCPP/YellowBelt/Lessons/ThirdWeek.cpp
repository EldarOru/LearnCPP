/*
* ��������� #include "file.h" ��������� ���������� ����� file.h � ����� ������������� (�������������)
* ����� ��� ������� ���������� ������� ���� �������������
* #pragma once �������� �� ���������� ���������� �����, ������� ��� ��� ������� �� �����
* ��� ����� ����� ������
*/
#include <iostream>
#include "Sum.h"
using namespace std;
//���������� �������. ����� ���� ������� ������
int greatestCommonDivisor(int a, int b);

//����������� �������. ����� ���� ������ ����
int greatestCommonDivisor(int a, int b) {
	while (a > 0 && b > 0) {
		if (a > b) {
			a %= b;
		}
		else b %= a;
	}
	return a + b;
}

/* 
* ��� ����� ���������� ����� bar � ������� foo ������ �� ������
* �. �. ���������� ������ ������ ���� � �� ��� �� ����� �� bar
* �� ��� ���������� ������� ������� ��� ������ �� ����������
*/
void bar();

void foo() {
	bar();
}

void bar() {

}

//���������� ������
class Rectangle {
public:
	Rectangle(int width, int height);

	int Area() const;
	int Perimeter() const;
private:
	int _width;
	int _height;
};

//����������� ������� ������
Rectangle::Rectangle(int w, int h) {
	_width = w;
	_height = h;
}

int Rectangle::Area() const {
	return _width * _height;
}

int Rectangle::Perimeter() const {
	return 2 * (_width * _height);
}

int mainY3() {
	int c = SumMore(5, 3);
	cout << c << endl;
	return 1;
}

/*
* file1.h ----> file1.cpp -----> file1.o -----> executable
*											    |
* file2.h ----> file2.cpp -----> file2.o -------|
* file3.h ------|
*/

/*
* ��� ������ ������� ����������������� ������ ���������� cpp �����
* �������� ��������� � h ���� ����������� �������������� ��� cpp ������, ��� �� ���������
* ������� ����� ��� �������� ������ ����������� ������� � cpp ������, � ���������� � h
*/