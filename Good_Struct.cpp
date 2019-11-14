#include "Good_Struct.h"

ostream& operator<<(ostream& is, const dat& l)
{
	is << l.el << " ";
	return is;
}

void DO::create(vector<__int64>& _v, function<dat(dat, dat)> _fun)
{
	v = _v;
	fun = _fun;
	n = v.size() - 1;
	mas.resize(4 * n + 8);
	create_rec(1, 0, n);
}

void DO::update_add(int _l, int _r, int _x)
{
	l = _l; r = _r; x = _x;
	get(l, r);
	update_add_rec(1, 0, n);
}

dat DO::get(int _l, int _r)
{
	l = _l; r = _r;
	return get_rec(1, 0, n);
}


void DO::create_rec(int ii, int l, int r)
{
	if (l == r)
	{
		mas[ii].el = v[l];
		mas[ii].dead_end = true;
	}
	else
	{
		int m = (r - l) / 2 + l;
		create_rec(2 * ii, l, m);
		create_rec(2 * ii + 1, m + 1, r);
		mas[ii].el = fun(mas[2 * ii], mas[2 * ii + 1]).el;
	}
}

void DO::update_add_rec(int ii, int ll, int rr)
{

	if ((ll > r) || (rr < l)) return;
	if ((l <= ll) && (rr <= r))
	{
		mas[ii].el += x * (rr - ll + 1);//Прибавить элемент
		mas[ii].change_add += x;
		return;
	}

	int tm = (rr - ll) / 2 + ll;
	update_add_rec(ii * 2, ll, tm);
	update_add_rec(ii * 2 + 1, tm + 1, rr);
	mas[ii].el = fun(mas[ii * 2], mas[ii * 2 + 1]).el;
}

dat DO::get_rec(int ii, int ll, int rr)
{
	if ((l <= ll) && (rr <= r))
	{
		return mas[ii];
	}

	int tm = (rr - ll) / 2 + ll;
	dat buf;

	//Проталкиваем изменения
	if (mas[ii].change_add)
	{
		if (!mas[ii].dead_end)
		{
			mas[ii * 2].el += mas[ii].change_add * (tm - ll + 1);
			mas[ii * 2 + 1].el += mas[ii].change_add * (rr - tm);
			mas[ii * 2].change_add += mas[ii].change_add;
			mas[ii * 2 + 1].change_add += mas[ii].change_add;
		}
		mas[ii].change_add = 0;
	}

	//---------

	if (tm >= l) buf = get_rec(ii * 2, ll, tm);
	else return get_rec(ii * 2 + 1, tm + 1, rr);

	if (tm < r) return fun(buf, get_rec(ii * 2 + 1, tm + 1, rr));
	else return buf;
}