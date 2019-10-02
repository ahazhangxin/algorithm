#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

bool CMP(const pair<int, pair<string, string>> & a, const pair<int, pair<string, string>> & b)
{
	return a.first > b.first;
}

int main()
{
	int m;
	cin >> m;
	vector<pair<int, pair<string, string>>> v;
	int p = 0;
	while (m--)
	{
		p++;
		int n;
		cin >> n;
		string s;
		int t;
		string temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> s >> t;
			v.push_back(pair<int, pair<string, string>>(t, pair<string, string>(s, temp)));
		}
		sort(v.begin(), v.end(), CMP);
		int j = 1;
		for (int i = 0; i < v.size(); ++i)
		{
			v[i].second.second += " ";
			v[i].second.second += to_string(p);
			v[i].second.second += " ";
			v[i].second.second += to_string(j);
			j++;
		}
	}
	sort(v.begin(), v.end(), CMP);
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i].second.first << " " << i << " " << v[i].second.second << endl;
	}
	return 0;
}