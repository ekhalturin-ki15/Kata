#include "CppUnitTest.h"

#include "Good_Array.h"
#include "Array.h"
#include "Good_Geometry.h"
#include "Geometry.h"
#include "Good_String.h"
#include "String.h"
#include "auxiliary.h"
#include "Good_Number.h"
#include "Good_Struct.h"
#include "Good_Extra_Struct.h"


#include <vector>
#include <fstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
#define __int64 long long

const __int64 INF = 1e18;
const size_t NUM_OF_TEST = 10;


namespace Array
{
	TEST_CLASS(Binary_Search_)
	{
		vector<__int64> mas;
	public:

		TEST_METHOD(Empty) // Проверка, чтобы не выйди за пределы массива
		{
			mas = {1};
			Binary_search(mas, 1);
			Assert::IsTrue(true);

		}
		TEST_METHOD(Test1) // Обычный тест
		{
			mas = { 1, 1, 1, 1, 2, 2, 3, 3, 4 };
			Assert::AreEqual(to_string(True_Binary_search(mas, 1)), to_string(Binary_search(mas, 1)));
		}

		TEST_METHOD(Test_Between) // Обычный тест
		{
			mas = { 1, 3 };
			Assert::AreEqual(to_string(True_Binary_search(mas, 2)), to_string(Binary_search(mas, 2)));
		}

		TEST_METHOD(TestMin1) //Проверка, что мы не выходим за массив справа
		{
			mas = { 1, 2 };
			Assert::AreEqual(to_string(True_Binary_search(mas, 3)), to_string(Binary_search(mas, 3)));
		}

		TEST_METHOD(TestMin2)//Проверка, что мы не выходим за массив слева
		{
			mas = { 1, 2 };
			Assert::AreEqual(to_string(True_Binary_search(mas, 0)), to_string(Binary_search(mas, 0)));
		}

	};

}

namespace Geometry
{
	TEST_CLASS(Pseudoscalar_)
	{
		pair<__int64, __int64> t0; pair<__int64, __int64> t1; pair<__int64, __int64> t2;

	public:
		TEST_METHOD(Test1) // Обычный тест
		{
			t0 = { 1, 1 };
			t1 = { 3,0 };
			t2 = { 3,2 };
			Assert::AreEqual(to_string(True_Pseudoscalar(t0, t1 ,t2 )),to_string(Pseudoscalar(t0, t1, t2)));
		}

		TEST_METHOD(Test2) // Обычный тест
		{
			t0 = { 1, 1 };
			t1 = { 3,2 };
			t2 = { 3,0 };
			Assert::AreEqual(to_string(True_Pseudoscalar(t0, t1, t2)), to_string(Pseudoscalar(t0, t1, t2)));
		}
		TEST_METHOD(Test3) // Обычный тест
		{
			t0 = { 1, 0 };
			t1 = { 0,0 };
			t2 = { 2,0 };
			Assert::AreEqual(to_string(True_Pseudoscalar(t0, t1, t2)), to_string(Pseudoscalar(t0, t1, t2)));
		}
	};

	TEST_CLASS(Polygon_Area_)
	{
		vector< pair<__int64, __int64>> t;

	public:
		TEST_METHOD(Test1) // Обычный тест
		{
			t = { {0 ,0} , {0, 1}, {1,1},{1,0} };
			Assert::AreEqual(to_string(True_Polygon_Area(t)), to_string(Polygon_Area(t)));
		}

		TEST_METHOD(Test2) // Обычный тест
		{
			t = { {0 ,0} , {1, 0}, {1,1},{0,1} };
			Assert::AreEqual(to_string(True_Polygon_Area(t)), to_string(Polygon_Area(t)));
		}
		TEST_METHOD(Test3) // Обычный тест
		{
			t = { {8, 4} , {-3, 3} , {9, 2} , {4,2}, {-8, -1}, {-10,5} };
			Assert::AreEqual(to_string(True_Polygon_Area(t)), to_string(Polygon_Area(t)));
		}
	};

	TEST_CLASS(Convex_Hull_)
	{
		vector< pair<__int64, __int64>> t;

	public:
		TEST_METHOD(Test1) // Обычный тест
		{
			t = { {0 ,0} , {0, 1}, {1,1},{1,0} };
			Assert::AreEqual(to_string(True_Convex_Hull(t)), to_string(Convex_Hull(t)));
		}

		TEST_METHOD(Test2) // Обычный тест
		{
			t = { {0 ,0} , {1, 1}, {1,0},{0,1} };
			Assert::AreEqual(to_string(True_Convex_Hull(t)), to_string(Convex_Hull(t)));
		}
		TEST_METHOD(Test3) // Обычный тест
		{
			t = { {8, 4} , {-3, 3} , {9, 2} , {4,2}, {-8, -1}, {-10,5} };
			Assert::AreEqual(to_string(True_Convex_Hull(t)), to_string(Convex_Hull(t)));
		}

		TEST_METHOD(Test4) // Обычный тест
		{
			t = { {0 ,0} , {0, 1}, {1,1} };
			Assert::AreEqual(to_string(True_Convex_Hull(t)), to_string(Convex_Hull(t)));
		}
		
	};

}


