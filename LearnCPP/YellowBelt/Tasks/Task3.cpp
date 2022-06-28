/*
Напишите шаблонную функцию RemoveDuplicates,
	принимающую по ссылке вектор elements объектов типа T и удаляющую из него все дубликаты элементов.
Порядок оставшихся элементов может быть любым.
Гарантируется, что объекты типа T можно сравнивать с помощью операторов ==, !=, < и >.
*/

#include "Task3.h";


using namespace std;

int mainT3(){
	vector<int> numbers{ 1, 5, 6, 7, 6, 5 };
	DeleteDuplicates(numbers);
	for (auto i : numbers) {
		cout << i << endl;
	}

	return 1;
}