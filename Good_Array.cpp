
#include "Good_Array.h"

using namespace std;

//Проверено на всех задачах с https://informatics.mccme.ru/mod/statements/view3.php?id=192&chapterid=2
pair<int, int> True_Binary_search(const vector<__int64>& mas, __int64 x)
{

	size_t n = mas.size();
	int  middle, left, right;
	pair<int, int> answer;

	left = -1; right = n - 1; //Ищем полуинтерволом (left , right]
	while (right-left> 1)
	{
		middle = (right - left) / 2 + left;
		if (mas[middle] >= x) right = middle;
		else
			left = middle;
	}
	answer.first = right;

	left = 0, right = n; //Ищем полуинтерволом [left , right)
	while (right - left > 1)
	{
		middle = (right - left) / 2 + left;
		if (mas[middle] > x) right = middle;
		else
		left = middle;
	}
	answer.second = left; 
	if (mas[left] != x) swap(answer.first, answer.second);
	return answer;
}

