#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> m;
	m.reserve(n);

	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		m.push_back(temp);
	}
	sort(m.begin(), m.end());
	int p = 0, q = 0;
	for (int i = 0; i < n; i++)
	{
		if (i & 1)
		{
			p += m[i];
		}
		else
		{
			q += m[i];
		}
	}
	cout << p - q << endl;
	return 0;
}