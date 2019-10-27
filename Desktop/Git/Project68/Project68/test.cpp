#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	/*
	vector<int> res;
	int left = 0;
	int right = nums.size() - 1;
	while(left<right)
	{
	int mid = (left + right) / 2;
	if(nums.)
	}
	return {-1,-1};
	*/
	vector<int> res;
	bool flag = true;
	for (int i = 0; i < nums.size(); ++i){
		if (nums[i] == target && flag){
			res.push_back(i);
			flag = false;
		}
		if (nums[i] > target && !flag){
			res.push_back(i - 1);
		}
	}

	if (res.size() == 1)
		res.push_back(nums.size() - 1);
	if (res.empty())
		return{ -1, -1 };
	return res;
}


class Solution {
private:
	int findLowerBound(vector<int> &nums, int target) {
		int size = nums.size();
		int left = 0;
		int right = size - 1;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		if (nums[left] != target) {
			return -1;
		}
		return left;
	}

	int findUpBound(vector<int> &nums, int target) {
		int size = nums.size();
		int left = 0;
		int right = size - 1;
		while (left < right) {
			int mid = (left + right + 1) >> 1;
			if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid;

			}
		}
		if (nums[left] != target) {
			return -1;
		}
		return left;
	}


public:
	vector<int> searchRange(vector<int> &nums, int target) {
		int size = nums.size();
		if (size == 0) {
			return{ -1, -1 };
		}
		int num1 = findLowerBound(nums, target);

		if (num1 == -1) {
			return{ -1, -1 };
		}
		int num2 = findUpBound(nums, target);
		return{ num1, num2 };
	}
};




int main()
{
	vector<int> v{ 1, 2, 3 };
	vector<int> res = searchRange(v, 1);
	return 0;
}