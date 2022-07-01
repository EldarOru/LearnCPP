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

//Локальные переменные хранятся в стеке
int mainR3() {
	int a = 20;
	int b = 40;
	int c = 60;

	//cout << *(&b - 1) << *(&b + 1) << endl;

	//Выделяем память в куче
	int* pInt = new int;

	string* s = new string;
	*s = "Hello";
	cout << *s << " " << s->size() << endl;
	string& ref_to_s = *s;
	ref_to_s += ", world";
	cout << *s << endl;
	//Оператор new создает объект в куче

	//delete освобождает память
	delete s;

	//Для создания в куче N объектов типа T используется оператор new T[N]
	//Для их освобождения используется оператор delete[]

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
	const int* cpx = &x; //не позволяет менять объект, на который указывает указатель
	int* const pxc = &x; //не позволяет меня указатель, но можем менять объект
	const int* const cpxc = &x; //ничего не позволяет 

	//Объекты в стеке уничтожаются автоматически при выходе из области видимости
	//Объекты из кучи удалаются вручную через delete и живут дольше, чем функция, создавшая их
	return 1;
}