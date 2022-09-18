#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*Параметры входа 1) Строка
Параметры выхода 1) Z функция строки
Асимптотика O(n*log(n))*/
vector<int> True_Z_Function(const string& s);

/*Параметры входа 1) Строка
Параметры выхода 1) префикс функция строки
Асимптотика O(n*log(n))*/
vector<int> True_Prefix_Function(const string& s);

/*Параметры входа 1) Строка
Параметры выхода 1) Пара векторов с указанием длины палиндромов в заданых позициях
1.1) Для нечётный позиций 1.2) Для чётных
Асимптотика O(n*log(n))*/
pair <vector<int>, vector<int>> True_Manacher(const string& s);