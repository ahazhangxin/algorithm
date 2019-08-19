////这个demo模拟实现一个smart_ptr
//
//#include<iostream>
//
//using namespace std;
//
//template <class T>
//class Smart_ptr
//{
//public:
//	Smart_ptr(T* str = nullptr)
//		:_str(str)
//	{}
//	~Smart_ptr()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//	T& operator*()
//	{
//		return *_str;
//	}
//
//	T* operator->()
//	{
//		return	_str;
//	}
//private:
//	T* _str;
//};
//
//
//struct time
//{
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Smart_ptr<int> s(new int);
//	*s = 10;
//	cout << *s << endl;
//
//	Smart_ptr<time> s1(new time);
//		
//	//这里本来应该是s1.operator->()->_year = 2019;
//	//为了可读性，所以直接写成s1->_year;
//	s1->_year = 2019;
//	s1->_month = 8;
//	s1->_day = 18;
//	return 0;
//}


//这个demo模拟实现了auto_ptr
//#include<iostream>
//using namespace std;
//
//template <class T>
//class Auto_ptr
//{
//public:
//	Auto_ptr(T* str = nullptr)
//		:_str(str)
//	{}
//	~Auto_ptr()
//	{
//		if (_str)
//		{
//			delete _str;
//			_str = nullptr;
//		}
//	}
//
//	//一旦发生拷贝，就将管理权转移给当前对象，然后令前身与其管理的空间断开联系
//	//这样就不会出现多个对象管理一份空间的问题，也就不会出现对一份地址释放多次的问题
//	Auto_ptr(Auto_ptr<T>& str)
//		:_str(str._str)
//	{
//		if (&str != this)
//		{
//			str._str = nullptr;
//		}
//	}
//
//	Auto_ptr<T>& operator=(const Auto_ptr<T>& str)
//	{
//		if (str != *this)
//		{
//			if (_str)
//				delete _str;
//
//			_str = str._str;
//			str._str = nullptr;
//		}
//		return *this;
//	}
//
//	T* operator->()
//	{
//		return _str;
//	}
//
//	T& operator*()
//	{
//		return *_str;
//	}
//
//private:
//	T* _str;
//};
//
//
//
//int main()
//{
//	Auto_ptr<int> s(new int);
//	*s = 10;
//	Auto_ptr<int> s1(s);
//	cout << *s1 << endl;
//	return 0;
//}



////这个demo模拟实现了unqiue_ptr
//#include<iostream>
//using namespace std;
//
//template <class T>
//class Unique_ptr
//{
//public:
//	Unique_ptr(T* str = nullptr)
//		:_str(str)
//	{}
//	~Unique_ptr()
//	{
//		if (_str)
//		{
//			delete _str;
//			_str = nullptr;
//		}
//	}
//	T& operator*()
//	{
//		return _str;
//	}
//
//	T* operator->()
//	{
//		return *_str;
//	}
//private:
//	//C++98版实现
//	Unique_ptr(Unique_ptr<T> & str);
//	Unique_ptr& operator=(const Unique_ptr<T> & str);
//	/*
//	C++11中实现
//	Unique_ptr(Unique_ptr<T> const str) = delete;
//	T& operator=(const Unique_ptr<T> const str) = delete;
//	*/
//
//private:
//	T* _str;
//};
//
//
//int main()
//{
//	Unique_ptr<int> s;
//	//Unique_ptr s1(s);
//	return 0;
//}


