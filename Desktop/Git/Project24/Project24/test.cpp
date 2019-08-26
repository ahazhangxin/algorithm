#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<functional>
using namespace std;
/*
bool cmp(const int& a,const int& b)
{
	return a > b;
}

int main()
{
	vector<int> v1{ 6, 43, 8, 4, 2, 8, 4, 2, 1, 4, 5, 6, 8, 0 };
	sort(v1.begin(), v1.end());
	for (auto& e : v1)
	{
		cout << e << "->";
	}
	cout << endl;
	vector<int> v2{ 6, 43, 8, 4, 2, 8, 4, 2, 1, 4, 5, 6, 8, 0 };
	sort(v2.begin(), v2.end(), cmp);
	for (auto& e : v2)
	{
		cout << e << "->";
	}
	cout << endl;
	return 0; 
}
*/

bool cmp()
{
	return true;
}

int main()
{
	//unordered_multimap<int, int> um{ { 1, 4 }, { 1, 2 } };
	//multimap<int, int> m{ { 1, 4 }, { 1, 2 } };
	vector<int> v{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	priority_queue<int,vector<int>,greater<int>> q;
	for (auto &e : v)
	{
		q.push(e);
	}
	int temp = q.size();
	for (int i = 0; i < temp; i++)
	{
		cout << q.top() << "->";
		q.pop();
	}
	cout << endl;
	priority_queue<int> q1(v.begin(), v.end());

	/*priority_queue<int,vector<int>, less<int>> q1;
	for (auto &e : v)
	{
		q1.push(e);
	}
	temp = q1.size();
	for (int i = 0; i < temp; i++)
	{
		cout << q1.top() << "->";
		q1.pop();
	}*/
	cout << endl;
	return 0;
}