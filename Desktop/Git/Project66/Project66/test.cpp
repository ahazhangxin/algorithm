#include<iostream>
#include<vector>
using namespace std;


//void Swap(int& a, int& b){
//	int temp = b;
//	b = a;
//	a = temp;
//}
//
//void BubbleSort(vector<int>& array)
//{
//	for (int i = 0; i < array.size()-1; ++i){
//		int t = 0;
//		for (int j = 0; j < array.size()-1; ++j){
//
//			if (array[j]>array[j + 1]){
//				Swap(array[j], array[j + 1]);
//				t = 1;
//			}
//		}
//		if (t == 0)
//			break;
//	}
//}
//
//void quickSort(vector<int>& array, int left, int right)
//{
//	if (left < right)
//	{
//		int pivot = array[left];
//		int low = left, high = right;
//		while (low < high)
//		{
//			while (array[high] >= pivot && low < high)
//				high--;
//			array[low] = array[high];
//
//			while (array[low] <= pivot && low < high)
//				low++;
//			array[high] = array[low];
//		}
//		array[low] = pivot;
//
//		quickSort(array, left, low - 1);
//		quickSort(array, low + 1, right);
//	}
//}
//
//int _QuickSort(vector<int>& v,int left,int right)
//{
//	int begin = left;
//	int end = right;
//	int temp = v[right];
//	while (begin<end)
//	{
//		while (begin<end && v[begin]<=temp)
//		{
//			begin++;
//		}
//		v[end] = v[begin];
//		while (begin<end && v[end]>=temp)
//		{
//			end--;
//		}
//		v[begin] = v[end];
//	}
//	v[begin] = temp;
//	return begin;
//}
//
//
//void QuickSort(vector<int>& v, int left, int right)
//{
//	if (left > right)
//		return;
//	if (left == right)
//		return;
//	int div = _QuickSort(v, left, right);
//	_QuickSort(v, left, div - 1);
//	_QuickSort(v, div + 1, right);
//}
//


void Swap(int* a,int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

int Partition_03(int *array, int left, int right)
{
	int cur, div;

	for (cur = left, div = left; cur < right; cur++)
	{
		if (array[cur] < array[right])
		{
			Swap(&array[cur], &array[div]);
			div++;
		}
	}
	Swap(&array[div], &array[right]);
	return div;
}


void _QuickSort(int *array, int left, int right)
{
	if (left > right)
	{
		return;
	}

	if (left == right)
	{
		return;
	}
	int div = Partition_03(array, left, right);
	_QuickSort(array, left, div - 1);
	_QuickSort(array, div + 1, right);
}

void QuickSort(int array[], int size)
{
	_QuickSort(array, 0, size - 1);
}

int main()
{
	//cout << (0xaa | 0x55) << endl;
	//cout << (15 & 240) << endl;
	//cout << (10 ^ 12) << endl;
	//cout << (-2 >> 1) << endl;
	vector<int> v{ 8, 6, 9, 5, 3, 2, 4, 1, 7 };
	//BubbleSort(v);
	//QuickSort(v, 0, v.size() - 1);
	int arr[] = { 8, 6, 9, 5, 3, 2, 4, 1, 7 };
	QuickSort(arr, 9);
	for (int i = 0; i < 9; ++i){
		cout << arr[i] << " ";
	}
	//for (auto e : v){
	//	cout << e << " ";
	//}
	return 0;
}
