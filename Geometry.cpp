#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
#include "Geometry.h"

using namespace std;
#define __int64 long long



__int64 Pseudoscalar(const pair<__int64, __int64>& t0, const pair<__int64, __int64>& t1, const pair<__int64, __int64>& t2)
{
	__int64 answer = 0;
	//--------------------
	__int64 x1 = t1.first - t0.first;
	__int64 x2 = t2.first - t0.first;
	__int64 y1 = t1.second - t0.second;
	__int64 y2 = t2.second - t0.second;
	//--------------------
	return (x1*y2 - x2*y1);
}

__int64 Polygon_Area(const vector < pair<__int64, __int64>>& t)
{
	__int64 answer = 0;
	//--------------------
	for (int i = 0; i<t.size();i++)
	{
		answer += Pseudoscalar({ 0,0 }, t[i], t[(i + 1)% t.size()]);
	}
	//--------------------
	return abs(answer);
}

vector <pair<__int64, __int64>> Convex_Hull(vector <pair<__int64, __int64>> t)
{
	if (t.size() < 3) return t;
	vector<pair<__int64, __int64>> answer;
	//--------------------
	vector<pair<__int64, __int64>> buf;
	sort(t.begin(), t.end());
	int i, n = t.size();
	
	for (i = 1; i < n-1; i++)
	{
		if (Pseudoscalar(t[0], t[i], t.back()) < 0)  buf.push_back(t[i]);
	}
	buf.push_back(t.back());
	for (i = n-2; i >=1; i--)
	{
		if (Pseudoscalar(t[0], t[i], t.back()) > 0)  buf.push_back(t[i]);
	}
	buf.push_back(t[0]);

	answer.push_back(t[0]); answer.push_back(buf[0]);
	for (i = 1; i < buf.size(); i++)
	{
		if (Pseudoscalar(answer[answer.size() - 2], buf[i], answer[answer.size() - 1]) > 0)
		{
			answer.push_back(buf[i]);
		}
		else
		{
			while (true)
			{
				answer.pop_back();
				if (answer.size() < 2) break;
				
				if (Pseudoscalar(answer[answer.size() - 2], buf[i], answer[answer.size() - 1]) > 0) break;
			}
			answer.push_back(buf[i]);
		}
	}
	answer.pop_back();


	//--------------------
	return answer;
}