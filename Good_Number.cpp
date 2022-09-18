#include "Good_Number.h"

using namespace std;
//__int64 True_Bin_Pow(const __int64& n, const  __int64& p, const  __int64& mod)
//{
//	if (!p) return 1;
//	__int64 answer;
//	answer = True_Bin_Pow(n, p / 2, mod);
//	answer = (answer* answer) % mod;
//	if (p % 2) answer *= n;
//	return answer % mod;
//}

__int64 True_Bin_Pow(const __int64& n, const  __int64& p, const  __int64& mod)
{
	__int64 p_ = p;
	__int64 x = n;
	__int64 ret = 1;
	while (p_)
	{
		if (p_ & 1)
			ret = (ret * x) % mod;
		x = (x * x) % mod;
		p_ >>= 1;
	}

	return ret;
}