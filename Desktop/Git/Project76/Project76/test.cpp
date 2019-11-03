#include<iostream>
#include<memory>
using namespace std;
int main()
{
	int* x(new int);
	unique_ptr<int> up1, up2;
	up1.reset(x);
	up2.reset(x);
	int* y = up1.get();
	int* z = up2.get();
	cout << y << " " << x << endl;
	return 0;
}