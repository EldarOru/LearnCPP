/* На вход дано целое положительное число N.
 * Выведите его в двоичной системе счисления без ведущих нулей.
 */

#include <iostream>
#include <vector>

using namespace std;

int mainT7() {
	int number;
	cin >> number;
	vector<int> answer;
	while (number != 0) {
		answer.push_back(number % 2);
		number /= 2;
	}

	for (int i = answer.size() - 1; i >= 0; --i) {
		cout << answer[i];
	}
	return 0;
}