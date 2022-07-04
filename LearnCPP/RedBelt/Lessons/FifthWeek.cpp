#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <string>
#include <deque>
#include <array>

using namespace std;

vector<string> SplitIntoWords(const string& str) {
	vector<string> words;
	string currentWord;
	for (const char c : str) {
		if (c == ' ') {
			words.push_back(move(currentWord));
			currentWord.clear();
		}
		else {
			currentWord.push_back(c);
		}
	}
	words.push_back(currentWord);
	return words;
}

class Test {
public:
	Test(int x) { 
		_x = x;
		cout << "Constructor" << endl; };
	//Объект запрещено копировать и можно только перемещать
	Test(const Test&) = delete;
	Test(Test&&) { cout << "Move" << endl; };
	int _x;
};

int main() {
	Test test(5);
	Test test1 = move(test);
	test._x = 3;
	cout << test._x << endl;
	cout << test1._x << endl;
	// && это rvalue ссылка. Она позволяет принимать временные объекты
	return 1;
}