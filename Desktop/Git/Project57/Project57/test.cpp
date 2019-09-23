#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;
bool cmp1(const pair<string,int>&a, const pair<string,int>& b)
{
	return a.second > b.second;
}
int main()
{
	string s;
	unordered_set<string> us;
	map<string, int> mp;
	getline(cin, s);
	for (int j = 0; j < s.size(); ++j)
	{
		string temp1 = "";
		string temp2 = "";
		bool sign = true;
		while ( j < s.size() && s[j] != ' ')
		{
			temp1 += s[j];
			if (s[j] == '-'){
				sign = false;
			}
			else if(!sign){
				temp2 += s[j];
			}
			++j;
		}
			
		if ( us.end() == us.find(temp1))
		{		
			us.insert(temp1);
			mp[temp2]++;
		}

	}
	vector<pair<string, int>> v;
	for (auto e : mp)
	{
		v.push_back(pair<string, int>(e.first, e.second));
	}
	sort(v.begin(), v.end(), cmp1);
	for (int i = 0; i < 3; ++i)
	{
		cout << v[i].first << " " << v[i].second << endl;
	}
	return 0;
}