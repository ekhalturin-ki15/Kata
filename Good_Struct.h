#pragma once

#include <functional>
#include <iostream>

using namespace std;

struct dat
{
	__int64 el;

	//-----   Изменения   --------
	__int64 change_add = 0; //Прибавка
	bool dead_end = false; //Проверка на лист

	friend ostream& operator<<(ostream& is, const dat& l);
};


//Дерево отрезков
//Проверено на http://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=20&id_topic=47&id_problem=608
struct DO
{

private:
	vector<dat> mas; //Само дерево
	vector<__int64> v; //Исходный
	int l, r, n, x;
	function<dat(dat, dat)> fun;//Операция

public:
	void create(vector<__int64>& _v, function<dat(dat, dat)> _fun);

	void update_add(int _l, int _r, int _x);

	dat get(int _l, int _r);

private:
	void create_rec(int ii, int l, int r);

	void update_add_rec(int ii, int ll, int rr);

	dat get_rec(int ii, int ll, int rr);

};