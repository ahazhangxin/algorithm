////#include <iostream>
////#include <string>
////#include <vector>
////#include <algorithm>
////using namespace std;
////void SplitString(string str) 
////{
////	int last[26] = {};
////	for (int i = str.size() - 1; i >= 0; --i)
////	{
////		if (last[str[i] - 'a'] == 0)
////			last[str[i] - 'a'] = i;
////	}
////	vector<int> v;
////	int i = 0;
////	while (i < str.size())
////	{
////		int j = i;
////		int MAX = last[str[i] - 'a'];
////		while (j <= MAX)
////		{
////			MAX = max(MAX, last[str[j] - 'a']);
////			j++;
////		}
////		v.push_back(j - i);
////		i = j;
////	}
////	int index = 0;
////	for (int i = 0; i < v.size(); ++i)
////	{
////		cout << str.substr(index, v[i]) << endl;
////		index += v[i];
////	}
////}
////int main()
////{
////	string s = "aabbbacceddefgkifk";
////	SplitString(s);
////	return 0;
////}
//
//
////
////#include <iostream>
////#include <math.h>
////#include <vector>
////using namespace std;
////int pack(const vector<int>& v, int n, int m)
////{
////	vector<vector<int>> src(n + 1, vector<int>(m + 1, 0));
////	int tmp = 0, sub = 0;
////	int i, j;
////	for (i = 0; i < n; i++)
////	{
////		for (j = 0; j <= m; j++)
////		{
////			if (j == 0)
////			{
////				src[i][j] = 0;
////			}
////			else if (i <= j * 2 - 2)
////			{
////				src[i][j] = 0;
////			}
////			else
////			{
////				if (i == 1)
////				{
////					src[i][j] = tmp;
////				}
////				else
////				{
////					if ((tmp + src[i - 2][j - 1]) < src[i - 1][j])
////					{
////						src[i][j] = tmp + src[i - 2][j - 1];
////					}
////					else
////					{
////						src[i][j] = src[i - 1][j];
////					}
////				}
////
////			}
////		}
////		
////		tmp = (int)pow((v[i] + v[i - 1]), 4);
////	}
////	return src[n - 1][m];
////}
////
////
////int main()
////{
////	int n, m;
////	cin >> n >> m;
////	int temp;
////	vector<int> v;
////	for (int i = 0; i < n; i++)
////	{
////		cin >> temp;
////		v.push_back(temp);
////	}	
////	cout << pack(v, n, m) << endl;
////	return 0;
////}
//
//
//#include<iostream>
//#include<sstream>
//#include<vector>
//#include<string>
//#include<map>
//#include<algorithm>
//using namespace std;
//struct PersonInfo
//{
//	string name;
//	vector<string> phones;
//};
//void Find(vector<char> vec, vector<int>& flag, int len, vector<string>& res, string &s, int num)
//{
//	for (int i = 0; i < len; ++i)
//	{
//		if (flag[i] == 0)
//		{
//			s += vec[i];
//			if (num == 1) //记录遍历的数字个数，如果是最后一个数字了，则压入res中
//			{
//				res.emplace_back(s);
//				s.erase(s.end() - 1, s.end());//删除最后一位，返回
//				return;
//			}
//			else
//			{
//				flag[i] = 1;
//				Find(vec, flag, len, res, s, num - 1);
//				s.erase(s.end() - 1, s.end());//删除当前一位，进行下一索引数字的遍历
//				flag[i] = 0;
//			}
//		}
//	}
//
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<char> vec;
//	stringstream ss;
//	char tmp;
//	while (n != 0)
//	{
//		ss << (n % 10);
//		ss >> tmp;
//		vec.emplace_back(tmp);  //存入一个容器中
//		n = n / 10;
//	}
//	int len = vec.size();
//	vector<int> flag;
//	vector<string> res;
//	string s;
//	for (int i = 0; i < len; ++i)
//	{
//		flag.emplace_back(0);//数字标志位，如果遍历过此数字，则标为1，否则为0
//	}
//	string s1;
//	for (int i = len - 1; i >= 0; --i)
//		s1 += vec[i];
//	Find(vec, flag, len, res, s, len);
//
//	sort(res.begin(), res.end());
//	res.erase(unique(res.begin(), res.end()), res.end()); //删除相同的数字
//	int j = 0;
//	for (; j < res.size(); ++j)
//	{
//		if (res[j] == s1)
//			break;
//	}
//	if (j == res.size() - 1)
//		cout << -1 << endl;
//	else
//		cout << res[j + 1];
//	system("pause");
//	return 0;
//}
//
//
//#include<iostream>
//#define divide(a,b)a/b
//using namespace std;
//struct Hellobike
//{
//	int m_ilD;
//	char m_chFlag;
//	union
//	{
//		int m_wKa;
//		int m_wKb;
//	}key;
//}hb;
//
//int main()
//{
//	
//	return 0;
//}


//#include<iostream>
//using namespace std;
//void MyStrcpy(char *des, char *src)
//{
//	while (*src != '\0')
//	{
//		*des++ = *src++;
//	}
//	*des = '\0';
//}
//
//int main()
//{
//	char str1[] = "";
//	char str2[] = "";
//	cin >> str2;
//	MyStrcpy(str1, str2);
//	cout << str1 << endl;
//	return 0;
//}



#include<stdio.h>
#include<string.h>


void* MemCpy(void *dest, const void *src, size_t count)
{
	char*p = (char*)dest;
	char*p1 = (char*)src;
	while (count--)
		*p++ = *p1++;
	return dest;
}

int main()
{
	char s[20] = { 0 };
	char*p = "aabbcc";
	MemCpy(s, p, strlen(p));
	return 0;
}