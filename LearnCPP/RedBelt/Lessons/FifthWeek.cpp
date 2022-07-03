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

int main() {

	return 1;
}