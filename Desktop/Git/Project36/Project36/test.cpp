#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		map<char, int> mp;
		for (int i = 0; i < str.size(); ++i)
			mp[str[i]]++;
		for (int i = 0; i < str.size(); ++i){
			if (mp[str[i]] == 1)
				return i;
		}
		return -1;
	}
};
int main()
{
	string s = "ssssssssssssbcccccccccccccccabaaaaaaaz";
	Solution t;
	int ret = t.FirstNotRepeatingChar(s);
	return 0;
}