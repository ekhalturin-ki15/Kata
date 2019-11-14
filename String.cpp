#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
#include "String.h"

using namespace std;

vector<int> Z_Function(const string& s)
{
	int i;
	int l = 0, r = 1;// [l,r)
	int n = s.size();
	vector<int> answer(n);
	
	for (i = 1; i < n; i++)
	{
		if (i < r) answer[i] = min(r - i, answer[i - l]);

		while (i + answer[i] < n)
		{
			if (s[i + answer[i]] != s[answer[i]]) break;
			++answer[i];
		}

		if (i + answer[i] > r)
		{
			l = i;
			r = i + answer[i];
		}
	}

	return answer;
}


vector<int> Prefix_Function(const string & s)
{
	vector<int> answer;
	
	return answer;
}

pair <vector<int>, vector<int>> Manacher(const string & s)
{
	vector<int> answer[2];



	return make_pair(answer[0], answer[1]);
}