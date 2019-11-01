#include<iostream>
#include<vector>
using namespace std;

void Earse(vector<int>& v)
{
	int count = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] % 2 == 0)
		{
			count++;
			for (int j = i+1; j < v.size(); ++j){
				v[j - 1] = v[j];
			}
		}
	}
	v.resize(count+1);
}

void getmemory(char *& p)
{
	p = new char[100];
	strcpy(p, "hello world");
	return;
}
int main(){
	char * p = nullptr;
	getmemory(p);
	printf("%s\n", p);
	return 0;
}