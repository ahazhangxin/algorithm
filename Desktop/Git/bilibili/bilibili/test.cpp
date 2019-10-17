//
//
///*题目1:
//一个长度为N的整数数组(N>2)，找出其中相乘最大的2个数。如Arr=[1,2,3],则最大值为2X3=6，返回 2,3
//只需实现一个函数，函数定义：int fun(Arr){return 相乘最大的2个数;}
//*/
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int fun(vector<int> Arr)
//{
//	if (Arr.empty())
//		return 0;
//	int max = Arr[0], min = Arr[0];
//	int sec_max = 0, sec_min = 0;
//	for (int i = 1; i < Arr.size(); ++i)
//	{
//		//求最大和次大的两个值
//		if (Arr[i] > max){
//			sec_max = max;
//			max = Arr[i];
//		}
//		if (Arr[i] > sec_max && Arr[i] < max){
//			sec_max = Arr[i];
//		}
//
//		//求最小和次小的两个值
//		if (Arr[i] < min){
//			sec_min = min;
//			min = Arr[i];
//		}
//		if (Arr[i] < sec_min && Arr[i] > min){
//			sec_min = Arr[i];
//		}
//	}
//	return (max*sec_max) > (min*sec_min) ? (max*sec_max) : (min*sec_min);
//}
//
//int main()
//{
//	vector<int> v0{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	vector<int> v{ 1, 1, 2, 4, 5, 6 };
//	vector<int> v1{ -1, -1, -2, -4, -5, -6 };
//	vector<int> v2{ -3, -1, 0, 3 };
//	vector<int> v3{ -1, 0, 1 };
//	cout << fun(v0) << endl;
//	cout << fun(v) << endl;
//	cout << fun(v1) << endl;
//	cout << fun(v2) << endl;
//	cout << fun(v3) << endl;
//	return 0;
//}




/*题目2:
一个大小是M*N大小的白色画板P, 即M像素*N像素,每个像素由r、g、b共 3个颜色组成,每个颜色值是0~255。设计一个方法、数据结构，
可以对这张图片绘制一个实心矩形。函数声明大概是 draw(P, 矩形数据， 绘制颜色)，打印最终结果如 
（r,g,b）(r,g,b) (r,g,b).....
（r,g,b）(r,g,b) (r,g,b).....
（r,g,b）(r,g,b) (r,g,b).....
...
*/

#include<iostream>
#include<vector>
using namespace std;
  
//用一个结构体标识像素点
//也可以用一个整数表示，利用位图映射的思想
struct pixel
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

void draw(vector<vector<pixel>>& P, int left, int right, int top, int low, int color)
{
	//								   r		g		b	
	//用一个整数表示color 00000000 00000000 00000000 00000000
	//
	//也可以用结构体来表示需要表示的颜色
	//此处用一个整数表示该像素的颜色，发现编码会变得更加复杂

	pixel t;
	unsigned char x = 0;
	vector<unsigned char> v;
	
	//取颜色属性
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 8; ++j){
			x *= 10;
			x += (color & 1);
			color >>= 1;
		}
		v.push_back(x);
		x = 0;
	}
	t.b = v[0];
	t.g = v[1];
	t.r = v[2];
	//在画板上绘图
	for (int i = top; i <= low; ++i){
		//防止越界
		if (i >= P.size()) break;

		for (int j = left; j <= right; ++j){
			//防止越界
			if (j >= P[0].size()) break;
			P[i][j] = t;
		}
	}
}

int main()
{
	int M, N;
	M = 20;
	N = 20;
	vector<vector<pixel>> v;
	pixel t;
	t.r = 0;
	t.g = 0;
	t.b = 0;
	vector<pixel> temp;
	for (int i = 0; i < 20; ++i){
		temp.push_back(t);
	}
	for (int i = 0; i < 20; ++i){
		v.push_back(temp);
	}
	//     (左 右 上 下)  
	draw(v, 5, 15, 5, 15, 0x00ffffff);
	draw(v, 0, 20, 0, 20, 0x00ffffff);
	return 0;
}