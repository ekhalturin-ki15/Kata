#include <tuple>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <tuple>
#include <vector>
#include <random> 
#include <ctime>

using namespace std;
static std::mt19937_64 generator(time(0));
//Генерация заданого параметрами числа
template <typename Type>
void Random_Number(Type& number, const __int64& min_value = -INF, const __int64& max_value = INF)
{
	unsigned __int64 answer = generator() % (max_value- min_value);
	number = answer;
	number+= min_value;
}


//Генерация заданого параметрами массива
template <typename Type>
void Random_Array(vector<Type>& mas, const  size_t& size_min = 0,
				const  size_t& size_max = 1e4, const __int64& min_value = -INF,
				const __int64& max_value = INF)
{
	//std::mt19937_64 generator(time(0));
	mas.resize(generator() % (size_max- size_min) + size_min);
	for (size_t i = 0; i < mas.size(); i++)
	{
		Type number;
		Random_Number(number, min_value, max_value);
		mas[i] = number;
	}
	sort(mas.begin(), mas.end());
}

template <typename Tf, typename Ts>
void swap(pair<Tf, Ts>& T);

template <typename ... Ts>
std::string to_string(const Ts& ... ts);

template <typename... Args>
std::string to_string(const std::tuple<Args...>& t);

template <typename Tf>
std::string to_string(const vector<Tf>& v);

template <typename Tf, typename Ts>
std::string to_string(const pair<Tf, Ts>& T)
{
	std::stringstream ss;
	const char* sep = "";
	ss << to_string(T.first) << " "<< to_string(T.second);
	return ss.str();
}

template <typename Tf, typename Ts>
void swap(pair<Tf, Ts>& T)
{
	swap(T.first, T.second);
}

template <typename ... Ts>
std::string to_string(const Ts& ... ts)
{
	std::stringstream ss;
	const char* sep = "";
	(((ss << sep << ts), sep = " "), ...);
	return ss.str();
}

template <typename... Args>
std::string to_string(const std::tuple<Args...>& t)
{
	return std::apply([](const auto & ... ts) { return to_string(ts...); }, t);
}

template <typename Tf>
std::string to_string(const vector<Tf>& v)
{
	string answer;
	for (const auto& it : v)
	{
		answer += to_string(it) + string(",");
	}
	return answer;
}
