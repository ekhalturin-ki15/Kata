#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

__int64 Pseudoscalar(const pair<__int64, __int64>& t0, const pair<__int64, __int64>& t1, const pair<__int64, __int64>& t2);

__int64 Polygon_Area(const vector < pair<__int64, __int64>>& t);

vector <pair<__int64, __int64>> Convex_Hull(vector <pair<__int64, __int64>> t);