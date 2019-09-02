//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//
//int main()
//{
//	int len = s.size();
//	if (len == 0 || len == 1)
//		return s;
//	int start = 0;//回文串起始位置
//	int max = 1;//回文串最大长度
//	vector<vector<int>>  dp(len, vector<int>(len));//定义二维动态数组
//	for (int i = 0; i<len; i++)//初始化状态
//	{
//		dp[i][i] = 1;
//		if (i<len - 1 && s[i] == s[i + 1])
//		{
//			dp[i][i + 1] = 1;
//			max = 2;
//			start = i;
//		}
//	}
//	for (int i = 3; i <= len; i++)//i表示检索的子串长度，等于3表示先检索长度为3的子串
//	{
//		for (int j = 0; i + j - 1 < len; j++)
//		{
//			int k = i + j - 1;//终止字符位置
//			if (s[j] == s[k] && dp[j + 1][k - 1] == 1)//状态转移
//			{
//				dp[j][k] = 1;
//				start = j;
//				max = i;
//			}
//		}
//	}
//	return s.substr(start, max);//获取最长回文子串
//	return 0;
//}


#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	int count = 0;
	if (m == 1)
	{
		for (auto e : v)
			count += *e;
	}
	while (1)
	{

	}
	cout << n << endl;
}