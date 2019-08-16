//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	cin >> n >> m;
//	int v[1 + n][1 + m] = { 0 };
//	int temp;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> temp;
//			v[i][j] = temp;
//		}
//	}
//	int result;
//	result = 2 * m*n;
//	result += (2 * m + 2 * n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (v[i][j] > 1)
//				result += 3 * (v[i][j] - 1);
//		}
//	}
//	cout << result << endl;
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	int n, m;
//	cin >> n >> m;
//	cin >> s1 >> s2;
//	sort(s1.begin(),s1.end());
//	sort(s2.begin(), s2.end());
//	reverse(s1.begin(), s1.end());
//	reverse(s2.begin(), s2.end());
//	cout << s1 << endl;
//	return 0;
//}


#include<bits/stdc++.h>
using namespace std;
#define maxn 1000+100
int a[maxn][maxn];
int main(){
	int n, m;
	cin >> n >> m;
	for (int j = 1; j <= n; j++){
		for (int k = 1; k <= m; k++){
			int x;
			cin >> x;
			a[j][k] = x;
		}
	}
	long long ans = 0;
	for (int j = 1; j <= n; j++){
		for (int k = 1; k <= m; k++){
			ans += 6 * a[j][k];
			if (a[j][k]>1){
				ans -= (a[j][k] - 1) * 2;
			}
			ans -= min(a[j][k], a[j - 1][k]);
			ans -= min(a[j][k], a[j + 1][k]);
			ans -= min(a[j][k], a[j][k - 1]);
			ans -= min(a[j][k], a[j][k + 1]);
		}
	}
	cout << ans << endl;

	return 0;
}



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t1[100010], t2[100010];
int tmp[100010], tot = 0;
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	multiset<int> s1, s2;
	for (int i = 1; i <= n; i++){
		int tmp; scanf("%d", &tmp); s1.insert(tmp);
	}
	for (int i = 1; i <= n; i++){
		int tmp; scanf("%d", &tmp); s2.insert(tmp);
	}
	for (int i = m - 1; i >= 0; i--){
		tot = 0;
		for (multiset<int>::iterator j = s1.begin(); j != s1.end(); ++j){
			if (s2.find((i - (*j) + m) % m) != s2.end()){
				tmp[tot++] = *j;
				s2.erase(s2.find((i - (*j) + m) % m));
				printf("%d ", i);
			}
		}
		for (int j = 0; j<tot; j++){
			s1.erase(s1.find(tmp[j]));
		}
	}


	return 0;
}
