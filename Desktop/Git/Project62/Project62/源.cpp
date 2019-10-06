#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
	//int t = srand(time(0)) % 5;
	switch ((rand()%5)*101010101%5)
	{
	case 1:
		cout << "³Ô¸ö»ð¹ø" << endl;
		break;
	case 2:
		cout << "³Ô¹øÌù" << endl;
		break;
	case 3:
		cout << "³ÔÃ×Ïß" << endl;
		break;
	case 4:
		cout << "³ÔÃæ" << endl;
		break;
	case 5:
		cout << "¸Ç½½·¹" << endl;
		break;
	default:
		break;
	}
	return 0;
}