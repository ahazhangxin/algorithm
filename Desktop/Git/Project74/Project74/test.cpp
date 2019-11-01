#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void Earse(vector<int>& vec)
{
	vec.erase(remove_if(vec.begin(), vec.end(), [](int i){
		return i % 2 == 0; 
	}), vec.end());
}

int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Earse(v);
	for (auto e : v)
	{
		cout << e << " ";
	}
	return 0;
}