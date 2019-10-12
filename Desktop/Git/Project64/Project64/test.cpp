#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<ostream>
#include<stdio.h>
using namespace std;
int main()
{
	string s;
	vector<int> v;
	cin >> s;
	int temp = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9'){
			temp *= 10;
			temp += (s[i] - '0');
		}
		if (s[i] == ','){
			v.push_back(temp);
			temp = 0;
		}
	}
	v.push_back(temp);
	s.clear();
	cin >> s;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9'){
			temp *= 10;
			temp += (s[i] - '0');
		}
		if (s[i] == ','){
			v.push_back(temp);
			temp = 0;
		}
	}
	v.push_back(temp);
	double res = 0.0;
	if (v.size() % 2 == 1){
		printf("%d", v[v.size() / 2 + 1]);
	}
	else{
		printf("%d", v[v.size() / 2 + 1] + v[v.size() / 2]);
	}
	return 0;
}