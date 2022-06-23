#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cassert>
#include <set>

using namespace std;

using Synonyms = map<string, set<string>>;

int Sm(int x, int y) {
	return x + y;
}

template <class T, class V>
void AssertEqual(const T& t, const V& v, const string& hint) {
	if (t != v) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << v << " Hint: " << hint;
		throw runtime_error(os.str());
	}
}

void TestSum() {
	AssertEqual(Sm(2, 3), 5, "s");
	AssertEqual(Sm(-2, -3),-5, "s");
	AssertEqual(Sm(-2, 0), -2, "s");
	AssertEqual(Sm(2, -2), 0, "s");
	cout << "Test sum OK" << endl;
}


template <class TestFunc>
void RunTest(TestFunc func, const string& test_name) {
	try {
		func();
		cerr << test_name << " OK";
	}
	catch (runtime_error& e) {
		cerr << test_name << " failed: " << e.what << endl;
 	}
}


int mainY2() {
	TestSum();
	//RunTest(TestSum, "TestSum");
	return 1;
}