#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

struct Day {
	int value;

	//Explicit говорит, что надо выполн€ть только €вно
	//Ќапример без explicit мы могли бы сделать так - Date date = { {5}, {12} };
	//— ним же только Date date = { Day{5}, Month{12} };
	explicit Day(int new_value) {
		value = new_value;
	}

};

struct Month {
	int value;
	explicit Month(int new_value) {
		value = new_value;
	}

};

struct Date {
	Day day;
	Month month;

};

struct Duration {
	int hour;
	int min;

	Duration(int h = 0, int m = 0) {
		int total = h * 60 + m;
		hour = total / 60;
		min = total % 60;
	}
};

Duration ReadDuration(istream& stream) {
	int m = 0;
	int h = 0;
	stream >> h;
	stream.ignore(1);
	stream >> m;
	return Duration{ h, m };
}

void PrintDuration(ostream& stream, const Duration& duration) {
	stream << setfill('0');
	stream << setw(2) << duration.hour << ":"
		<< setw(2) << duration.min;
}

//ћожно переопредел€ть операторы ввода и вывода
ostream& operator << (ostream& stream, const Duration& duration) {
	stream << setfill('0');
	stream << setw(2) << duration.hour << ":"
		<< setw(2) << duration.min;
	return stream;
}

istream& operator >> (istream& stream, Duration& duration) {
	stream >> duration.hour;
	stream.ignore(1);
	stream >> duration.min;
	return stream;
}

Duration operator + (Duration& dur1, Duration& dur2) {
	return Duration(dur1.hour + dur2.hour, dur1.min + dur2.min);
}

bool operator < (const Duration& dur1, const Duration& dur2) {
	if (dur1.hour == dur2.hour) {
		return dur1.min < dur2.min;
	}
	return dur1.min < dur2.min;
}

int main() {

	Date date = { Day{5}, Month{12} };
	//-----------------------
	ifstream input = ifstream("Test.txt");
	string line;
	while (getline(input, line)) {
		cout << line << endl;
	}

	const string path = "MyData.txt";
	ofstream output(path);
	output << "hello" << endl;

	//ios::app открыть файл в режиме дозаписи
	ofstream moreOutput(path, ios::app);
	output << "world" << endl;

	ifstream moreInput(path);
	if (moreInput) {
		string line;
		while (getline(moreInput, line)) {
			cout << line << endl;
		}
	}

	vector<double> values = { 5, 0.05, 0.00005 };
	vector<string> names = { "a", "b", "c" };

	for (const auto& i : names) {
		cout << setw(10) << i << ' ';
	}

	cout << endl;
	//fixed делает все числа в стандартном формате
	//setprecision ставит максимум цифр после зап€той
	cout << fixed << setprecision(2);
	for (const auto& i : values) {
		//setw делает пробелы
		cout << setw(10) << i << ' ';
	}
	//-----------------
	stringstream dur = stringstream("01:50");
	//Duration dur1 = ReadDuration(dur);
	//PrintDuration(cout, dur1);
	Duration dur1;
	dur >> dur1;
	cout << dur1;

	//одинаковые
	cout << "hello " << "world";
	operator << (operator << (cout, "hello"), "world");
	return 1;
}
