#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
class Solution {
public:
static bool cmp(const vector<int>&a,const vector<int>&b )
{
if(a[0]==b[0])
return a[1]>b[1];
return a[0]<b[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
if(intervals.empty()) return intervals;
vector<vector<int>> res;
int count=0;
sort(intervals.begin(),intervals.end(),cmp);
vector<int> temp;
temp.push_back(intervals[0][0]);
temp.push_back(intervals[0][1]);
res.push_back(temp);
for(int i=1;i<intervals.size();i++)
{
if(res[count][1]>=intervals[i][0])
{
if(res[count][1]<=intervals[i][1])
{
res[count][1]=intervals[i][1];
}
}
else
{
count++;
temp[0]=intervals[i][0];
temp[1]=intervals[i][1];
res.push_back(temp);
}
}
return res;
}
};

*/

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.empty()) return{};
		vector<vector<int>> res;
		sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
			return a[0]<b[0];
		});

		res.push_back(move(intervals[0]));
		int j = 0;
		for (int i = 1; i<intervals.size(); i++){
			if (res[j][1] >= intervals[i][0] && res[j][1] <= intervals[i][1]){
				res[j][1] = intervals[i][1];
			}
			else if (res[j][1]<intervals[i][0]){
				j++;
				res.push_back(move(intervals[i]));
			}
		}
		return res;
	}
};


int main()
{
	Solution s;
	return 0;
}