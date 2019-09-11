#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.size();
	int len2 = s2.size();
	if (len1 == 0){
		cout << len2 << endl;
	}
	else if (len2 == 0){
		cout << len1 << endl;
	}
	vector<vector<int>> v(len1 + 1, vector<int>(len2 + 1));
	for (int i = 1; i <= len1; ++i){
		v[i][0] = i;
	}
	for (int i = 1; i <= len2; ++i){
		v[0][i] = i;
	}

	for (int i = 1; i <= len1; ++i){
		for (int j = 1; j <= len2; ++j){
			if (s1[i - 1] == s2[j - 1]){
				v[i][j] = v[i - 1][j - 1];
			}
			else{
				v[i][j] = min(v[i - 1][j - 1], min(v[i][j - 1], v[i - 1][j])) + 1;
			}
		}
	}
	cout << v[len1][len2];
	return 0;
}

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	int len1 = str1.length();
	int len2 = str2.length();
/*
	int minDistance(string word1, string word2) {
	int len1 = word1.length();
	int len2 = word2.length();
*/
	vector<vector<int>> v(len1 + 1, vector<int>(len2 + 1));
	/*vector<vector<int>>dp(len1 + 1, vector<int>(len2 + 1));*/

	for (int i = 0; i <= len1; i++){
		/*for (int i = 0; i <= len1; i++){*/
		for (int j = 0; j <= len2; j++)
			/*for (int j = 0; j <= len2; j++){*/
		{

			if (i == 0){
				v[i][j] = j;
			}
			else if (j == 0){
				v[i][j] = i;
			}
			else if (str1[i - 1] == str2[j - 1]){
				v[i][j] = v[i - 1][j - 1];
			}
			else{
				v[i][j] = (min(min(v[i - 1][j], v[i][j - 1]), v[i - 1][j - 1]) + 1);
			}
			/*if (i == 0){
				dp[i][j] = j;   //如果 i=0 则需要插入j个字符
			}
			else if (j == 0){
				dp[i][j] = i;    //如果j=0则需要删除i个字符
			}
			else if (word1[i - 1] == word2[j - 1]){   //如果字符相同则不做变换，等于这个字符之前的步数
				dp[i][j] = dp[i - 1][j - 1];
			}
			else{                          //否则 就从插入，删除，修改中选择最小的 加 1 
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}*/

		}
	}

	int res = v[len1][len2];
	cout << res;
	/*	return dp[len1][len2];*/
	return 0;
}




	
	








#include<iostream>
using namespace std;
int main()
{
	long long t;
	cin >> t;
	long long count = 0;
	long long r = 2, l = 1;
	while (r >= l)
	{
		long long cur = (r + 1)*(r - l + 1) / 2;
		if (cur<t){
			r++;
		}
		else if (cur == t){
			count++;
			l++;
		}
		else{
			l++;
		}
	}
	cout << count;
	return 0;
}
