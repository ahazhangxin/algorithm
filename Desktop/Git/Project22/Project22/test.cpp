//#include<iostream>
//#include<map>
//using namespace std;
//
//
//int main()
//{
//	map<int, int> m;
//	m.insert(make_pair(1, 2));
//	m[2] = 3;
//	for (auto& t : m)
//	{
//		cout << t.first << "----" << t.second << endl;
//	}
//	return 0;
//}


#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
class Mul2
{
public:
	void operator()(int& data)
	{
		data <<= 1;
	}
};
class Mod3
{
public:
	bool operator()(int data)
	{
		return 0 == data % 3;
	}
};
int main()
{
	// 给容器中每个元素乘2
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	for_each(v.begin(), v.end(), Mul2());
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	// 删除容器中3的倍数
	auto pos = remove_if(v.begin(), v.end(), Mod3());
	v.erase(pos, v.end());
	// 将容器中的元素打印出来
	// 注意：对于功能简单的操作，可以使用C++11提供的lambda表达式来代替
	// lambda表达式实现简单，其在底层与仿函数的原理相同，编译器会将lambda表达式转换为仿函数
	for_each(v.begin(), v.end(), [](int data){cout << data << " "; });
	cout << endl;
	return 0;
}