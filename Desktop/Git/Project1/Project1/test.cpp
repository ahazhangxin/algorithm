#include <stdio.h> 
#include<iostream>
//int func(int n)
//{
//	if (n < 2)
//		return n;
//	return func(n - 1) + func(n - 2);
//}

//
//int func(int i, int j){
//	if (i <= 0 || j <= 0)
//		return 1;
//	return 2 * func(i - 3, j / 2);
//}
//
//int main()
//{
//	//int t = ROUND(11.56, 0);
//	printf("%d\n", func(15,20));
//
//	return 0;
//}


using namespace std;
//void print(char **str)
//{
//	++str;
//	cout << *str << endl;
//}
//int main()
//{
//	static char *arr[] = { "hello", "world", "c++" };
//	char **ptr;
//	ptr = arr;
//	print(ptr);
//	return 0;
//}


//int main()
//{
//	char *ptr;
//	char arr[] = "12345678";
//	ptr = arr;
//	ptr += 5;
//	printf("%s", ptr);
//	return 0;
//}

//
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int *ptr = (int*)(&a + 1);
//	printf("%d, %d", *(a + 1), *(ptr - 1));
//	return 0;
//}


//#include<iostream> 
//using namespace std;
//class Clock
//{
//public:
//	Clock(int NewH = 0, int NewM = 0, int NewS = 0)
//	{
//		Hour = NewH; Minute = NewM; Second = NewS;
//	}
//	void ShowTime()
//	{
//		cout << Hour << ":" << Minute << ":" << Second;
//	}
//	Clock  operator ++();
//private:
//	int Hour, Minute, Second;
//};
//Clock Clock::operator ++()
//{
//	Second++;
//	if (Second >= 60)
//	{
//		Second = Second - 60;
//		Minute++;
//		if (Minute >= 60)
//		{
//			Minute = Minute - 60;
//			Hour++;
//			Hour = Hour % 24;
//		}
//	}
//	return *this;
//}
//int main()
//{
//	Clock c1;
//	(++c1).ShowTime();
//	return 0;
//}


//
//int main()
//{
//	int x = 5;
//	const int * const p = &x;
//	const int &q = x;
//	int const *next = &x;
//	const int *j = &x;
//	*j++;
//	return 0;
//}

//
//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int n;
//	long long row = 0;
//	long long len = 0;
//	long long MAXrow = 0;
//	long long rMAXrow = 0;
//	long long MAXlen = 0;
//	long long rMAXlen = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> row;
//		if (row >= 0){
//			MAXrow = max(MAXrow, row);
//		}
//		else{
//			row = 0 - row;
//			rMAXrow = max(rMAXrow, row);
//		}
//		cin >> len;
//		if (len >= 0){
//			MAXlen = max(MAXlen, len);
//		}
//		else{
//			len = 0 - len;
//			rMAXlen = max(rMAXlen, row);
//		}
//	}
//	if (MAXrow == 0 && rMAXrow == 0 && MAXlen == 0 && rMAXlen == 0)
//		cout << '1' << endl;
//	string s1, s2;
//
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//
//string MulString(const string &num1)
//{
//	int l1 = num1.size();
//	string res(l1 + l1 , '0');
//	if (l1 == 0)
//		return "";
//	for (int i = l1 - 1; i >= 0; i--){
//		int add = 0;
//		for (int j = l1 - 1; j >= 0; j--){
//			int mul = (num1[i] - '0')*(num1[j] - '0');
//			int sum = res[i + j + 1] + add + mul % 10 - '0';
//			res[i + j + 1] = '0' + sum % 10;
//			add = mul / 10 + sum / 10;
//		}
//		res[i] += add;
//	}
//	for (int i = 0; i<(l1 << 2); i++)
//	if (res[i] != '0')
//		return res.substr(i);
//	return "0";
//}
//
//bool CompareString(const string& s1, const string& s2)
//{
//	int n1 = s1.size();
//	int n2 = s2.size();
//	if (n1 > n2){
//		return true;
//	}
//	if (n1 < n2){
//		return false;
//	}
//	for (int i = 0; i < n1; i++)
//	{
//		if ((s1[i] - '0') >(s2[i] - '0'))
//			return true;
//		if ((s1[i] - '0') < (s2[i] - '0'))
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	int n;
//	long long row = 0;
//	long long len = 0;
//	long long MAXrow = 0;
//	long long rMAXrow = 0;
//	long long MAXlen = 0;
//	long long rMAXlen = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> row;
//		if (row >= 0){
//			MAXrow = max(MAXrow, row);
//		}
//		else{
//			row = 0 - row;
//			rMAXrow = max(rMAXrow, row);
//		}
//		cin >> len;
//		if (len >= 0){
//			MAXlen = max(MAXlen, len);
//		}
//		else{
//			len = 0 - len;
//			rMAXlen = max(rMAXlen, row);
//		}
//	}
//	if (MAXrow == 0 && rMAXrow == 0 && MAXlen == 0 && rMAXlen == 0)
//		cout << '1' << endl;
//	//输出格式，会越界
//	string s1, s2;
//	s1 += to_string(MAXrow + rMAXrow);
//	s2 += to_string(MAXlen + rMAXlen);
//	string res1 = MulString(s1);
//	string res2 = MulString(s2);
//	if (CompareString(res1, res2)){
//		cout << res1 << endl;
//	}
//	else{
//		cout << res2 << endl;
//	}
//	return 0;
//}


/*小明看花，小红好奇*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
#include<stdio.h>
using namespace std;
int main(){
	int m, n;
	while (cin >> n >> m){
		vector<int> a(n);
		for (int i = 0; i < n; ++i){
			scanf_s("%d", &a[i]);
		}
		vector<vector<int>> ans(n, vector<int>(n, 1)); // ans[i][j] 表示从时间[i + 1， j + 1]看了几种花，其中i <= j;
		for (int i = 0; i < n; ++i){
			unordered_set<int> set_a;
			set_a.insert(a[i]);
			for (int j = i; j < n; ++j){
				set_a.insert(a[j]);
				ans[i][j] = set_a.size();
			}
		}
		int Q;
		cin >> Q;
		while (Q--){
			int l, r;
			scanf("%d %d", &l, &r);
			//printf("%d\n",ans[l - 1][r - 1]);
			//cin >> l >> r;
			cout << ans[l - 1][r - 1] << endl;
		}
	}
	return 0;
}