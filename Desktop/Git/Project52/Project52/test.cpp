//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	string s;
//	getline(cin, s);
//	vector<int> v;
//	int temp;
//	for (int i = 0; i < n; ++i){
//		cin >> temp;
//		v.push_back(temp);
//	}
//	int left = 0;
//	int right = v.size() - 1;
//	long leftcount = 0;
//	long rightcount = 0;
//	while (left <= right){
//		if ((leftcount - rightcount) > 0)
//		{
//			right--;
//			rightcount += v[right];
//		}
//		else if ((leftcount - rightcount) < 0){
//			left++;
//			leftcount += v[left];
//		}
//		else{
//			if (v[left] > v[right]){
//				left++;
//				leftcount += v[left];
//			}
//			else{
//				right--;
//				rightcount += v[right];
//			}
//		}
//	}
//	if ((leftcount - rightcount) > 0){
//		cout << leftcount - rightcount << endl;
//	}
//	else{
//		cout << rightcount - leftcount << endl;
//	}
//	return 0;
//}



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; ++i){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	sort(v.begin(), v.end());
	int length = 1;
	int c = v[1] - v[0];
	int res = 0;
	for (int i = 1; i < n; ++i)
	{
		if ((v[i] - v[i - 1]) == c){
			length++;
		}
		else{
			c = v[i] - v[i - 1];
			if (length > res)
			{
				res = length;
			}
			length = 0;
		}
	}
	if (length > res)
		res = length;
	cout << res << endl;
	return 0;
}