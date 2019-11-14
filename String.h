#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Z_Function(const string& s);

vector<int> Prefix_Function(const string& s);

pair <vector<int>, vector<int>> Manacher(const string& s);