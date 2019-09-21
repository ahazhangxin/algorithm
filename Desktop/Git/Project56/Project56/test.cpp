//#include<iostream>
//#include<map>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	map<int, int> mp;
//	int temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		mp[temp]++;
//	}
//	while (cin >> temp){
//		cout << mp[temp] << endl;
//	}
//	return 0;
//}

//
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int GetMaxElement(vector<int> v, int left, int m)
//{
//	int right = left + m-1;
//	if (left > (v.size() - 1))
//		left--;
//	if (right > (v.size() - 1))
//		right = v.size() - 1;
//	while (left < right)
//	{
//		if (v[left]>v[right])
//			right--;
//		else if (v[left] < v[right])
//			left++;
//		else
//			left++;
//	}
//	return left;
//}
//
//
//int main()
//{
//	int T;
//	cin >> T;
//	while (T--)
//	{
//		int n, m;
//		cin >> n >> m;
//		vector<int> v;
//		bool sign = true;
//		int temp;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> temp;
//			v.push_back(temp);
//		}
//		int left = 0;
//		while (left < n)
//		{
//			int t;
//			if ((left + m) < n)
//				t = GetMaxElement(v, left + 1, m);
//			else
//				t = GetMaxElement(v, left + 1, m);
//
//			if (v[left] > v[t])
//				left = t;
//			else if (sign && v[left] < v[t]){
//				left = t;
//				sign = false;
//			}
//			else
//			{
//				break;
//			}
//
//		}
//		if ((left == (n-1)) && v[left] >= v[n - 1])
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//
//
//	}
//	return 0;
//}


#include<iostream>
#include<vector>
using namespace std;
int compute(int stair){
	vector<int> v(stair+3, 0);
	v[0] = 0;
	v[1] = 1;
	v[2] = 1;
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = v[i - 1] + v[i - 2];
	}
	
}

int main()
{
	int n = compute(100);
	return 0;
}