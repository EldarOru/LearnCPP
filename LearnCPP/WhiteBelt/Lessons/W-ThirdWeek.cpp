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
	//Тернарный оператор
	string parity = (x % 2 == 0) ? "ever" : "odd";
	cout << x << " is " << parity;
}

//Структура это просто набор полей
struct Lecture {
	string title;
	int duration;
	string author;
};

class Route {
public: 
	//Без const функция PrintRoute не вызовется т. к. мы передаем const Route  
	//Методы могут быть константными - не изменять объект, в контексте которого вызваны
	//При константной ссылке на объект можно вызвать только константные методы
	//При неконстатной ссылке можно выбрать любой метод
	
	//КОНСТРУКТОР ПО-УМОЛЧАНИЮ
	Route() {
		SetSource("Moscow");
		SetDestination("Saint-Petersburg");
	}

	Route(const string& new_source, const string& new_destination) {
		source = new_source;
		destination = new_destination;
	}

	//ДЕСТРУКТОР, вызывается при уничтожении объекта
	//Когда выходим за границу видимости объекта, то уничтожаем его
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
	//Третий аргумент это лямбда выражение
	cout << count_if(begin(numbers), end(numbers), [thr](int x) {
		if (x > thr) {
			return true;
		};
		return false;
		}) << endl;
	//Надо стараться минимизировать область видимости переменной

	//Значение неинициализированной переменной неопределено
	int number;

	Lecture lecture = { "CPP GUIDE", 322, "ELDAR" };

	Route route = Route("Paris", "London");
	Route route1("Paris", "London");
	PrintRoute(Route("k", "m"));
	PrintRoute(Route());
	PrintRoute({});
	return 1;
}

