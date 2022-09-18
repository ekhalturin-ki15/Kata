#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*��������� ����� 1)��� �����, �������� ��� �������
1.1)����� ����� ������ ��������
1.2, 1.3) ����� ������ ��������
��������� ������ 1) ��������������� ������������ ��������
(��� �������� ��������� ������� ���������������)
����������� O(1)*/
__int64 True_Pseudoscalar(const pair<__int64, __int64>& t0, const pair<__int64, __int64>& t1, const pair<__int64, __int64>& t2);


/*��������� ����� 1)���������� ������ ��������������
��������� ������ 1) ��������� �������
����������� O(n)*/
__int64 True_Polygon_Area(const vector < pair<__int64, __int64>>& t);


/*��������� ����� 1)���������� ������ ��������������
��������� ������ 1) �������� �������� (���������� ������)
����������� O(n*log(n)) ��� O(n) ���� �������������*/
vector <pair<__int64, __int64>> True_Convex_Hull(vector <pair<__int64, __int64>> t);