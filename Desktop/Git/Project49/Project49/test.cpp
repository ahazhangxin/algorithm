//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<vector<int>> v(n, vector<int>(2));
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> v[i][0] >> v[i][1];
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		int Min = v[i][0] * v[i][1];
//		int temp = i;
//		int t = i;
//		for (int j = 0; j < n; ++j){
//			if (Min = v[j][0] * v[j][1]){
//				if (min(v[temp][0] / v[temp][1], v[temp][1] / v[temp][0]) > min(v[j][0] / v[j][1], v[j][1] / v[j][0])){
//					temp = temp;
//				}
//				else if (min(v[temp][0] / v[temp][1], v[temp][1] / v[temp][0]) > min(v[j][0] / v[j][1], v[j][1] / v[j][0])){
//					temp = j;
//				}
//				else{
//					temp = v[temp][0] > v[j][0] ? temp : j;
//				}
//			}
//			else if (Min > v[j][0] * v[j][1]){
//				temp = j;
//			}
//		}
//		swap(v[i], v[temp]);
//	}
//	for (int i = 0; i < n; ++i){
//		cout << v[i][0] << " " << v[i][1];
//		cout << " ";
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	//int n;
//	//cin >> n;
//	double s = 1;
//
//	return 0;
//}


#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(2));
	map<int, int> m;
	int temp1, temp2;
	for (int i = 0; i < n; ++i){
		cin >> temp1;
		cin >> temp2;
		if (m[temp1].second > temp2){
			continue;
		}
		else{
			m[temp1].second = temp2;
		}
	}
	int max = 0;
	for (auto e : m){
		if (e->second > max)
			max = e->second;
	}
	cout << max << endl;
	return 0;
}