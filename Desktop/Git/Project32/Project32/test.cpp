#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v = { n, vector<int> };
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	return 0;
}