//#include<iostream>
//
//using namespace std;
//int main()
//{
//
//	int i = 10;
//	double d = i;
//	cout << d << "   " << i << endl;
//	int *t = &i;
//	int addr = (int)t;
//	cout << addr << "        " << *t << endl;
//	return 0;
//}

//static_cast、reinterpret_cast、const_cast、dynamic_cast



//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	double d = 1.34;
//	int i = static_cast<int> (d);
//	cout << d << endl;
//	cout << i << endl;
//	return 0;
//}
//


//#include<iostream>
//using namespace std;
//
//typedef void(*FUNC)();
//int DoSomething(int i)
//{
//	cout << "DoSomething" << endl;
//	return 0;
//}
//void Test()
//{
//	//
//	// reinterpret_cast可以编译器以FUNC的定义方式去看待DoSomething函数
//	// 所以非常的BUG，下面转换函数指针的代码是不可移植的，所以不建议这样用
//	// C++不保证所有的函数指针都被一样的使用，所以这样用有时会产生不确定的结果
//	//
//	FUNC f = reinterpret_cast< FUNC>(DoSomething);
//	f();
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//const_cast

//#include<iostream>
//using namespace std;
//
//
//int main()
//{
//	const int a = 4;
//	cout << "a = " << a << endl;
//	cout << endl;
//	int *i = const_cast<int*>(&a);
//	*i = 3;
//	cout << "a = " << a << endl;
//	cout << "i = " << *i << endl;
//	return 0;
//}

//dynamic_cast

/*
dynamic_cast用于将一个父类对象的指针转换为子类对象的指针或引用(动态转换)
向上转型：子类对象指针->父类指针/引用(不需要转换，赋值兼容规则) 
向下转型：父类对象指针->子类指针/引用(用dynamic_cast转型是安全的)
注意： 
1. dynamic_cast只能用于含有虚函数的类 
2. dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回0
*/
//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	virtual void f(){}
//};
//class B : public A
//{};
//void fun(A* pa)
//{
//	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
//	B* pb1 = static_cast<B*>(pa);
//	B* pb2 = dynamic_cast<B*>(pa);
//	cout << "pb1:" << pb1 << endl;
//	cout << "pb2:" << pb2 << endl;
//}
//int main()
//{
//	A a; B b;
//	fun(&a);
//	fun(&b);
//	return 0;
//}


#include<iostream>
using namespace std;

class A
{
public:
	explicit A(int a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};
int main()
{
	A a1(1);
	// 隐式转换-> A tmp(1); A a2(tmp);
	//A a2 = 1;
}