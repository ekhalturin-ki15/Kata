#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//Описание тех структур, которые есть в языках программирования

template <typename T>
struct True_Heap
{
	vector<T> v;
	int n;
	True_Heap() = delete;

	True_Heap(const vector<T>& v_) : v{v_}
	{
		v.push_back(0);
		n = v.size();
		swap(v[0], v[n- 1]);
		for (int i = n - 2; i > 0; --i)
		{
			Down(i);
		}
	}

	T Top() { return v[1]; }

	void Pop()
	{
		swap(v[1], v[n - 1]);
		--n;
		v.pop_back();
		Down(1);
	}

	void Push(T q)
	{
		n++;
		v.push_back(q);
		Up(q);
	}

	void Up(int i)
	{
		int l = i >> 1;
		if (l)
		{
			if (v[i] < v[l])
			{
				swap(v[i], v[l]);
				Up(l);
				return;
			}
		}
	}


	void Down(int i)
	{
		int l = (i << 1) + 1;
		int r = (i << 1) + 2;
		if (l >= n) return;
		if ((l == n-1) || (v[l]<v[r]))
			if (v[i] > v[l])
			{
				swap(v[i], v[l]);
				Down(l);
				return;
			}

		if (v[i] > v[r])
		{
			swap(v[i], v[r]);
			Down(r);
			return;
		}
	}



};