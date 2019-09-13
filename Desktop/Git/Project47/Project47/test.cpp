//while (a<v.size()){
//	if (v[a] == t[b]){
//		a++;
//		b++;
//		num++;
//	}
//	else{
//		a++;
//	}
//}
//
//
//for (pa = n - 1, pb = n - 1; pa >= 0;)//从后面开始比对，已经有序的就不要管了
//{
//	if (v[pa] == t[pb])
//	{
//		pa--;
//		pb--;
//	}
//	else if (v[pa] != t[pb])
//	{
//		ans++;
//		pa--;
//	}
//	if (pa<0)
//		break;
//}
//cout << ans << endl;
//
//
//int a = 0, b = 0;
//int count = 0;
//while (a<v.size()){
//	if (v[a] == t[b]){
//		a++;
//		b++;
//		count++;
//	}
//	else{
//		a++;
//	}
//}
//cout << a - count << endl;


#include <iostream>
#include<vector>
#include<string>
using namespace std;


int stringlenth(string &s, int length)
{
	int i;
	vector<int> res(length, 1);
	for (i = 1; i<length; i++)
	{
		if (s[i] != s[i - 1])
		{
			res[i] = res[i - 1] + 1;
		}

	}
	int maxlong = res[0];
	for (i = 1; i<length; i++)
	{
		if (res[i]>maxlong)
		{
			maxlong = res[i];
		}

	}
	return maxlong;
}


int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int resnum = stringlenth(s, n);
	cout << resnum << endl;
	return 0;
}