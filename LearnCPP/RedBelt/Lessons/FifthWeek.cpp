#include <iostream>
#include <vector>
#include <string>
#include <future>
#include <string>
#include <numeric>
#include <array>
#include <algorithm>

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

int SumToVectors(const vector<int> v1, const vector<int> v2) {
	future<int> f = async([&v1] {
		return accumulate(begin(v1), end(v1), 0);  
	});
	int result = accumulate(begin(v2), end(v2), 0);
	return result + f.get();
}
//Mutex нужен для синхронизации
//В секции может находиться только один поток

int main() {
	Test test(5);
	Test test1 = move(test);
	test._x = 3;
	cout << test._x << endl;
	cout << test1._x << endl;
	// && это rvalue ссылка. Она позволяет принимать временные объекты
	return 1;
}