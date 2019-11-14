#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
#include "Good_String.h"

using namespace std;

vector<int> True_Z_Function(const string& s)
{
	int i;
	int l = 0, r = 1;// [l,r)
	int n = s.size();

	vector<int> answer(n);
	for (i = 1; i < n; ++i)
	{
		if (i < r)
			answer[i] = min(r - i, answer[i - l]);

		while (answer[i] + i < n)	
		{
			if (s[answer[i]] != s[answer[i] + i]) break;
			++answer[i];			
		}
		if (r < i + answer[i])
		{
			l = i;
			r = i + answer[i];
		}		
	}

	return answer;
}


vector<int> True_Prefix_Function(const string& s)
{
	int i, n = s.size();
	vector<int> answer(n);
	for (i = 1; i < n; i++)
	{
		answer[i] = answer[i - 1];
		while (answer[i]>0)	
		{
			if (s[answer[i]] == s[i])
				break;
			answer[i] = answer[answer[i] - 1];
		}
		if (s[answer[i]] == s[i])	++answer[i];
	}
	return answer;
}

pair <vector<int>, vector<int>> True_Manacher(const string& s)
{
	
	int l, r, i, n = s.size();
	vector<int> answer[2];

	//Для нечётных (0)  //Для чётных (1)
	for (int parity = 0; parity < 2; ++parity)
	{
		answer[parity].resize(n);
		for (l = r = i = 0; i < n; i++)
		{
			if (i < r)
				answer[parity][i] = min(answer[parity][r - i + l], r - i);

			while (i - answer[parity][i] >= 0 && i + answer[parity][i] + parity < n)
			{
				if (s[i - answer[parity][i]] != s[i + answer[parity][i] + parity]) break;
				++answer[parity][i];
			}

			if (i + answer[parity][i] > r)
			{
				r = i + answer[parity][i];
				l = i - answer[parity][i];
			}
		}
	}

	return make_pair(answer[0], answer[1]);
}