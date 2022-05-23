#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct CustomPerson {
	string name;
	string surname;

};

int mainW1() {
	//cout << "Hello world";

	// types
	
	int x = 5;
	string hi = "string";
	vector<int> nums = { 1, 3, 5, 7 };
	CustomPerson customPerson = CustomPerson{ "hi", "hey" };
	customPerson.name;
	map<string, int> myMap;
	myMap["one"] = 1;
	

	//cycles
	
	string s = "abcdefg";
	for (char c : s) {
		cout << c << ", ";
	};

	vector<int> mynums = {1,2,3,4,5,6};
	for (auto c :mynums) {
		cout << c << ", ";
	};

	int quantity = count(begin(mynums), end(mynums), 5);
	cout << quantity << ", ";

	sort(begin(mynums), end(mynums));

	for (int i = 0; i < 10; ++i) {
		cout << i;
	}
	
	//input and output 

	string name;
	cin >> name;
	cout << "Hello, " << name;
	return 0;

	//¬ —++ присваивание осуществл€етс€ не через ссылку, а через глубокое копирование
}


