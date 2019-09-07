#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > vv(sum, vector<int>(sum));
		vector<int> v;
		int count;
		int t = 0;
		for (int i = 1; i < sum; ++i)
		{
			count = i;
			v.push_back(count);
			for (int j = i + 1; j < sum; j++)
			{
				if (count >= sum)
				{
					break;
				}
				else{
					count += j;
					v.push_back(j);
				}
			}
			if (count == sum)
			{
				vv[t] = v;
				t++;
			}
			else
				v.clear();
		}
		return vv;
	}
};
int main()
{
	Solution s;
	s.FindContinuousSequence(100);
	return 0;
}