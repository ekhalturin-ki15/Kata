#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*��������� ����� 1)��������������� ������, 2) ������� �������
��������� ������ 1) ��� ������� �������
1.1)�� ������ ������� ����� x (��� max <=x)
1.2)�� ������ ������� ����� x (��� min >=x)
���������� - ����� �� ��������
����������� O(log(n))*/
pair<int, int> True_Binary_search(const vector<__int64>& mas, __int64 x);