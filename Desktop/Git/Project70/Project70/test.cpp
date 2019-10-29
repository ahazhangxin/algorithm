#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> res;
	vector<int> path;
public:
	void DFS(vector<int>& candidates, int start, int target){
		if (target == 0){
			res.push_back(path);
			return;
		}
		for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i){
			path.push_back(candidates[i]);
			DFS(candidates, i, target - candidates[i]);
			path.pop_back();
		}
	}


	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.empty())
			return{};
		sort(candidates.begin(), candidates.end());
		DFS(candidates, 0, target);
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<vector<int>> res;
	res = s.combinationSum(v, 8);
	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j < res[i].size(); ++j){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}