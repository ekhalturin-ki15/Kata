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
Асимптотика O(1)*/
__int64 True_Pseudoscalar(const pair<__int64, __int64>& t0, const pair<__int64, __int64>& t1, const pair<__int64, __int64>& t2);


/*Параметры входа 1)Координаты вершин многоугольника
Параметры выхода 1) Удвоенная площадь
Асимптотика O(n)*/
__int64 True_Polygon_Area(const vector < pair<__int64, __int64>>& t);


/*Параметры входа 1)Координаты вершин многоугольника
Параметры выхода 1) Выпуклая оболочка (координаты вершин)
Асимптотика O(n*log(n)) или O(n) если отсортированы*/
vector <pair<__int64, __int64>> True_Convex_Hull(vector <pair<__int64, __int64>> t);