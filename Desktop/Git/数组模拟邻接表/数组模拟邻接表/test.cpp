///*体育场突然着火了，现场需要紧急疏散，但是过道真的是太窄了，同时只能容许一个人通过。现在知道了体育场的所有座位分布，座位分布图是一棵树，已知每个座位上都坐了一个人，安全出口在树的根部，也就是1号结点的位置上。其他节点上的人每秒都能向树根部前进一个结点，但是除了安全出口以外，没有任何一个结点可以同时容纳两个及以上的人，这就需要一种策略，来使得人群尽快疏散，问在采取最优策略的情况下，体育场最快可以在多长时间内疏散完成。
//
//
//输入描述:
//第一行包含一个正整数n，即树的结点数量（1<=n<=100000）。 接下来有n-1行，每行有两个正整数x，y，表示在x和y结点之间存在一条边。(1<=x，y<=n)
//
//输出描述:
//输出仅包含一个正整数，表示所需要的最短时间
//
//输入例子1:
//6
//2 1
//3 2
//4 3
//5 2
//6 1
//
//输出例子1:
//4
//*/
//
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//const int N = 1e5 + 10, M = N * 2;
//struct Edge {
//	int to, next;
//} edge[M];
//
//int head[N], idx, n;
//
//void add(int a, int b)
//{
//	edge[idx].to = b;
//	edge[idx].next = head[a];
//	head[a] = idx++;
//}
////深度优先
//int dfs(int u, int fa)
//{
//	int res = 1;
//	for (int i = head[u]; ~i; i = edge[i].next)
//	{
//		if (edge[i].to != fa) res += dfs(edge[i].to, u);
//	}
//	return res;
//}
//
//
//int main()
//{
//	cin >> n;
//	memset(head, -1, sizeof head);
//	for (int i = 0; i < n - 1; ++i)
//	{
//		int a, b;
//		cin >> a >> b;
//		add(a, b), add(b, a);
//	}
//	int res = 0;
//	for (int i = head[1]; ~i; i = edge[i].next)
//		res = max(res, dfs(edge[i].to, 1));
//	cout << res << endl;
//	return 0;
//}
//
//
//
//
//
//
///*
//
//int q[N];
//bool visited[N];
//int bfs(int u)
//{
//	int hh = 0, tt = 0;
//	q[0] = u;
//	visited[u] = true;
//	while (hh <= tt)
//	{
//		int t = q[hh++];
//		for (int i = head[t]; ~i; i = edge[i].next)
//		{
//			int son = edge[i].to;
//			if (!visited[son])
//			{
//				q[++tt] = son;
//				visited[son] = true;
//			}
//		}
//	}
//	return tt + 1;
//}
//int main()
//{
//	...
//		visited[1] = true;
//	for (int i = head[1]; ~i; i = edge[i].next)
//		res = max(res, bfs(edge[i].to));
//	cout << res << endl;
//	return 0;
//}
//*/
//
///*给出m个字符串S1，S2，...，Sm和一个单独的字符串T。请在T中选出尽可能多的子串同时满足： 
//1）这些子串在T中互不相交。
//2）这些子串都是S1，S2，...，Sm中的某个串。  问最多能选出多少个子串。
//
//
//输入描述:
//第一行一个数m（1≤m≤10），接下来m行，每行一个串。最后一行输入一个串T。输入中所有单个串的长度不超过100000，串中只会出现小写字母。
//
//输出描述:
//输出一个数，最多能选出多少串。
//
//输入例子1:
//3
//aa
//b
//ac
//bbaac
//
//输出例子1:
//3*/
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int maxCount(vector<string>& sub, string& src) {
//	vector<int> result(src.length() + 1, 0);
//	sort(sub.begin(), sub.end(), [](string& s1, string& s2)->bool {return s1.length() < s2.length(); });
//	int maxLen;
//	for (int i = 1; i <= src.length(); i++) {
//		maxLen = 0;
//		for (int j = 0; j < sub.size() && sub[j].length() <= i; j++) {
//			int k = sub[j].length() - 1;
//			for (; k >= 0; --k) {
//				if (sub[j][k] != src[i - sub[j].length() + k]) {
//					break;
//				}
//			}
//			if (k == -1) {
//				maxLen = result[i - sub[j].length()] + 1;
//				break;
//			}
//		}
//		result[i] = max(maxLen, result[i - 1]);
//	}
//	return result[src.length()];
//}
//
//
//int main() {
//	int nums;
//	vector<string> subStrs;
//	string terget;
//
//	cin >> nums;
//	for (int i = 0; i < nums; i++) {
//		cin >> terget;
//		subStrs.push_back(terget);
//	}
//	cin >> terget;
//	cout << maxCount(subStrs, terget);
//}
//
//#define _CRT_SECURE_NO_WARNINGS
//
//#include<string.h>
//#include<stdio.h>
//int main(void)
//{
//	char input[16] = "abc,d";
//	char*p;
//	/*strtok places a NULL terminator
//	infront of the token,if found*/
//	p = strtok(input, ",");
//	if (p)
//		printf("%s\n", p);
//	/*Asecond call to strtok using a NULL
//	as the first parameter returns a pointer
//	to the character following the token*/
//	p = strtok(NULL, ",");
//	if (p)
//		printf("%s\n", p);
//	return 0;
//
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<stdio.h>
//#include<string>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	string type;
//	int res = 0;
//	type = strtok(s.c_str(), ".");
//	while (!type.empty())
//	{
//		res += atoi(type.c_str());
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//bool isSushu(int n)
//{
//	for (int i = 2; i < n; ++i){
//		if (n % i == 0)
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int a, b;
//	for (int j = 6; j <= n; j+=2)
//	{
//		for (a = 3; a <= j / 2; a++)
//		{
//			if (isSushu(a)){
//				b = j - a;
//				if (isSushu(b))
//					cout << j << "=" << a << "+" << b << endl;
//			}
//		}
//	}
//
//	return 0;
//}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> mem;

int max_three(int a, int b, int c){
	return max(a, max(b, c));
}
//int _IntegerBreak(int n){
//	int res = -1;
//	if (n == 1)
//		return 1;
//
//	for (int i = 1; i<n; ++i)
//	{
//		res = max_three(res, i*(n - i), i*_IntegerBreak(n - i));
//	}
//	return res;
//}
int _IntegerBreak(int n)
{
	if (n == 1)
		return 1;
	if (mem[n] != -1)
		return mem[n];

	int res = -1;
	for (int i = 1; i <= n - 1; ++i)
		res = max_three(res, i*(n - i), i*_IntegerBreak(n - i));
	mem[n] = res;
	return res;
}


int integerBreak(int n)
{
	
	vector<int> res(n + 1, -1);
	res[1] = 1;
	for (int i = 2; i <= n; ++i){
		for (int j = 1; j <= i - 1; ++j){
			res[i] = max_three(res[i], j*(i - j), j*res[i - j]);
		}
		return res[n];
	}
}
int main()
{
	int n;
	cin >> n;
	_IntegerBreak(n);
	return 0;
}