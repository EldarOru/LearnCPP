#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <class T>
void DeleteDuplicates(vector<T>& v) {
	sort(v.begin(), v.end());
	auto it = unique(v.begin(), v.end());
	v.erase(it, v.end());
}