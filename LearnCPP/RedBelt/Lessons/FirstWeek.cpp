#include <iostream>
#include <vector>
#include <string>
#include <sstream>

//�������
//�� ����� �������������� ��� ������� ���������� �� �������, ������� ��� ������������ 
#define MY_MAIN int mainR1()
#define FINISH return 1

//������� ����� ���������� ��������� �������� �������� ���������� � string
#define AS_KV(x) #x << " = " << x << endl

#define GIVE_INFO { \
	ostringstream os; \
	os << __FILE__ << endl; \
	os << __LINE__ << endl; \
	cout << os.str(); \
}

using namespace std;

template <typename T, typename V>
struct Pair {
	T first;
	V second;
};

template <typename Iterator>
struct IteratorRange {
	Iterator first, second;

	//����� �� ������� ������ ����� ���� ���������������� � ������� ����� for 
	//�� ������ ����� ������ begin � end
	Iterator begin() const {
		return first;
	}

	Iterator end() const {
		return second;
	}
};

template <typename K>
IteratorRange <typename vector<K>::iterator> Head(
	vector<K>& v, size_t s) {
	return {
		v.begin(), next(v.begin(), min(s, v.size()))
	};
}

MY_MAIN{
	int x = 5;
	string hello = "hello";
	//������� x = 5 � hello = hellp
	cout << AS_KV(x) << ""
		<< AS_KV(hello);
	 
	const string file = __FILE__;
	const int line = __LINE__;

	GIVE_INFO;

	cout << file << " " << line << endl;

	Pair<string, int> p;
	p.first = "hi";
	p.second = 5;

	vector<int> vec = { 1,2,3,4,5,6,7 };

	for (auto i : Head(vec, 3)) {
		cout << i << endl;
	}

	FINISH;
}
