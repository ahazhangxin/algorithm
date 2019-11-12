#include<vector>
#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int S = nums.size();
		int N = 1 << S;
		vector<vector<int> > res;
		for (int i = 0; i < N; ++i) {
			vector<int> v;
			for (int j = 0; j < S; ++j)
			if (i & (1 << j))
				v.push_back(nums[j]);
			res.push_back(v);
		}
		return res;
	}
};


int main()
{
	Solution s;
	vector<int> v{ 1, 2, 3, 4 };
	vector<vector<int>> res = s.subsets(v);
	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j < res[i].size(); ++j){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}