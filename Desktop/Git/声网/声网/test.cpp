//#include<iostream>
//using namespace std;
//
//void getAddress(int temp[], int length){
//	int tempInt;
//	for (int i = 0; i<length; ++i){
//		cin >> tempInt;
//		cin.ignore();
//		if (tempInt < 0 || tempInt >255){
//			tempInt = -1;//标记非法字符
//		}
//		temp[i] = tempInt;
//	}
//}
//
//int main()
//{
//	int mask[4];
//	int IPOne[4];
//	int IPTwo[4];
//	bool isSameSubNet = true;
//	bool isOk = true;
//	//输入有效IP地址
//	getAddress(mask, 4);
//	getAddress(IPOne, 4);
//	getAddress(IPTwo, 4);
//	//判断是否是同一子网
//	for (int i = 0; i<4; ++i){
//		if ((IPOne[i] == -1) || (IPTwo[i] == -1)){
//			cout << 1 << endl;
//			isOk = false;
//			break;
//		}
//		if ((mask[i] & IPOne[i]) != (mask[i] & IPTwo[i])){
//			isSameSubNet = false;
//		}
//	}
//	//输出
//	if (isSameSubNet&&isOk){
//		cout << 0 << endl;
//	}
//	else if (isOk){
//		cout << 2 << endl;
//	}
//	return 0;
//}



#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int floor;
	int i = 0;
	int originFloor = 0;
	int time = 0;
	int N;
	cin >> N;
	while ((++i)<=N && cin>>floor)
	{
		if (floor - originFloor >= 0)
			time += (floor - originFloor) * 6;
		else
			time += (originFloor - floor) * 4;
		originFloor = floor;
		time += 5;
	}
	cout << time << endl;
	return 0;
}