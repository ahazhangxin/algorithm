#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 0 || s.size() == 0)
			return s;
		int count = s.size();
		int tmp = numRows * 2 - 2;
		string res = "";
		for (int i = 0; i < count / tmp; ++i)
		{
			int j = 0;
			while (j <( count / tmp))
			{
				res += s[i + j*tmp];
				j++;
			}
		}
		return res;
	}
};


int main()
{
	Solution s;
	string p = s.convert("LEETCODEISHIRING", 3);
	return 0;
}


