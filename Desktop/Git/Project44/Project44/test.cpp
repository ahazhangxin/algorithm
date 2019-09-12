//#include<iostream>
//#include<vector>
//#include<stdio.h>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	int temp;
//	vector<vector<int>> v;
//	for (int i = 0; i < n; ++i)
//	{
//		vector<int> t;
//		for (int j = 0; j < n; ++j)
//		{
//			cin >> temp;
//			t.push_back(temp);
//		}
//		v.push_back(t);
//	}
//	int res = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		temp = 0;
//		for (int j = 0; j < n; ++j)
//		{
//			temp += v[i][j];
//		}
//		if (res < temp)
//			res = temp;
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		temp = 0;
//		for (int j = 0; j < n; ++j)
//		{
//			temp += v[j][i];
//		}
//		if (res < temp)
//			res = temp;
//	}
//	cout << res << endl;
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//vector<char> v1, v2, pre;
//void GetPre(int root, int left, int right)
//{
//	if (left>right)
//		return;
//	int i = left;
//	while (i<right && v1[i] != v2[root])
//		++i;
//	pre.push_back(v1[root]);
//	GetPre(root - 1 - right + i, left, i - 1);
//	GetPre(root - 1, i + 1, right);
//}
//int main()
//{
//	string s1;
//	string s2;
//	cin >> s1 >> s2;
//
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		v1[i] = s1[i];
//	}
//	for (int i = 0; i < s2.size(); ++i)
//	{
//		v2[i] = s2[i];
//	}
//	GetPre(v1.size() - 1, 0, v1.size());
//	for (int i = 0; i < pre.size(); ++i){
//		cout << pre[i];
//	}
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//vector<int> v1;
//vector<int> v2;
//vector<int> pre;
//
//void Change(int root, int left, int right) {
//	if (left > right) 
//		return;
//	int i = left;
//	while (i < right && v2[i] != v1[root]) i++;
//	pre.push_back(v1[root]);
//	Change(root - 1 - right + i, left, i - 1);
//	Change(root - 1, i + 1, right);
//}
//
//int main() {
//	string s1;
//	string s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	int Size = s1.size();
//	v1.resize(Size);
//	v2.resize(Size);
//	for (int i = 0; i < Size; i++)
//		v1[i] = s1[i];
//	for (int i = 0; i < Size; i++)
//		v2[i] = s2[i];
//	Change(Size - 1, 0, Size - 1);
//	for (int i = 0; i < Size; i++)
//		printf("%c", pre[i]);
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <cstdio>
//
//using namespace std;
//vector<int> bac, in, pre;
//
//void Change(int gen, int start, int end) {
//	if (start > end) return;
//	int i = start;
//	while (i < end && in[i] != bac[gen]) i++;
//	pre.push_back(bac[gen]);
//	Change(gen - 1 - end + i, start, i - 1);
//	Change(gen - 1, i + 1, end);
//}
//
//int main() {
//	string s1, s2;
//	cin >> s1 >> s2;
//	int Size = s1.size();
//	bac.resize(Size);
//	in.resize(Size);
//	for (int i = 0; i < Size; i++)
//		bac[i] = s1[i];
//	for (int i = 0; i < Size; i++)
//		in[i] = s2[i];
//	Change(Size - 1, 0, Size - 1);
//	for (int i = 0; i < Size; i++)
//		printf("%c", pre[i]);
//	cout << endl;
//	return 0;
//}
//#include <iostream>
//#include <vector>
//#include <string> 
//#include <cstdio>
//
//using namespace std;
//vector<int> v1, v2, pre;
//
//void Change(int gen, int start, int end) {
//	if (start > end) return;
//	int i = start;
//	while (i < end && v2[i] != v1[gen]) i++;
//	pre.push_back(v1[gen]);
//	Change(gen - 1 - end + i, start, i - 1);
//	Change(gen - 1, i + 1, end);
//}
//
//int main() {
//	string prev;
//	string inv;
//	getline(cin, inv);
//	getline(cin, prev);
//	int Size = prev.size();
//	v1.resize(Size);
//	v2.resize(Size);
//	for (int i = 0; i < Size; i++)
//		v1[i] = prev[i];
//	for (int i = 0; i < Size; i++)
//		v2[i] = inv[i];
//	Change(Size - 1, 0, Size - 1);
//	for (int i = 0; i < Size; i++)
//		printf("%c", pre[i]);
//	cout << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//
//int array(int* a, int n)
//{
//	int sum = 0;
//	int b = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		if (b < 0)
//		{
//			b = a[i];
//		}
//		else
//		{
//			b += a[i];
//		}
//		if (b > sum)
//		{
//			sum = b;
//		}
//	}
//	return sum;
//}
//int matrix(int** a, int m, int n)
//{
//	int MaxSum = 0;
//	int* b = new int[n];
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			b[j] = 0;
//		}
//		for (int j = i; j < m; ++j)
//		{
//			for (int k = 0; k < n; k++)
//			{
//				b[k] += a[j][k];
//				int sum = array(b, n);
//				if (sum > MaxSum)
//				{
//					MaxSum = sum;
//				}
//			}
//		}
//	}
//	return MaxSum;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int** a = new int*[n];
//	for (int i = 0; i < n; ++i)
//	{
//		a[i] = new int[n];
//		for (int j = 0; j < n; ++j)
//		{
//			cin >> a[i][j];
//		}
//	}
//	cout << matrix(a, n, n);
//	return 0;
//}

//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int array(int* a, int n)
//{
//	int sum = 0;
//	int b = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		if (b < 0)
//		{
//			b = a[i];
//		}
//		else
//		{
//			b += a[i];
//		}
//		if (b > sum)
//		{
//			sum = b;
//		}
//	}
//	return sum;
//}
//int matrix(int** a, int m, int n)
//{
//	int MaxSum = 0;
//	int* b = new int[n];
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			b[j] = 0;
//		}
//		for (int j = i; j < m; ++j)
//		{
//			for (int k = 0; k < n; k++)
//			{
//				b[k] += a[j][k];
//				int sum = array(b, n);
//				if (sum > MaxSum)
//				{
//					MaxSum = sum;
//				}
//			}
//		}
//	}
//	return MaxSum;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int** v = new int*[n];
//	for (int i = 0; i < n; ++i)
//	{
//		v[i] = new int[n];
//		for (int j = 0; j < n; ++j)
//		{
//			cin >> v[i][j];
//		}
//	}
//	cout << matrix(v, n, n);
//	return 0;
//}

#include<iostream>
#include<set>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string temp;
	getline(cin, temp);
	vector<int> v;
	string t;
	for (int i = 0; i < temp.size(); ++i){
		if (temp[i] == ','){
			int count = 0;
			for (int j = 0; j < t.size(); j++){
				if (count > 0)
					count *= 10;
				count += (atoi(t[i]));
			}
			v.push_back(count);
			t.clear();
		}else{
			t += temp[i];
		}
	}
	unique(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; ++i){
		cout << v[i] << ",";
	}
	cout << v[v.size() - 1];
	return 0;
}