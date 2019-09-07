#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> v;
		int row = matrix[0].size();
		int col = matrix.size();
		if (row == 0 || col == 0)
			return v;
		int left = 0;
		int right = row - 1;
		int top = 0;
		int low = col - 1;
		while (left <= right && top <= low)
		{
			for (int i = left; i <= right; i++)
				v.push_back(matrix[top][i]);
			if (top<low)
			for (int i = top + 1; i <= low; i++)
				v.push_back(matrix[i][right]);
			if (top<low && left<right)
			for (int i = right - 1; i >= left; i--)
				v.push_back(matrix[low][i]);
			if (top + 1<low&&left<right)
			for (int i = low - 1; i >= top + 1; i--)
				v.push_back(matrix[i][left]);
			left++; right--; top++; low--;
		}
		return v;
	}
};

int main()
{
	vector<vector<int>> v{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	Solution s;
	s.printMatrix(v);
	return 0;
}
