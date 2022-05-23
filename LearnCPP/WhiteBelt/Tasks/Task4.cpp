
/*
 * Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
 * Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.
 * Гарантируется, что среднее арифметическое значений температуры является целым числом.
 *
 * Формат ввода
 * Вводится число N, затем N неотрицательных целых чисел — значения температуры в 0-й, 1-й, ... (N−1)-й день.
 *
 * Формат вывода
 * Первое число K — количество дней, значение температуры в которых выше среднего арифметического.
 * Затем K целых чисел — номера этих дней.
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int mainT4() {
	int daysNumber;
	cin >> daysNumber;
	int averageTemp = 0;
	vector<int> daysTemperature(daysNumber);
	for (int i = 0; i < daysNumber; ++i) {
		int temp;
		cin >> temp;
		averageTemp += temp;
		daysTemperature[i] = temp;
	}
	averageTemp /= daysNumber;

	int count = 0;
	for (int temp = 0; temp < daysNumber; ++temp) {
		if (daysTemperature[temp] > averageTemp) {
			count++;
		}
	}

	cout << count << endl;
	for (int temp = 0; temp < daysNumber; ++temp) {
		if (daysTemperature[temp] > averageTemp) {
			cout << temp << " ";
		}
	
	}
	return 0;
}