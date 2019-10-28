#include<iostream>
using namespace std;
//int main()
//{
//	//unsigned char ch = 0;
//	//int count = 0;
//	//while (++ch<=255)
//	//{
//	//	count++;
//	//}
//	//cout << count << endl;
//	int i = 5, j = 2;
//	cout << (i << j) << " " << (i >> j);
//	return 0;
//}

template<typename T,int count>
void foo(T x)
{
	T val[count];
	for (int i = 0; i < count; ++i){
		val[i] = x++;
		cout << val[i] << " ";
	}
};

int main()
{
	float y = 2.1;
	foo<float, 3>(y);
	return 0;
}