namespace String
{
	TEST_CLASS(Z_Function_)
	{
		string s;
	public:
		TEST_METHOD(Test1) // Обычный тест
		{
			s = "ABACABABACABA";
			Assert::AreEqual(to_string(True_Z_Function(s)), to_string(Z_Function(s)));
		}

		TEST_METHOD(Test2) // Обычный тест
		{
			s = "ABAA";
			Assert::AreEqual(to_string(True_Z_Function(s)), to_string(Z_Function(s)));
		}

		TEST_METHOD(TestSame) // Обычный тест
		{
			s = "AAAAAAAAAA";
			Assert::AreEqual(to_string(True_Z_Function(s)), to_string(Z_Function(s)));
		}

		TEST_METHOD(Test3) // Обычный тест
		{
			s = "AAABAAB";
			Assert::AreEqual(to_string(True_Z_Function(s)), to_string(Z_Function(s)));
		}

		TEST_METHOD(TestACMP1) // С задачи https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=18&id_topic=42&id_problem=281
		{
			s = "ABRACADABRA";
			Assert::AreEqual(to_string(True_Z_Function(s)), to_string(Z_Function(s)));
		}

		TEST_METHOD(TestACMP2) // С задачи https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=18&id_topic=42&id_problem=281
		{
			s = "ABACABADABACABA";
			Assert::AreEqual(to_string(True_Z_Function(s)), to_string(Z_Function(s)));
		}
	};

	TEST_CLASS(Prefix_Function_)
	{
		string s;
	public:
		TEST_METHOD(TestSame) // Обычный тест
		{
			s = "AAAAAAAAAA";
			Assert::AreEqual(to_string(True_Prefix_Function(s)), to_string(Prefix_Function(s)));
		}

		TEST_METHOD(TestACMP1) // С задачи https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=18&id_topic=42&id_problem=280
		{
			s = "ABRACADABRA";
			Assert::AreEqual(to_string(True_Prefix_Function(s)), to_string(Prefix_Function(s)));
		}

		TEST_METHOD(TestACMP2) // С задачи https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=18&id_topic=42&id_problem=280
		{
			s = "ABACABADABACABA";
			Assert::AreEqual(to_string(True_Prefix_Function(s)), to_string(Prefix_Function(s)));
		}

	};


	TEST_CLASS(Manacher_)
	{
		string s;
	public:
		TEST_METHOD(TestSame) // Обычный тест
		{
			s = "AAAAAAAAAA";
			Assert::AreEqual(to_string(True_Manacher(s)), string("1,2,3,4,5,5,4,3,2,1, 1,2,3,4,5,4,3,2,1,0,"));
		}

		TEST_METHOD(Test1)
		{
			s = "ABABABABA";
			Assert::AreEqual(to_string(True_Manacher(s)), string("1,2,3,4,5,4,3,2,1, 0,0,0,0,0,0,0,0,0,"));
		}

		TEST_METHOD(Test2)
		{
			s = "CCAABBAACC";
			Assert::AreEqual(to_string(True_Manacher(s)), string("1,1,1,1,1,1,1,1,1,1, 1,0,1,0,5,0,1,0,1,0,"));
		}

		TEST_METHOD(TestACMP1) // С задачи https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=18&id_topic=42&id_problem=282
		{
			s = "ABRACADABRA";
			Assert::AreEqual(to_string(True_Manacher(s)), string("1,1,1,1,2,1,2,1,1,1,1, 0,0,0,0,0,0,0,0,0,0,0,"));
		}

		TEST_METHOD(TestACMP2) // С задачи https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=18&id_topic=42&id_problem=282
		{
			s = "ABACABADABACABA";
			Assert::AreEqual(to_string(True_Manacher(s)), string("1,2,1,4,1,2,1,8,1,2,1,4,1,2,1, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"));
		}

		TEST_METHOD(TestRand) // С задачи https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=18&id_topic=42&id_problem=282
		{
			s.resize(100);
			std::generate(s.begin(), s.end(), []()  { return rand()%26 +'a'; });
			Assert::AreEqual(to_string(True_Manacher(s)), to_string(Manacher(s)));
		}
	};
}



namespace Number
{
	TEST_CLASS(Bin_Pow_)
	{
	public:
		TEST_METHOD(Test1) // Обычный тест
		{
			Assert::AreEqual(to_string(True_Bin_Pow(2, 10, 10000)), to_string("1024"));
		}
		TEST_METHOD(TestMin) // Обычный тест
		{
			Assert::AreEqual(to_string(True_Bin_Pow(777, 0, 10000)), to_string("1"));
		}
		TEST_METHOD(Test2) // Обычный тест
		{
			Assert::AreEqual(to_string(True_Bin_Pow(2, 1e18, 1e9)), to_string("787109376"));
		}
	};

}


namespace Struct
{
	TEST_CLASS(DSU_)
	{
	public:
		TEST_METHOD(Test1) // Обычный тест
		{
			True_DSU<int> d({1, 5, 7, 8, 3, 4 ,2, 0, 1, -1});
			d.Merge(0, 9);
			d.Merge(1, 2);
			d.Merge(2, 3);
			d.Merge(7, 8);
			d.Merge(8, 9);
			d.Merge(0, 1);
			Assert::IsTrue(d.isSame(0, 7));
			Assert::IsFalse(d.isSame(5, 6));
			Assert::IsFalse(d.isSame(1, 6));
			Assert::IsTrue(d.isSame(7, 1));
			Assert::AreEqual(4, d.count);
		}
	};

}

namespace Extra_Struct
{
	TEST_CLASS(Heap_)
	{
	public:
		TEST_METHOD(Test1) // Обычный тест
		{
			True_Heap<int> d({ 1, 5, 7, 8, 3, 4 ,2, 0, 1, -1 });
			Assert::AreEqual(-1, d.Top());
			d.Pop();
			Assert::AreEqual(0, d.Top());
		}
	};

}