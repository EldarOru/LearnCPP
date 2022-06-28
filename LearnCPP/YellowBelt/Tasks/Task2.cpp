/*
Напишите функцию SplitIntoWords, разбивающую строку на слова по пробелам.
Гарантируется, что:
	1) строка непуста;
	2) строка состоит лишь из латинских букв и пробелов;
	3) первый и последний символы строки не являются пробелами;
	4) строка не содержит двух пробелов подряд.
Подсказка
Рекомендуется следующий способ решения задачи:
	1) искать очередной пробел с помощью алгоритма find;
	2) создавать очередное слово с помощью конструктора строки по двум итераторам.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(string& str) {
	vector<string> vector;
	auto str_b = str.begin();
	auto str_e = str.end();

	for (auto i = str.begin(); i < str.end(); ++i) {
		if (*i == ' ') {
			vector.push_back({ str_b, i });
			if (i != str.end()) {
				str_b = ++i;
			}
		}
	}

	vector.push_back({ str_b, str.end() });
	return vector;
}

int mainT2() {
	string s = "C++ KOTLIN JAVA JAVASCRIPT";

	vector<string> a = SplitIntoWords(s);

	for (auto i : a) {
		cout << i << endl;
	}
	return 1;
}