/*
 * ���������� ������� �������� ���������� ���������. ��� ����� ������������ ��������� �������:
 *
 * NEW_BUS bus stop_count stop1 stop2 ... � �������� ������� �������� � ��������� bus � stop_count ����������� � ���������� stop1, stop2, ...
 * BUSES_FOR_STOP stop � ������� �������� ���� ��������� ��������, ���������� ����� ��������� stop.
 * STOPS_FOR_BUS bus � ������� �������� ���� ��������� �������� bus �� ������� ���������, �� ������� ����� ��������� �� ������ �� ���������.
 * ALL_BUSES � ������� ������ ���� ��������� � �����������.
 *
 * ������ �����
 * � ������ ������ ����� ���������� ���������� �������� Q, ����� � Q ������� ������� �������� ��������.
 *
 * �������������, ��� ��� �������� ��������� � ��������� ������� ���� �� ��������� ����, ���� � ������ �������������.
 *
 * ��� ������� ������� NEW_BUS bus stop_count stop1 stop2 ... �������������, ��� ������� bus �����������, ���������� ��������� ������ 0,
 * � ����� ����� stop_count ������� ������ ����� ���������� �������� ���������, ������ ��� �������� � ������ ������ ��������.
 *
 * ������ ������
 *
 * ��� ������� �������, ����� NEW_BUS, �������� ��������������� ����� �� ����:
 *
 * �� ������ BUSES_FOR_STOP stop �������� ����� ������ ������ ���������, ����������� ����� ��� ���������, � ��� �������, � ������� ��� ����������� ��������� NEW_BUS.
 * ���� ��������� stop �� ����������, �������� No stop.
 *
 * �� ������ STOPS_FOR_BUS bus �������� �������� ��������� �������� bus � ��������� ������� � ��� �������, � ������� ��� ���� ������ � ��������������� ������� NEW_BUS.
 * �������� ������ ��������� stop ������ ����� ��� Stop stop: bus1 bus2 ..., ��� bus1 bus2 ... � ������ ���������, ����������� ����� ��������� stop,
 * � �������, � ������� ��� ����������� ��������� NEW_BUS, �� ����������� ��������� �������� bus.
 * ���� ����� ��������� stop �� ��������� �� ���� �������, ����� bus, ������ ������ ��������� ��� �� �������� no interchange.
 * ���� ������� bus �� ����������, �������� No bus.
 *
 * �� ������ ALL_BUSES �������� �������� ���� ��������� � ���������� �������.
 * �������� ������� �������� bus ������ ����� ��� Bus bus: stop1 stop2 ..., ��� stop1 stop2 ... � ������ ��������� �������� bus � �������, � ������� ��� ���� ������ � ��������������� ������� NEW_BUS.
 * ���� �������� �����������, �������� No buses.
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