#include<iostream>
#include<string>
using namespace std;

void AllSort(string s,int k)
{
	int i = 0, j = 0;
	if (k == s.size()){
		for (i = 0; i < s.size(); ++i)
			cout << s[i];
		cout << endl;
	}
	else
	{
		for (j = k; j < s.size(); ++j){
			swap(s[j], s[k]);
			AllSort(s, k + 1);
			swap(s[j], s[k]);
		}
	}

}



int main()
{
	string s = "abcd";
	AllSort(s, 0);
	return 0;
}