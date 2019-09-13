//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<string> v;
//	for (int i = 0; i < n; ++i){
//		string temp;
//		cin >> temp;
//		v.push_back(temp);
//		temp.clear();
//	}
//	int count = 0;
//	for (int i = 1; i < n - 1; ++i){
//		for (int j = 1; j< m - 1; ++j){
//			if (v[i][j] == '1' && v[i - 1][j] == '1' && v[i + 1][j] == '1' && v[i][j + 1] == '1' && v[i][j - 1] == '1')
//				count++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}



//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v;
//	while (n--){
//		string s1, s2;
//		cin >> s1 >> s2;
//		int count = 0;
//		for (int i = 0; i < s1.size(); ++i){
//			if (s1[i] != s2[i])
//				count++;
//		}
//		v.push_back(count);
//	}
//	for (int i = 0; i < v.size(); ++i){
//		cout << v[i] << endl;
//	}
//	return 0;
//}



#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool IsOk(int a)
{
	for (int i = 2; i < a; ++i){
		if (a%i == 0)
			return false;
	}
	return true;
}

int Sum(const vector<int>& v)
{
	int temp = 0;
	for (size_t i = 0; i < v.size(); ++i){
		temp *= 10;
		temp += v[i];
	}
	return temp;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	while (n--){
		string s1, s2;
		cin >> s1 >> s2;
		vector<int> v1, v2;
		for (size_t i = 0; i < s1.size(); ++i){
			v1.push_back(s1[i] - '0');
			v2.push_back(s2[i] - '0');
		}
		bool ok = true;
		int count = 0;
		for (size_t i = 0; i < v1.size(); ++i){
			if (v1[i] != v2[i]){
				count++;
				v1[i] = v2[i];
				int temp = Sum(v1);
				ok = IsOk(temp);
				if (!ok)
					break;
			}
		}
		if (ok)
			v.push_back(count);
		else
			v.push_back(-1);
	}
	for (size_t i = 0; i < v.size(); ++i){
		cout << v[i] << endl;
	}
	return 0;
}