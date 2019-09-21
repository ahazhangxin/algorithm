//#include<iostream>
//using namespace std;
//class CExample
//{
//private:
//	int a;
//public:
//	//构造函数
//	CExample(int b)
//	{
//		//a = b;
//		printf("constructor is called\n");
//	}
//	//拷贝构造函数
//	CExample(const CExample & c)
//	{
//		a = c.a;
//		printf("copy constructor is called\n");
//	}
//	//析构函数
//	~CExample()
//	{
//		cout << "destructor is called\n";
//	}
//	void Show()
//	{
//		cout << a << endl;
//	}
//};
//CExample g_fun()
//{
//	CExample temp(0);
//	return temp;
//}
//int main()
//{
//
//	g_fun();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class CExample
//{
//private:
//	int a;
//public:
//	CExample(int b)
//	{
//		a = b;
//		printf("constructor is called\n");
//	}
//	CExample(const CExample & c)
//	{
//		a = c.a;
//		printf("copy constructor is called\n");
//	}
//	~CExample()
//	{
//		cout << "destructor is called\n";
//	}
//	void Show()
//	{
//		cout << a << endl;
//	}
//};
//void g_fun(CExample c)
//{
//	cout << "g_func" << endl;
//}
//int main()
//{
//	CExample A(100);
//	CExample B = A;
//	B.Show();
//	g_fun(A);
//	return 0;
//}


//#include<iostream>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string>
//#include<sstream>
//using namespace std;
//int main()
//{
//	char* s = "aisufbhiaubnf";
//	int a;
//	stringstream str;
//	str << s;
//	str >> a;
//	cout << a << endl;
//	return 0;
//}


#include<iostream>
#include<algorithm>
using namespace std;


int SelectPivot(int arr[], int low, int high)
{
	return arr[low];//选择选取序列的第一个元素作为基准
}


/*随机选择枢轴的位置，区间在low和high之间*/
int SelectPivotRandom(int arr[], int low, int high)
{
	//产生枢轴的位置
	srand((unsigned)time(NULL));
	int pivotPos = rand() % (high - low) + low;

	//把枢轴位置的元素和low位置元素互换，此时可以和普通的快排一样调用划分函数
	swap(arr[pivotPos], arr[low]);
	return arr[low];
}



/*函数作用：取待排序序列中low、mid、high三个位置上数据，选取他们中间的那个数据作为枢轴*/
int SelectPivotMedianOfThree(int arr[], int low, int high)
{
	int mid = low + ((high - low) >> 1);//计算数组中间的元素的下标

	//使用三数取中法选择枢轴
	if (arr[mid] > arr[high])//目标: arr[mid] <= arr[high]
	{
		swap(arr[mid], arr[high]);
	}
	if (arr[low] > arr[high])//目标: arr[low] <= arr[high]
	{
		swap(arr[low], arr[high]);
	}
	if (arr[mid] > arr[low]) //目标: arr[low] >= arr[mid]
	{
		swap(arr[mid], arr[low]);
	}
	//此时，arr[mid] <= arr[low] <= arr[high]
	return arr[low];
	//low的位置上保存这三个位置中间的值
	//分割时可以直接使用low位置的元素作为枢轴，而不用改变分割函数了
}

void QSort(int arr[], int low, int high)
{
	int first = low;
	int last = high;

	int left = low;
	int right = high;

	int leftLen = 0;
	int rightLen = 0;

	if (high - low + 1 < 10)
	{
		InsertSort(arr, low, high);
		return;
	}

	//一次分割
	int key = SelectPivotMedianOfThree(arr, low, high);//使用三数取中法选择枢轴

	while (low < high)
	{
		while (high > low && arr[high] >= key)
		{
			if (arr[high] == key)//处理相等元素
			{
				swap(arr[right], arr[high]);
				right--;
				rightLen++;
			}
			high--;
		}
		arr[low] = arr[high];
		while (high > low && arr[low] <= key)
		{
			if (arr[low] == key)
			{
				swap(arr[left], arr[low]);
				left++;
				leftLen++;
			}
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = key;

	//一次快排结束
	//把与枢轴key相同的元素移到枢轴最终位置周围
	int i = low - 1;
	int j = first;
	while (j < left && arr[i] != key)
	{
		swap(arr[i], arr[j]);
		i--;
		j++;
	}
	i = low + 1;
	j = last;
	while (j > right && arr[i] != key)
	{
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	QSort(arr, first, low - 1 - leftLen);
	QSort(arr, low + 1 + rightLen, last);
}