#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<ostream>
using namespace std;

class CMP
{
public:
	bool operator()(int a,int b){
		return a > b;
	}
};



int main()
{
	vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	sort(v.begin(), v.end(), CMP());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}