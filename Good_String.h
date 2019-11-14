#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> True_Z_Function(const string& s);

vector<int> True_Prefix_Function(const string& s);

pair <vector<int>, vector<int>> True_Manacher(const string& s);