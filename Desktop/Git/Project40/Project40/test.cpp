/*
第一题： 现有两个从小到大排好序的 int 数组（每个数组自身没有重复元素）。
请找出所有在 这两个数组中都出现过的数。请写一个函数，输入为两个数组。
*/

//#include<iostream>
//#include<vector>
//using namespace std;
//vector<int> GetSameNum(const vector<int>& v1,const vector<int>& v2)
//{
//	vector<int> res;
//	//如果两个数组中有一个空数组，那么就直接返回-1，避免无意义的操作
//	if (v1.empty() || v2.empty())
//		return res;
//	int i = 0, j = 0;
//	while (i < v1.size() && j < v2.size())
//	{
//		//两个数组同时向后走，每次移动较小数字的下标
//		if (v1[i]>v2[j]){
//			j++;
//		}else if (v1[i]<v2[j]){
//			i++;
//		}else{
//			res.push_back(v1[i]);
//			//因为数组中没有相同的数字，所以每次碰到相同大小的数字两个数组都需要同时向后移动
//			++i; ++j;
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	//vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	//vector<int> v1 = { 1 };
//	vector<int> v1 = {};
//	vector<int> v2 = { 4, 5, 6, 7, 8, 9, 10 };
//	vector<int> t = GetSameNum(v1, v2);
//	return 0;
//}