//
//#include<iostream>
//using namespace std;
//
////使用辅助类
//template<class T>
//class SmartPtr;
//
///*
//辅助类包含：
//1、引用计数器_count;
//2、指向实际空间的指针_ptr;
//*/
//template<class T>
//class Asistant
//{
//	friend class SmartPtr<T>;
//private:
//	Asistant(T *ptr) :_count(1), _ptr(ptr)
//	{}
//	~Asistant(){
//		delete _ptr;
//		_ptr = NULL;
//	}
//	int _count;
//	T *_ptr;
//};
//
///*
//智能指针类:(包含)
//1、指向辅助类的指针
//*/
//template<class T>
//class SmartPtr{
//public:
//	SmartPtr(T *ptr) :_p(new Asistant<T>(ptr))
//	{}
//	SmartPtr(const SmartPtr<T> &sp){
//		_p = sp._p;
//		_p->_count++;
//	}
//	SmartPtr& operator=(const SmartPtr<T> &sp){
//		if (this != &sp){
//			//处理好原来的关系---->注意：处理好与“前妻”的关系
//			if (--(_p->_count) == 0){
//				delete _p;         //会先调用辅助类的析构函数(释放实际空间),再释放辅助类对象空间
//			}
//			//指向新的辅助空间
//			_p = sp._p;
//			(_p->_count)++;
//		}
//		return *this;
//	}
//	~SmartPtr(){
//		if (--(_p->_count) == 0){
//			delete _p;
//			_p = NULL;
//		}
//	}
//	T* operator->(){
//		return _p->_ptr;
//	}
//	T& operator*(){
//		return *(_p->_ptr);
//	}
//
//private:
//	Asistant<T> *_p;
//};
//
//////////////////////////////////////////////////////////////////////////////
//
////在一个类中实现智能指针
//template<class T>
//class SmartPtr1{
//public:
//	SmartPtr1(T *ptr) :_countPtr(new int(1)), _ptr(ptr)
//	{}
//	~SmartPtr1(){
//		if (--(*_countPtr) == 0){
//			delete _ptr;
//			delete _countPtr;
//			_ptr = NULL;
//			_countPtr = NULL;
//		}
//	}
//	SmartPtr1(const SmartPtr1<T> &sp){
//		_countPtr = sp._countPtr;
//		++(*_countPtr);
//		_ptr = sp._ptr;
//	}
//	/*
//	operator=四部曲：
//	1、检查自赋值
//	2、与以前“一刀两断”
//	3、指向新世界
//	4、return *this
//	*/
//	SmartPtr1& operator=(const SmartPtr1<T> &sp){
//		if (this != &sp){
//			if (--(*_countPtr) == 0){
//				delete _countPtr;
//				delete _ptr;
//				_countPtr = NULL;
//				_ptr = NULL;
//			}
//			_countPtr = sp._countPtr;
//			++(*_countPtr);
//			_ptr = sp._ptr;
//		}
//		return *this;
//	}
//	T* operator->(){
//		return _ptr;
//	}
//	T& operator*(){
//		return *_ptr;
//	}
//private:
//	int *_countPtr;//指向引用计数的指针
//	T *_ptr;       //指向实际空间的指针
//};
//
//
//
////垂悬指针：指向已被释放空间的指针
//void HangPtr()
//{
//	int *ptr1 = new int(10);
//	int *ptr2 = ptr1;
//	int *ptr3 = ptr1;
//
//	cout << "before delete:" << endl;
//	cout << *ptr1 << endl;
//	cout << *ptr2 << endl;
//	cout << *ptr3 << endl;
//
//	cout << "after delete:" << endl;
//	delete ptr1;
//	cout << *ptr2 << endl;//所指向的空间已被释放--->悬垂指针，程序崩溃“指日可待”
//	cout << *ptr3 << endl;
//}
//
////SmartPtr
////-------------------> SmartPtr <---------------------------
////测试拷贝构造函数
//void test1(){
//	int *p = new int(10);
//	SmartPtr<int> sp(p);
//	{
//		SmartPtr<int> sp1(sp);
//	}
//	SmartPtr<int> sp2(sp);
//}
//
////测试operator=
//void test2()
//{
//	int *p = new int(10);
//	SmartPtr<int> ptr(p);
//
//	int *p1 = new int(20);
//	SmartPtr<int> ptr1(p1);
//
//	ptr1 = ptr;
//	cout << *ptr << endl;
//	cout << *ptr1 << endl;
//}
//
////-------------------> SmartPtr1 <---------------------------
////测试拷贝构造函数
//void test3(){
//	int *p = new int(10);
//
//	SmartPtr1<int> sp(p);
//	{
//		SmartPtr1<int> sp1(sp);
//	}
//	SmartPtr1<int> sp2(sp);
//}
//
////测试operator=
//void test4()
//{
//	int *p = new int(10);
//	SmartPtr<int> ptr(p);
//
//	int *p1 = new int(20);
//	SmartPtr<int> ptr1(p1);
//
//	ptr1 = ptr;
//	cout << *ptr << endl;
//	cout << *ptr1 << endl;
//}
//int main()
//{
//	test4();
//	system("pause");
//	return 0;
//}

//// 1.演示引用计数线程安全问题，就把AddRefCount和SubRefCount中的锁去掉
//// 2.演示可能不出现线程安全问题，因为线程安全问题是偶现性问题，main函数的n改大一些概率就变大了，就容易出现了。
//// 3.下面代码我们使用SharedPtr演示，是为了方便演示引用计数的线程安全问题，将代码中的SharedPtr换成sshared_ptr进行测试，可以验证库的shared_ptr，发现结论是一样的。
//void SharePtrFunc(SharedPtr<Date>& sp, size_t n) {
//	cout << sp.Get() << endl;
//	for (size_t i = 0; i < n; ++i)
//	{
//		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
//		SharedPtr<Date> copy(sp);
//		// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最
//		终看到的结果，并一定是加了2n
//			copy->_year++;
//		copy->_month++;
//		copy->_day++;
//	}
//}
//int main()
//{
//	SharedPtr<Date> p(new Date);
//	cout << p.Get() << endl;
//	const size_t n = 100;
//	thread t1(SharePtrFunc, p, n);
//	thread t2(SharePtrFunc, p, n);
//	t1.join();
//	t2.join();
//	cout << p->_year << endl;
//	cout << p->_month << endl;
//	cout << p->_day << endl;
//	return 0;
//}



//struct ListNode
//{
//	int _data;
//	shared_ptr<ListNode> _prev;
//	shared_ptr<ListNode> _next;
//	~ListNode(){ cout << "~ListNode()" << endl; }
//};
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	return 0;
//}


// 仿函数的删除器
template<class T>
struct FreeFunc {
	void operator()(T* ptr)
	{
		cout << "free:" << ptr << endl;
		free(ptr);
	}
};
template<class T>
struct DeleteArrayFunc {
	void operator()(T* ptr)
	{
		cout << "delete[]" << ptr << endl;
		delete[] ptr;
	}
};
int main()
{
	FreeFunc<int> freeFunc;
	shared_ptr<int> sp1((int*)malloc(4), freeFunc);
	DeleteArrayFunc<int> deleteArrayFunc;
	shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);
	return 0;
}