//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//	vector<vector<int> > FindContinuousSequence(int sum) {
//		vector<vector<int> > vv(sum, vector<int>(sum));
//		vector<int> v;
//		int count;
//		int t = 0;
//		for (int i = 1; i < sum; ++i)
//		{
//			count = i;
//			v.push_back(count);
//			for (int j = i + 1; j < sum; j++)
//			{
//				if (count >= sum)
//				{
//					break;
//				}
//				else{
//					count += j;
//					v.push_back(j);
//				}
//			}
//			if (count == sum)
//			{
//				vv[t] = v;
//				t++;
//			}
//			else
//				v.clear();
//		}
//		return vv;
//	}
//};
//int main()
//{
//	Solution s;
//	s.FindContinuousSequence(100);
//	return 0;
//}


#include<iostream>
#include<vector>
using namespace std;
int main()
{
	long long sum;
	cin >> sum;
	long long count = 0;
	long long temp;
	long long t = 0;
	for (long long i = 1; i <= sum; ++i)
	{
		temp = i;
		for (long long j = i + 1; j <= sum; j++)
		{
			if (temp >= sum){
				break;
			}
			else{
				temp += j;
			}
		}
		if (temp == sum){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	vector<vector<int>> v(len1 + 1, vector<int>(len2 + 1));
	for (int i = 0; i <= len1; i++){
		for (int j = 0; j <= len2; j++)
		{

			if (i == 0){
				v[i][j] = j;
			}
			else if (j == 0){
				v[i][j] = i;
			}
			else if (s1[i - 1] == s2[j - 1]){
				v[i][j] == v[i - 1][j - 1];
			}
			else{
				v[i][j] = min(min(v[i - 1][j], v[i][j - 1]), v[i - 1][j - 1]) + 1;
			}

		}
	}
	cout << v[len1][len2];
	return 0;
}