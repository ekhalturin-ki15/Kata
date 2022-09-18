#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*��������� ����� 1) ������
��������� ������ 1) Z ������� ������
����������� O(n*log(n))*/
vector<int> True_Z_Function(const string& s);

/*��������� ����� 1) ������
��������� ������ 1) ������� ������� ������
����������� O(n*log(n))*/
vector<int> True_Prefix_Function(const string& s);

/*��������� ����� 1) ������
��������� ������ 1) ���� �������� � ��������� ����� ����������� � ������� ��������
1.1) ��� �������� ������� 1.2) ��� ������
����������� O(n*log(n))*/
pair <vector<int>, vector<int>> True_Manacher(const string& s);