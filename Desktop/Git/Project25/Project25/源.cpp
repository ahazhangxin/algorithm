#include<iostream>
#include<vector>
using namespace std;

struct node{
	int to;    //终点 
	int v;     //权 
}rt;
vector<node>v[10];
void add(int a, int b, int c){  //从a到b有一条权c的边 
	rt.to = b, rt.v = c;
	v[a].push_back(rt);
}

int main()
{
	add(1, 1, 1);
	add(1, 2, 1);
	add(1, 3, 1);
	add(1, 4, 1);
	add(1, 5, 1);
	add(1, 6, 1);
	add(1, 7, 1);
	return 0;
}