#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*Параметры входа 1)Отсортированный массив, 2) Искомый элемент
Параметры выхода 1) Два индекса массива
1.1)От какого индекса равно x (или max <=x)
1.2)До какого индекса равно x (или min >=x)
Исключение - выход за диапазон
Асимптотика O(log(n))*/
pair<int, int> True_Binary_search(const vector<__int64>& mas, __int64 x);