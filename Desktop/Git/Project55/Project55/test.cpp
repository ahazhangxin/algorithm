//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//bool IsTeleNumber(string s)
//{
//	int count = 0;
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if ((s[i] - '0') == 8)
//			count++;
//	}
//	if (count >= 11)
//		return true;
//	return false;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<pair<int, string>> v;
//	string s;
//	int temp;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> temp;
//		cin >> s;
//		v.push_back(pair<int, string>(temp, s));
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		if (v[i].first < 11)
//			cout << "NO" << endl;
//		else{
//			if (IsTeleNumber(v[i].second))
//			{
//				cout << "YES" << endl;
//			}
//			else{
//				cout << "NO" << endl;
//			}
//		}
//	}
//	return 0;
//}
//
//
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;  
//	string v;
//	for (int i = 0; i < n; ++i)
//	{
//		int p, q;
//		cin >> p >> q;
//		for (int j = 0; j < p; ++j)
//		{
//			v.push_back(q);
//		}
//	}
//	sort(v.begin(), v.end());
//	int res = 0;
//	for (int i = 0; i < v.size(); ++i)
//	{
//		if ((v[i] + v[v.size() - i - 1]) > res)
//			res = (v[i] + v[v.size() - i - 1]);
//	}
//	cout << res << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v;
//	vector<pair<int, int>> res;
//	while (n--){
//		int m;
//		cin >> m;
//		int temp;
//		for (int i = 0; i < m; ++i)
//		{
//			cin >> temp;
//			v.push_back(temp);
//		}
//		sort(v.begin(), v.end());
//		int n1 = 0, n2 = 0;
//		for (int i = 0; i < m; ++i){
//			if (i % 2 == 0)
//				n1 += v[i];
//			else
//				n2 += v[i];
//		}
//		if (n1 > n2){
//			res.push_back(pair<int, int>(n2, n1));
//		}
//		else{
//			res.push_back(pair<int, int>(n1, n2));
//		}
//		v.clear();
//	}
//	for (int i = 0; i < res.size(); ++i){
//		cout << res[i].first << " " << res[i].second << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v;
//	vector<pair<int, int>> res;
//	while (n--){
//		int m;
//		cin >> m;
//		int temp;
//		for (int i = 0; i < m; ++i)
//		{
//			cin >> temp;
//			v.push_back(temp);
//		}
//		sort(v.begin(), v.end());
//		int n1 = 0, n2 = 0;
//		for (int i = 0; i < m / 2; ++i){
//			if (i % 2 == 0)
//				n1 += (v[i] + v[v.size() - i - 1]);
//			else
//				n2 += (v[i] + v[v.size() - i - 1]);
//		}
//		if (n1 > n2){
//			res.push_back(pair<int, int>(n2, n1));
//		}
//		else{
//			res.push_back(pair<int, int>(n1, n2));
//		}
//		v.clear();
//	}
//	for (int i = 0; i < res.size(); ++i){
//		cout << res[i].first << " " << res[i].second << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v;
//	vector<pair<int, int>> res;
//	while (n--){
//		int m;
//		cin >> m;
//		int temp;
//		for (int i = 0; i < m; ++i)
//		{
//			cin >> temp;
//			v.push_back(temp);
//		}
//		sort(v.begin(), v.end());
//		reverse(v.begin(), v.end());
//		int n1 = v[0], n2 = 0;
//		for (int i = 1; i < m; i++)
//		{
//			if (n1>n2) n2 += v[i];
//			else n1 += v[i];
//		}
//
//
//		if (n1 > n2){
//			res.push_back(pair<int, int>(n2, n1));
//		}
//		else{
//			res.push_back(pair<int, int>(n1, n2));
//		}
//		v.clear();
//	}
//	for (int i = 0; i < res.size(); ++i){
//		cout << res[i].first << " " << res[i].second << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	vector<int> v;
//	int temp;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> temp;
//		v.push_back(temp);
//	}
//	sort(v.begin(), v.end());
//	while (k--)
//	{
//		int i = 0;
//		bool sign = true;
//		while (i < n)
//		{
//			if (v[i] == 0){
//				i++;
//				continue;
//			}
//
//			cout << v[i] << endl;
//			bool sign = false;
//			int t = v[i];
//			for (int j = 0; j < v.size(); ++j)
//			{
//				if ((v[j] - t) < 0 || (v[j] == 0))
//				{
//					v[j] = 0;
//					continue;
//				}
//				else{
//					v[j] -= t;
//				}
//				
//			}
//		}
//		if (i == n && sign)
//			cout << 0 << endl;
//	}
//	return 0;
//}

#include<iostream>
using namespace std;
int main()
{
	short* ptr = (short*)0;
	ptr = ptr + 1;
	cout << ptr << endl;
	return 0;
}
