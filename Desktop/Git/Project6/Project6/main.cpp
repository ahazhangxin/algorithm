
//int main(){
//	string x;
//	while (cin >> x)
//	{
//		stack<char> q;
//		for (int i(0); i<x.size(); i++)
//		{
//			if (x[i] != ']')
//				q.push(x[i]);
//			else
//			{
//				string tmp;
//				while (q.top() != '|')
//				{
//					tmp = q.top();
//					q.pop();
//				}
//				q.pop();
//				int bt(0);
//				for (int i(1); q.top() != '['; i *= 10)
//				{
//					bt += (q.top() - '0')*i;
//					q.pop();
//				}
//				q.pop();
//				for (int i(0); i < bt; i++)
//				{
//					for (int j(tmp.size() - 1); j >= 0; j--)
//					{
//						q.push(tmp[j]);
//					}
//				}
//			}
//		}
//		string ans(q.size(), ' ');
//		for (int i(ans.size() - 1); i >= 0; i--)
//		{
//			ans[i] = q.top();
//			q.pop();
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}



//腾讯第一次笔试题第一道
/*
*	压缩算法
*	如将HG[3|B[2|CA]]F解压为
*	HGBCACABCACABCACAF

*/


//#include<iostream>
//#include<string>
//#include<stack>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	string str;
//	stack<char> q;
//	cin >> str;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] != ']')
//			{
//				q.push(str[i]);
//			}
//			else
//			{
//				string tmp;
//				while (q.top() != '|')
//				{
//					tmp += q.top();
//					q.pop();
//				}
//				reverse(tmp.begin(), tmp.end());
//				q.pop();
//				int count = 0;
//				for (int i = 1; q.top() != '['; i *= 10)
//				{
//					count += (q.top() - '0')*i;
//					q.pop();
//				}
//				q.pop();
//
//				for (int i = 0; i < count; i++)
//				{
//					for (int j = 0; j < tmp.size(); j++)
//					{
//						q.push(tmp[j]);
//					}
//				}
//
//			}
//		}
//	string result(q.size(), ' ');
//	for (int i = result.size() - 1; i >= 0; i--)
//	{
//		result[i] = q.top();
//		q.pop();
//	}
//	cout << result << endl;
//	return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n, l;
	cin >> n >> l;
	vector<pair<int, int> >all(n);
	for (int i(0); i<n; i){
		cin >> all[i].first >> all[i].second;
	}
	//仿函数排序
	auto cmp = [](pair<int, int>a, pair<int, int>b) -> bool{ return a.first == b.first ? a.second > b.second : a.first < b.first; };
	sort(all.begin(), all.end(), cmp);
	int tmp(0), i(0), ans(0);
	for (int i(0); tmp < l && i < n; ){
		ans++;
		int s = tmp;
		for (; all[i].first <= s && i < n; i++)
		{
			tmp = max(all[i].second, tmp);
		}
		if (tmp == s && tmp < l)
			break;
	}
	if (tmp >= l)
		cout << ans << endl;
	else 
		cout << -1 << endl;
	return 0;
}