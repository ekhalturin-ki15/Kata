#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
#include "Array.h"

using namespace std;
#define __int64 long long

pair<int, int> Binary_search(const vector<__int64>& mas, __int64 x)
{
	pair<int, int> answer;
	//--------------------

	int n = mas.size();
	int m, l = -1, r = n- 1;
	while (r - l > 1)
	{
		m = (r + l) / 2;
		if (mas[m] >= x) r = m;
		else l = m;
	}
	answer.first = r;
	l = 0; r = n;
	while (r - l > 1)
	{
		m = (r + l) / 2;
		if (mas[m] > x) r = m;
		else l = m;
	}
	answer.second = l;
	if (mas[l] != x) swap(answer.first, answer.second);
	//--------------------
	return answer;
}