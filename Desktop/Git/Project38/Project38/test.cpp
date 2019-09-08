#include<iostream>
using namespace std;
template<typename T, typename _PrintFunc>
struct solution
{
	void PrintAll(const T* values, int size, _PrintFunc _print);
	void operator()(int* v)
	{
		cout << *v << '->';
	}
};

template<typename T, typename _PrintFunc>
void solution::PrintAll(const T* values, int size, _PrintFunc _print){
	for (int i = 0; i < size; i++)
		_print(values[i]);
	cout << endl;
}

int main()
{
	int iV[5] = { 1, 2, 3, 4, 5 };
	solution s;
	s.PrintAll<int, void>(iV, 5, _print()(iV));
	return 0;
}