/*
第二题： 小马过河： 
如图所示，有一个 N 行 M 列的棋盘格，有个国际象棋里的马要从这个棋盘格的第一行 跳到最后一行。
要求这匹马只能从上往下跳，不能倒着跳，即只能跳往下一行或者下 面第二行。 
每个格子上有一个数字，请为小马寻找一条路径，要求路径上所有数之和最小。 
小马可以从第一行的任意某个格子开始，也必须到最后一 行 的某个格子结束。
输入：一个 NxM 的矩阵 输出：一个数字，这条路径上所有数之和。 
附加题（文字阐述你的思路即可，无需代码）： 如果允许小马往回跳，算法有什么不同？
*/

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main(){
//	int n, m;
//	cin >> n >> m;
//	int temp;
//	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
//	for (int i = 0; i < dp.size(); ++i)
//	{
//		for (int j = 0; j < dp[0].size(); ++j)
//		{
//			cin >> temp;
//			dp[i][j] = temp;
//		}
//	}
//	int res = 0;
//	int x = 0;
//	int y = (int)(std::min_element(dp[0].begin(), dp[0].end()) - dp[0].end());
//	res += dp[x][y];
//	while (x < n)
//	{
//		int one = min(dp[x + 1][y - 2], dp[x + 1][y + 2]);
//		int two = min(dp[x + 2][y - 1], dp[x + 2][y + 1]);
//		if (one <= two){
//			//小马走向下一层
//			if (dp[x + 1][y - 2] < dp[x + 1][y + 2]){
//				x += 1; y -= 2;
//			}else{
//				x += 1; y += 2;
//			}
//		}else{
//			//小马走向下两层
//			if (dp[x + 2][y - 1] < dp[x + 2][y + 1]){
//				x += 2; y -= 1;
//			}
//			else{
//				x += 2; y += 1;
//			}
//		}
//		res += dp[x][y];
//	}
//	cout << res;
//	return 0;
//}


/*
第三题： 
“斗牛”是一种热门的扑克游戏，每个人 5 张牌，其中 A 当 1，JQK 都当 10。
要求： 从 5 张牌中选出 3 张牌（必须刚好 3 张），
如果存在 3 张牌加起来是 10 或者 20 或者 30，就称为“有牛”，否则就是“没牛”。 
有牛的情况下，剩余两张牌加起来除以 10 后：  余数为 0 就是“牛牛”，是最大的一手牌。  
如果余数为 9 就是“牛九”，是第二大的，依次类推，“牛一”就是最小。  
“有牛”都大于“没牛”。  
两人都是没牛的情况下，比最大的一张牌谁大（注意 A 最大，2 最小），最大 一张牌一样则比较第二张牌，依次类推。 
请写一段代码，验证两手牌哪一个最大。 
输入是长度为 5 的两个字符串，表示两手牌。
字符串内容是 23456789TJQKA，
注意为 了让字符串长度一致，我们用 T 代表 10。 
请输出一个值：1 表示第一手牌大，-1 表示后一手牌更大，0 表示一样大。 
示例： 输入 "4579K", "AAAA2", 输出：1 
因为 4+7+9=20（有牛），剩下两张牌 5+K 是牛五，后一手牌没牛，所以前者更大。
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int Bullfight(string s1, string s2)
{
	vector<int> v1;
	vector<int> v2;
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < s1.size(); ++i)
	{
		if (s1[i] == 'T')
		{
			v1.push_back(10);
		}
		else if (s1[i] <= 9 && s1[i] >= 1){
			v1.push_back(s1[i]);
		}
		else if(s1[i] == 'A'){
			v1.push_back(1);
		}
		else
		{
			v1.push_back(10);
		}
		count1 += v1[i];
	}

	for (int i = 0; i < s2.size(); ++i)
	{
		if (s2[i] == 'T')
		{
			v2.push_back(10);
		}
		else if (s2[i] <= 9 && s2[i] >= 1){
			v2.push_back(s2[i]);
		}
		else if (s2[i] == 'A'){
			v2.push_back(1);
		}
		else
		{
			v2.push_back(10);
		}
		count2 += v2[i];
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int temp1 = count1;
	for (int i = 0; i < v1.size(); ++i)
	{
		for (int j = i + 1; j < v1.size(); ++j)
		{
			for (int k = j + 1; k < v1.size(); ++k)
			{
				if ((v1[i] + v1[j] + v1[k] == 10) || (v1[i] + v1[j] + v1[k] == 20) || (v1[i] + v1[j] + v1[k] == 30))
				{
					temp1 = count1 - v1[i] - v1[j] - v1[j];
					goto breakLoop1;
				}
			}
		}
	}
breakLoop1: 
	if (temp1 != count1){
		count1 = temp1;
		temp1 %= 10;
	}

	int temp2 = count2;
	for (int i = 0; i < v2.size(); ++i)
	{
		for (int j = i + 1; j < v2.size(); ++j)
		{
			for (int k = j + 1; k < v2.size(); ++k)
			{
				if ((v2[i] + v2[j] + v2[k] == 10) || (v2[i] + v2[j] + v2[k] == 20) || (v2[i] + v2[j] + v2[k] == 30))
				{
					temp2 = count1 - v2[i] - v2[j] - v2[j];
					goto breakLoop2;
				}
			}
		}
	}
breakLoop2:
	if (temp2 != count2){
		count2 = temp2;
		temp2 %= 10;
	}

	if (temp1 != count1 && temp2 != count2){
		if (temp1 == 1 && temp2 == 1)
		{
			return 0;
		}
		else if (temp1 == 1 && temp2 != 1)
		{
			return 1;
		}
		else if (temp1 != 1 && temp2 == 1)
		{
			return -1;
		}
		else{
			if (temp1 == temp2)
				return 0;
			return temp1 > temp2 ? 1 : -1;
		}
	}
	else if (temp1 != count1 && temp2 == count2)
	{
		return 1;
	}
	else if (temp1 == count1 && temp2 != count2){
		return -1;
	}
	else{
		for (int i = 0; i < 5; ++i)
		{
			if (v1[i] == 1 && v2[i] == 1)
			{
				continue;
			}
			else if (v1[i] == 1 && v2[i] != 1)
			{
				return 1;
			}
			else if (v1[i] != 1 && v2[i] == 1)
			{
				return -1;
			}
			else
			{
				if (v1[i] == v2[i])
					continue;
				return v1[i] > v2[i] ? 1 : 0;
			}
		}
	}

}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int res = Bullfight(s1, s2);
	return 0;
}