//#include<iostream>
//#include<string>
//#include<stack>
//
//using namespace std;
//
//int main()
//{
//	stack<char> s;
//	string str;
//	string result;
//	cin >> str;
//	if (str.empty())
//		return;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] != '[' || str[i] != ']' || str[i] != '|')
//		{
//			result += str[i];
//		}
//		else if (str[i] == '[')
//		{
//
//		}
//		else
//		{
//
//		}
//	}
//
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int n, L;
//	cin >> n >> L;
//	vector<int> v;
//	v.resize(n);
//	int n1, n2;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> n1 >> n2;
//		v[i] = n2 - n1;
//	}
//	sort(v.begin(), v.end());
//	reverse(v.begin(), v.end());
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		count += v[i];
//		if (count >= L)
//		{
//			cout << i+1 << endl;
//			return 0;
//		}
//	}
//	cout << '-1' << endl;
//	return 0;
//}



#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.reserve(n);
	vector<int> result;
	result.reserve(n);
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		v.push_back(t);
	}
	int count1;
	int count2;
	for (int i = 0; i < n; i++)
	{
		count1 = i;
		count2 = i;
		int temp1 = 0;
		int temp2 = 0;
		if (i = 0)
		{
			int c1 = i + 1;
			int count = 0;
			while (true)
			{
				if (v[i] > v[c1])
				{
					c1++;
					count++;
				}
				else
				{
					result.push_back(count);
					break;
				}

			}

		}
		if (count1 >= 0 && count2 >= 0 && count1 < n && count2 < n)
		{
			while (count1)
			{
				count1--;
				if (count1 < 0)
					break;
				if (v[count1] > v[i])
				{
					temp1++;
					break;
				}
				
				temp1++;
			}
			while (count2)
			{
				count2++;
				if (count2 > n)
					break;
				if (v[count2] > v[i])
				{
					temp2++;
					break;
				}
				
				temp2++;
			}
			result.push_back(1 + temp1 + temp2);
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		cout << result[i] << ' ';
	}
	cout << result[n - 1];
	return 0;
}