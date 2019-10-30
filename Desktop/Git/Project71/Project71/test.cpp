#include<iostream>
#include<vector>
using namespace std;

class Solution {

	void Swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; ++i){
			for (int j = i; j < n; ++j){
				Swap(matrix[i][j], matrix[j][i]);
			}
		}

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n / 2; ++j){
				Swap(matrix[i][j], matrix[i][n - j - 1]);
			}
		}
	}
};
int main()
{
	Solution s;
	vector<vector<int>> v{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	s.rotate(v);

	return 0;
}