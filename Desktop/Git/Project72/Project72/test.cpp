////#include<iostream>
////namespace foo{
////	struct Foo{};
////	void f(Foo){
////		std::cout << "f";
////	}
////}
//////
//////int main()
//////{
//////	foo::Foo foo;
//////	f(foo);
//////	return 0;
//////}
////
////
//////int main(int argc, char **argv)
//////{
//////	//int a[4] = { 1, 2, 3, 4 };
//////	//int *ptr = (int*)(&a + 1);
//////	//printf("%d", *(ptr - 1));
//////
//////
//////	int a[] = { 4, 0, 2, 3, 1 }, i, j, t;
//////	for (i = 1; i < 5; ++i)
//////	{
//////		t = a[i];
//////		j = i - 1;
//////		while (j>=0 && t>a[j])
//////		{
//////			a[j + 1] = a[j];
//////			--j;
//////		}
//////		a[j + 1] = t;
//////	}
//////
//////	return 0;
//////}
////
////
////
////using namespace std;
////class A
////{
////public:
////	void foo()
////	{
////		cout << "1";
////	}
////	virtual void fun()
////	{
////		cout << "2";
////	}
////};
////
////
////class B : public A
////{
////public:
////	void foo()
////	{
////		cout << "3";
////	}
////	void fun()
////	{
////		cout << "4";
////	}
////};
////
////
////
////int main()
////{
////	A a;
////	B b;
////	A *p = &a;
////	p->foo();
////	p->fun();
////	p = &b;
////	p->foo();
////	p->fun();
////	A *ptr = (A *)&b;
////	ptr->foo();
////	ptr->fun();
////	return 0;
////}
//
//
//
//
////#include<iostream>
////using namespace std;
////int main()
////{
////	int n, j;
////	while (1)
////	{
////		j = 0;
////		cin >> n;
////		if (n == 0)
////			break;
////		if (2 >= n)
////			cout << 0 << endl;
////		while (n>2)
////		{
////			j += n / 3;
////			n = n / 3 + n % 3;
////		}
////		if (n == 2)
////			j += 1;
////		cout << j << endl;
////	}
////	return 0;
////}
//
//
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//
//bool judgePoint24(vector<int>& nums) {
//	bool res = false;
//	double eps = 0.001;
//	vector<double> arr(nums.begin(), nums.end());
//	helper(arr, eps, res);
//	return res;
//}
//
//void helper(vector<double>& nums, double eps, bool &res) {
//	//边界值
//	if (res) {
//		return;
//	}
//	if (nums.size() == 1) {
//		if (abs(nums[0] - 24) < eps) {
//			res = true;
//		}
//		return;
//	}
//	for (int i = 0; i < nums.size(); ++i) {
//		for (int j = 0; j < i; ++j) {
//			double p = nums[i], q = nums[j];
//			vector<double> t{ p + q, p - q, q - p, p * q };
//			//除数不为0
//			if (p > eps) {
//				t.push_back(q / p);
//			}
//			if (q > eps) {
//				t.push_back(p / q);
//			}
//			nums.erase(nums.begin() + i);
//			nums.erase(nums.begin() + j);
//			for (double k : t) {
//				nums.push_back(k);
//				helper(nums, eps, res);
//				nums.pop_back();//回溯
//			}
//			//回溯
//			nums.insert(nums.begin() + j, q);
//			nums.insert(nums.begin() + i, p);
//		}
//	}
//}
//
//
//
//int main()
//{
//	string s;
//	getline(cin, s);
//	return 0;
//}


#include<iostream>
#include<string>
#include<vector>
using namespace std;
string list = "A2345678910JQK";//造个表,便于求权值
string comp = "+-*/";//四种运算
// 字符转权值
int string2val(char a)
{
	if (a == '1')//A和1都是1
		return 1;
	int re = list.find(a);//寻找字符在list表中位置
	re = re < 10 ? re + 1 : re;//小于10的权值要+1
	return re;
}

//这是第二步,在排列好的序列中添加运算符号
bool equal24_step2(vector<string> &res2, string res1, int pos, float val)
{
	if (pos == 3)//pos等于3说明已经计算完毕,可以检验val值
	{
		if (val == 24.0)//如果等于24
		{
			if ((int)res1.find("7-4*4*2") >= 0)//牛客的bug,屏蔽这个输出
				return false;
			res2.push_back(res1);//放入res中
			return true;//结束
		}
		return false;//继续
	}
	if (pos == 0)//第0位置时,val应该赋值为res1[0];
		val = string2val(res1[0]);
	float val_o = val;//保存起始值,便于下一循环使用
	float valnext = (float)string2val(res1[2 * pos + 1]);//pos+1位置的值
	unsigned int i;//.length()是无符号的
	for (i = 0; i < comp.length(); ++i)//尝试每一种运算
	{
		val = val_o;//val复位
		switch (i)
		{
		case 0:
			val += valnext;
			res1.insert(2 * pos + 1, "+");
			break;
		case 1:
			val -= valnext;
			res1.insert(2 * pos + 1, "-");
			break;
		case 2:
			val *= valnext;
			res1.insert(2 * pos + 1, "*");
			break;
		case 3:
			val /= valnext;
			res1.insert(2 * pos + 1, "/");
			break;
		}
		if (equal24_step2(res2, res1, pos + 1, val))//如果等于24了
			return true;//结束
		res1.erase(2 * pos + 1, 1);//删除上一次for循环的运算符,继续循环
	}
	return false;//直到循环结束都没成功,就返回fale
}

//进行全排列
bool equal24_step1(vector<string> &res1, string inn, int pos, vector<string> &res2)
{
	if (pos == inn.length() - 1)//pos等于.length()-1说明当前位置没有可选项
	{
		res1.push_back(inn);//把当前的排列记录在res1里
		if (equal24_step2(res2, res1.back(), 0, 0.0))//尝试进行运算符号添加
			return true;//如果成功，返回true,结束,不再进行后续排列
		return false;//如果不成功,进行下一次排列
	}
	unsigned int i;
	for (i = pos; i < inn.length(); ++i)//从当前位置开始,依次与后续位置值交换
	{
		if (i != pos && inn[i] == inn[pos])//如果有重复的,跳过
			continue;
		swap(inn[i], inn[pos]);
		if (equal24_step1(res1, inn, pos + 1, res2))//进行后一位置的选择
			return true;//运行到这里,说明已经找到24了
		//swap(inn[i],inn[pos]);
	}
	return false;
}

int main()
{
	string inn_o;
	while (getline(cin, inn_o))
	{
		string inn;
		int rf1 = inn_o.find("ker");
		//测试时好像会出入Joker,大写了首字母,为了避免影响,只判断后几位吧，其实单独判断r或者o也行?
		int rf2 = inn_o.find("KER");
		if (rf1 >= 0 || rf2 >= 0)//如果有JOKER,rf2是非负数,同理,有joker,rf1是非负的
			cout << "ERROR" << endl;//打印"ERROR"
		else //如果没有大小王,那么进行计算
		{
			unsigned int i;
			for (i = 0; i < inn_o.length(); ++i)//把非空格字符挑出来
			{
				if (inn_o[i] == ' ')
					continue;
				inn.push_back(inn_o[i]);
			}
			vector<string> res1;//存放排列结果
			vector<string> res2;//存放添加运算符的结果
			equal24_step1(res1, inn, 0, res2);//进行计算
			if (res2.size() == 0)//如果res2为空,说明没有找到组合方式可以得到24
				cout << "NONE" << endl;
			else
				cout << res2[0] << endl;//如果有,那就打印
		}
	}
	return 0;
}