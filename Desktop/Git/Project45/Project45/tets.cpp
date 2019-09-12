//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> v(n, vector<int>(m));
//	for (int i = 0; i < n; ++i){
//		for (int j = 0; j < m; ++j){
//			cin >> v[i][j];
//		}
//	}
//	vector<vector<int>> res;
//	int cols = 0;
//	int rows = 0;
//	while (cols < n && rows < m)
//	{
//		vector<int> temp;
//		if ((cols + 1)< n && (rows + 1) <m  && v[cols][rows + 1] > v[cols + 1][rows]){
//			temp.push_back(cols++);
//			temp.push_back(rows);
//		}
//		else{
//			temp.push_back(cols);
//			temp.push_back(rows++);
//		}
//		res.push_back(temp);
//		temp.clear();
//	}
//	if (cols >= n){
//		while (rows < m){
//			vector<int> temp;
//			temp.push_back(n - 1);
//			temp.push_back(rows++);
//			res.push_back(temp);
//			temp.clear();
//		}
//	}
//	else{
//		while (++cols < n){
//			vector<int> temp;
//			temp.push_back(cols);
//			temp.push_back(m - 1);
//			res.push_back(temp);
//			temp.clear();
//		}
//	}
//	for (int i = 0; i < res.size(); ++i)
//	{
//		cout << res[i][0] << " " << res[i][1] << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int minPathSum(vector<vector<int>>& grid)
//{
//	//当grid为空时，返回0
//	if (grid.empty())
//		return 0;
//	//获得grid行数和列数
//	int rows = grid.size();
//	int cols = grid[0].size();
//	//保存s[i-1]行中的元素
//	vector<int> pre(cols, grid[0][0]);
//	//保存s[i][j-1]中的元素
//	int cur = grid[0][0];
//	//初始化pre
//	for (int i = 1; i < cols; ++i)
//	{
//		pre[i] = pre[i - 1] + grid[0][i];
//	}
//	//获得s[i][j]的最小值
//	for (int i = 1; i < rows; ++i)
//	{
//		cur = grid[i][0] + pre[0];
//		pre[0] = cur;
//		for (int j = 1; j < cols; ++j)
//		{
//			cur = min(cur, pre[j]) + grid[i][j];
//			pre[j] = cur;
//		}
//	}
//	return pre[cols - 1];
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> v(n, vector<int>(m));
//	for (int i = 0; i < n; ++i){
//		for (int j = 0; j < m; ++j){
//			cin >> v[i][j];
//		}
//	}
//	int res = minPathSum(v);
//	return 0;
//}
//
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
	string str;
	cin >> str;
	map<char, int> mp;
	for (int i = 0; i < str.size(); ++i){
		if (str[i] >= '0' && str[i] <= '9');
		mp[str[i]]++;
	}
	int count = 0;
	int num = 0;
	auto it = mp.begin();
	for (it; it != mp.end(); ++it){
		if (it->second == 1)
			++count;
		else
			++num;
	}
	int ret = num + count;
	cout << ret - 1 << endl;
	return 0;
}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int cookie(vector<int>& v) {
//	int n = v.size(), sum = 0;
//
//	vector<int> left(n, 1), right(n, 1);
//	for (int i = 1; i<n; i++){
//		if (v[i]>v[i - 1])
//			left[i] = left[i - 1] + 1;
//	}
//	for (int i = n - 2; i >= 0; i--){
//		if (v[i]>v[i + 1])
//			right[i] = right[i + 1] + 1;
//
//		sum += max(left[i], right[i]);
//	}
//	sum += max(right[n - 1], left[n - 1]);
//	return sum;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v;
//	int temp;
//	for (int i = 0; i < n; ++i){
//		cin >> temp;
//		v.push_back(temp);
//	}
//	int res = cookie(v);
//	cout << res << endl;
//	return 0;
//}