#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <string>

using namespace std::chrono;
using namespace std;

#define UNIQ_ID_IMPL(lineno) _a_local_var##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) \
	LogTime UNIQ_ID(__LINE__) {message};

class LogTime {
public:
	explicit LogTime(const string& msg = "") : log_name(msg), start(steady_clock::now()) {

	}

	~LogTime() {
		auto finish = steady_clock::now();
		auto dur = finish - start;
		cerr << duration_cast<milliseconds>(dur).count() << " ms" << endl;

	}

private:
	string log_name;
	steady_clock::time_point start;
};

int mainR2() {
	LOG_DURATION("BASE");

	float some = 391; // ������� ����������
	float* u = &some; // ��������� �� ����������
	*u = 98; // ��������� �������� ����������
	cout << *u << endl;
	cout << some << endl;
	return 1;
}

//ofstream ������ ����� ���������� ������ � ��� ���������� ���������� �� ��� � ����
//��� endl ������ ��� ����� ������������ ����� � ����� ��������� � �����, ��-�� ���� ����� ���������� 

//�� ��������� ������ cout � cerr ������� � cin
//����� ������ ��������� ����� �� ������ ������������