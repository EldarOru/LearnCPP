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

using namespace std;

struct Date {
	int year;
	string month;
	int day;
};

bool operator < (Date& d1, Date& d2) {
	//Кортежи
	tuple<const int&, const string&, const int&> t1 = { d1.year, d1.month, d1.day };
	auto t2 = tie( d2.year, d2.month, d2.day ); //tie делает кортеж из ссылок, а make_tuple кортеж из значений
	cout << get<1>(t2) << endl;
	return t1 < t2;
}

tuple <bool, string> someFunction() {
	return { true, "hello" };
}

//Шаблоны или просто дженерик
template <typename T>
T Sqr(T x) {
	return x * x;
}

template <typename First, typename Second> 
pair <First, Second> operator * (pair <First, Second> one, pair <First, Second> two) {
	First first = one.first * two.first;
	Second second = one.second * two.second;
	return make_pair(first, second);
}


template <typename First, typename Second>
ostream& operator << (ostream& stream, pair <First, Second> one) {
	stream << one.first << " " << one.second;
	return stream;
}

template <typename Collection>
string join(const Collection& c, char d) {
	stringstream str;
	bool first = true;
	for (const auto& : c) {
		if (!first) {
			ss << d;
		}
		first = false;
		ss << i;
	}

	return str.str();
}

template <typename T>
ostream& operator << (ostream& stream, vector <T> one) {
	return stream << '(' << join(one, ',') << ')';
}

int main() {
	cout << numeric_limits<int>::max();
	int x = 2'000'000'000;
	unsigned int y = x;

	//При приведении типо будет всегда приводится к большему типу и к безнаковому, если такой есть в выражении
	cout << (-1 < 1u) << endl;

	vector<int> nums = { 5,3,2 };
	//size имеет беззнаковый тип, поэтому если i вдруг окажется отрицательной, то при сравнении могут быть проблемы
	//чтобы этого избежать делаем статик каст к знаковому типу
	for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
		cout << i << " - " << nums[i] << endl  ;
	}

	for (size_t k = nums.size();
		k > 0;
		--k) {
		size_t i = k - 1;
		cout << nums[i] << endl;
	}
	
	bool success;
	string str;
	tie(success, str) = someFunction();

	auto firstPair = make_pair(2, 1.5);
	cout << Sqr(firstPair) << endl;

	return 1;
}