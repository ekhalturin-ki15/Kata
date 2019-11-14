#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
#include "Good_Geometry.h"

using namespace std;

__int64 True_Pseudoscalar(const pair<__int64, __int64>& t0, const pair<__int64, __int64>& t1, const pair<__int64, __int64>& t2)
{
	__int64 x1 = t1.first - t0.first;
	__int64 x2 = t2.first - t0.first;
	__int64 y1 = t1.second - t0.second;
	__int64 y2 = t2.second - t0.second;
	return x1 * y2 - x2 * y1;
}


__int64 True_Polygon_Area(const vector < pair<__int64, __int64>>& t)
{
	__int64 answer = 0;
	int i, n = t.size();
	for (int i = 0; i < n; i++)
		answer += True_Pseudoscalar({ 0,0 }, t[i], t[(i + 1) % n]);
	return abs(answer);
}

vector <pair<__int64, __int64>> True_Convex_Hull(vector <pair<__int64, __int64>> t)
{
	sort(t.begin(), t.end());
	if (t.size() <= 2) return t;

	vector<pair<__int64, __int64>> bypass;
	vector<pair<__int64, __int64>> answer;
	int  i;
	

	bypass.push_back(t[0]);
	for (i = 1; i <= t.size() -2; i++)
	{
		if (True_Pseudoscalar(t[0], t.back(), t[i]) > 0) bypass.push_back(t[i]);
	}
	bypass.push_back(t.back());

	for (i = t.size() - 2; i >= 1; i--)
	{
		if (True_Pseudoscalar(t[0], t.back(), t[i]) < 0) bypass.push_back(t[i]);
	}
	bypass.push_back(t[0]);
	//Обошли по часовой и замкнули

	answer.push_back(bypass[0]);
	answer.push_back(bypass[1]);
	for (i = 2; i < bypass.size(); i++)
	{
		if (True_Pseudoscalar(answer.back(), answer[answer.size() - 2], bypass[i]) > 0)
			answer.push_back(bypass[i]);
		else
		{
			while (true)
			{
				answer.pop_back();
				if (answer.size() < 2) break;
				if (True_Pseudoscalar(answer.back(), answer[answer.size() - 2], bypass[i]) > 0)
					break;

			}
			answer.push_back(bypass[i]);
		}

	}
	answer.pop_back();
	return answer;
}
