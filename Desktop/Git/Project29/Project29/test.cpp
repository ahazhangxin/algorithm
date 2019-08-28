#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v;
	vector<char> v1;
	int n;
	cin >> n;
	if (n == 1)
	{
		int temp;
		cin >> temp;
		cout << temp;
	}
	int tmp1;
	char tmp2;
	string res = "";
	int start = 0;
	int end = 0;
	int temp;
	cin >> temp;
	v.push_back(temp);
	for (int i = 0; i < n; ++i)
	{
		char sign;
		cin >> sign;
		int tmp;
		cin >> tmp;
		switch (sign)
		{
		case '*':
			res += sign;
			break;
		case'+':
			if (res.back() != '/' || res.back() != '-')
			{
				sort(v.begin(), v.end());

			}
			res += sign;
			break;
		case'/':
			v.push_back(tmp);
			res += sign;
			break;
		case'-':
			v.push_back(tmp);
			res += sign;
			break;
		}
		
	}
	return 0;
}
