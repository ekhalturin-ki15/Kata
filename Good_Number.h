#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*Параметры входа 1)Три точки, задающие два вектора
1.1)Общая точка начала векторов
1.2, 1.3) Точки концов векторов
Параметры выхода 1) Псевдоскалярное произведение векторов
(или знаковая удвоенная площадь параллелограмма)
Асимптотика O(log(p))*/
__int64 True_Bin_Pow(const __int64& n, const  __int64& p, const  __int64& mod);