/*
* директива #include "file.h" вставляет содержимое файла file.h в место использования (препроцессинг)
* после все вставок полученный большой файл компелируется
* #pragma once защищает от повторного вставления файла, который был уже встроен до этого
* без этого будет ошибка
*/
#include <iostream>
#include "Sum.h"
using namespace std;
//Объявление функции. Может быть сколько угодно
int greatestCommonDivisor(int a, int b);

//Определение функции. Может быть только одно
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
* Без этого объявления вызов bar в функции foo вызвал бы ошибку
* т. к. компилятор читает сверху вниз и он еще не дошел до bar
* но при объявлении функции сначала эта ошибка не произойдет
*/
void bar();

void foo() {
	bar();
}

void bar() {

}

//Объявление класса
class Rectangle {
public:
	Rectangle(int width, int height);

	int Area() const;
	int Perimeter() const;
private:
	int _width;
	int _height;
};

//Определение функций класса
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
* При сборке проекта перекомпилируются только измененные cpp файлы
* Внесение изменений в h файл провоцирует перекомпиляцию все cpp файлов, где он подключен
* Поэтому чтобы это избежать делают определения функций в cpp файлах, а объявление в h
*/