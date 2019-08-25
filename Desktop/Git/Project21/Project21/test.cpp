#include<iostream>
#include<map>
#include<set>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	multimap<int, int> boy;
	multimap<int, int> girl;
	int temp1, temp2;
	for (int i = 0; i < m; i++)
	{
		cin >> temp1 >> temp2;
		
		if (temp1 <= n)
		{
			boy.insert(make_pair(temp1, temp2));
			girl.insert(make_pair(temp2, temp1));
		}
		else
		{
			boy.insert(make_pair(temp2, temp1));
			girl.insert(make_pair(temp1, temp2));
		}
	}
	set<int> b;
	set<int> g;
	for (auto it = boy.begin();it != boy.end(); ++it)
	{
		b.insert(it->first);
	}
	for (auto it = girl.begin(); it != girl.end(); ++it)
	{
		g.insert(it->first);
	}

	if (b.size() > g.size())
	{
		cout << g.size() << endl;
		for (auto it = g.begin(); it != g.end(); ++it)
		{
			cout << *it << endl;
		}
	}
	else
	{
		cout << b.size() << endl;
		for (auto it = b.begin(); it != b.end(); ++it)
		{
			cout << *it << endl;
		}
	}
	return 0;
}


//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<long long> v;
//	v.reserve(n);
//	int temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		v.push_back(temp);
//	}
//	long long MIN = 999999999;
//	for (int i = n - 1; i > 0; i--)
//	{
//		if (v[i] >= v[i - 1])
//		{
//			if (MIN < v[i - 1])
//				MIN = v[i];
//		}
//	}
//	int count = 0;
//	for (int i = n - 1; i > 0; i--)
//	{
//		if (v[i] <= v[i - 1] || MIN > v[i - 1])
//		{
//			count++;
//		}
//
//	}
//	cout << count;
//	return 0;
//}
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<long long> v;
//	v.reserve(n);
//	int temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		v.push_back(temp);
//	}
//	int count = 0;
//	for (int i = n - 1; i > 0; i--)
//	{
//		if (v[i] <= v[i - 1])
//			count++;
//	}
//	cout << count;
//	return 0;
//}