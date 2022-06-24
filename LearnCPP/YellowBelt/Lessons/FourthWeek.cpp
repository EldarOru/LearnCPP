#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <set>
#include <tuple>
#include <utility>
#include <ostream>

using namespace std;


using LangIt = vector<string>::iterator;

template <class T>
void PrintRange(T range_begin,
	T range_end) {
	for (auto it = range_begin;
		it != range_end; ++it) {
		cout << *it << endl;
	}

}

int mainY4() {
	vector<string> langs = {"Kotlin", "C++", "C", "Java"};
	auto result = find_if(begin(langs),
		end(langs),
		[](const string& lang) {
			return lang[0] == 'C';
		});

	//string& ref = *result;

	//изменили ссылку в самом векторе langs с C++ на D++
	//ref = "D++";
	//cout << ref << endl;

	for (auto i : langs) {
		cout << i << endl;
	}
	PrintRange(begin(langs), end(langs));

	//не удаляет, а по сути переставляет элементы
	auto it = remove_if(begin(langs),
		end(langs),
		[](const string& lang) {
			return lang[0] == 'C';
		});
	
	//удаляем все значения, начинающиеся с 'C'
	langs.erase(it, end(langs));
	PrintRange(begin(langs), end(langs));

	auto p = minmax_element(begin(langs), end(langs));
	//к итератору p можно обращаться только через *
	cout << *p.first << " " << *p.second << endl;

	auto m = partition(begin(langs),
		end(langs),
		[](const string& lang) {
			return lang[0] == 'C';
		});
	PrintRange(begin(langs), m);

	vector <string> c_langs;
	copy_if(begin(langs), end(langs), back_inserter(c_langs),
		[](const string& lang) {
			return lang[0] == 'C';
		});
	PrintRange(begin(c_langs), end(c_langs));

	set<int> numbers = { 1, 3 ,5 ,7 };
	auto it3 = numbers.find(3);
	PrintRange(next(it3), end(numbers));
	return 1;
}