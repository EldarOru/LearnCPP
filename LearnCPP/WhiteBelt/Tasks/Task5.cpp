/*
 * Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:
 *
 * NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...
 * BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
 * STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
 * ALL_BUSES — вывести список всех маршрутов с остановками.
 *
 * Формат ввода
 * В первой строке ввода содержится количество запросов Q, затем в Q строках следуют описания запросов.
 *
 * Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков подчёркивания.
 *
 * Для каждого запроса NEW_BUS bus stop_count stop1 stop2 ... гарантируется, что маршрут bus отсутствует, количество остановок больше 0,
 * а после числа stop_count следует именно такое количество названий остановок, причём все названия в каждом списке различны.
 *
 * Формат вывода
 *
 * Для каждого запроса, кроме NEW_BUS, выведите соответствующий ответ на него:
 *
 * На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов, проезжающих через эту остановку, в том порядке, в котором они создавались командами NEW_BUS.
 * Если остановка stop не существует, выведите No stop.
 *
 * На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в отдельных строках в том порядке, в котором они были заданы в соответствующей команде NEW_BUS.
 * Описание каждой остановки stop должно иметь вид Stop stop: bus1 bus2 ..., где bus1 bus2 ... — список автобусов, проезжающих через остановку stop,
 * в порядке, в котором они создавались командами NEW_BUS, за исключением исходного маршрута bus.
 * Если через остановку stop не проезжает ни один автобус, кроме bus, вместо списка автобусов для неё выведите no interchange.
 * Если маршрут bus не существует, выведите No bus.
 *
 * На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке.
 * Описание каждого маршрута bus должно иметь вид Bus bus: stop1 stop2 ..., где stop1 stop2 ... — список остановок автобуса bus в порядке, в котором они были заданы в соответствующей команде NEW_BUS.
 * Если автобусы отсутствуют, выведите No buses.
 */

#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

void printVector(const vector<string>& data) {
	for (const auto& value : data) {
		cout << value << ", ";
	}
	cout << endl;
}

int mainT5() {
	map<string, vector<string>> listBusesStops, listStopBuses;

	string command;
	
	while (command != "EXIT") {
		cout << "Enter the command" << endl;
		cin >> command;
		if (command == "NEW_BUS") {

			cout << "Enter bus name and count of stops" << endl;
			string busName;
			int stopsCount;
			cin >> busName >> stopsCount;

			cout << "Enter stop name" << endl;
			for (int i = 0; i < stopsCount; ++i) {
				string stopName;
				cin >> stopName;
				listBusesStops[busName].push_back(stopName);
				listStopBuses[stopName].push_back(busName);
			}
		}
		if (command == "BUSES_FOR_STOP") {
			cout << "Enter stop name" << endl;
			string stop;
			vector <string> buses;
			cin >> stop;
			if (listStopBuses.count(stop)) {
				buses = listStopBuses[stop];
			}
			if (!buses.empty()) {
				printVector(buses);
			}
			else {
				cout << "Such stop doesn't exist" << endl;
			}
		}
		if (command == "STOPS_FOR_BUS") {
			cout << "Enter bus name" << endl;
			string bus; 
			cin >> bus;
			if (listBusesStops.count(bus) != 0) {
				vector <string> stops = listBusesStops[bus];
				for (const auto& stop : stops) {
					cout << "Stop - " << stop << " " << endl;
					vector <string>& buses = listStopBuses[stop];
					for (const auto& item : buses) {
						if (item == bus && buses.size() == 1 ) {
							cout << "No other buses";
				
						}
						else if (item != bus) {
							cout << item << " ";
						}
					}
					cout << endl;
				}
			}
			else {
				cout << "No such buses";
			}
		}
		if (command == "ALL_BUSES") {
			if (!listBusesStops.empty()) {
				for (const auto& k : listBusesStops) {
					cout << k.first << " has stops: " << endl;
					printVector(k.second);
				}
			}
			else {
				cout << "No buses" << endl;
			}
		}
	}
	return 0;
}