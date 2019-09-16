//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int x, y, n;
//	cin >> x >> y >> n;
//	x += 500;
//	y += 500;
//	vector<vector<int>> v(1001, vector<int>(1001));
//	
//	int left = INT_MAX;
//	int right = INT_MIN;
//	int low = INT_MAX;
//	int top = INT_MIN;
//	while (n--)
//	{
//		int a, b;
//		cin >> a >> b;
//		a += 500;
//		b += 500;
//		if (a > 0){
//			if (a > right)
//				right = a;
//		}
//		else
//		{
//			if (a < left)
//				left = a;
//		}
//
//		if (b > 0)
//		{
//			if (b > top)
//				top = b;
//		}
//		else
//		{
//			if (b < low)
//				low = b;
//		}
//		v[a][b] = 1;
//	}
//
//	for (int i = 0; i <= 1000; ++i)
//	{
//		v[i][left] = 1;
//		v[i][right] = 1;
//	}
//
//	for (int i = 0; i <= 1000; ++i)
//	{
//		v[low][i] = 1;
//		v[top][i] = 1;
//	}
//
//
//	int a = 500, b = 500;
//	int count = 0;
//	while (a != x || b != y)
//	{
//		if ((a - x) > 0){
//			if (v[a - 1][b] != 0)
//			{
//				a--;
//				count++;
//				v[a - 1][b] = 2;
//			}
//			else if(v[a + 1][b] != 0)
//			{
//				a++;
//				count++;
//				v[a + 1][b] = 2;
//			}
//		}
//		else if ((a - x) < 0)
//		{
//			if (v[a + 1][b] != 0)
//			{
//				a++;
//				count++;
//				v[a + 1][b] = 2;
//			}
//			else if(v[a - 1][b] != 0)
//			{
//				a--;
//				count--;
//				v[a - 1][b] = 2;
//			}
//		}
//
//		if ((b - y) > 0)
//		{
//			if (v[a][b - 1] != 1)
//			{
//				b--;
//				count++;
//				v[a][b - 1] = 2;
//			}
//			else if (v[a][b + 1] != 1)
//			{
//				b++;
//				count++;
//				v[a][b + 1] = 2;
//			}
//		}
//		else if((b - y) < 0)
//		{
//			if (v[a][b + 1] != 1)
//			{
//				b++;
//				count++;
//				v[a][b + 1] = 2;
//			}
//			else if (v[a][b - 1] != 1)
//			{
//				b--;
//				count++;
//				v[a][b - 1] = 2;
//			}
//		}
//
//		if (v[a + 1][b] != 0 && v[a - 1][b] != 0 && v[a][b + 1] != 0 && v[a][b - 1] != 0)
//		{
//			if (v[a + 1][b] == 2)
//			{
//				a--;
//				count--;
//				v[a + 1][b] = 1;
//			}
//			else if (v[a - 1][b] == 2)
//			{
//				a++;
//				count--;
//				v[a - 1][b] = 1;
//			}
//			else if (v[a][b + 1] == 2)
//			{
//				b--;
//				count--;
//				v[a][b + 1] = 1;
//			}
//			else if (v[a][b - 1] == 2)
//			{
//				b++;
//				count--;
//				v[a][b - 1] = 1;
//			}
//		}
//
//	}
//	cout << count << endl;
//	return 0;
//}


//#include <cstdio>
//#include <queue>
//#include <cstring>
//#include <iostream>
//#define Open(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
//#define Close fclose(stdin); fclose(stdout);
//#define O(x) cout << #x << "=" << x << endl;
//using namespace std;
//const int MAXN = 10010 << 2;
//const int MAXM = 5000000;
//struct Edge{
//	int next, to, dis;
//}e[MAXM << 1];
//int head[MAXN], num, dis[MAXN], vis[MAXN], a[110][110], s[12], top;
//inline void Add(int u, int v, int dis){
//	e[++num] = (Edge){ head[u], v, dis }; head[u] = num;
//}
//int n, m, N, l[] = { -1, 1, 0, 0 }, r[] = { 0, 0, -1, 1 }, sx, sy, px, py;
//inline int id(int x, int y, int direct){
//	return direct * N + (x - 1) * m + y;
//}
//queue <int> q;
//void work(int check){
//	for (int i = 1; i <= n; ++i)
//	for (int j = 1; j <= m; ++j){
//		if (!a[i][j]) continue;
//		for (int k = 0; k < 4; ++k){
//			for (int p = 1, x = i + l[k], y = j + r[k]; a[x][y]; ++p, x += l[k], y += r[k])
//			if (p == check){
//				for (int l = 0; l < 4; ++l)
//				if (l != k)
//					Add(id(i, j, k), id(x, y, l), check);
//				break;
//			}
//		}
//	}
//	memset(dis, 127, sizeof dis);
//	dis[id(sx, sy, 0)] = dis[id(sx, sy, 1)] = dis[id(sx, sy, 2)] = dis[id(sx, sy, 3)] = 0;
//	vis[id(sx, sy, 0)] = vis[id(sx, sy, 1)] = vis[id(sx, sy, 2)] = vis[id(sx, sy, 3)] = 1;
//	q.push(id(sx, sy, 0)); q.push(id(sx, sy, 1)); q.push(id(sx, sy, 2)); q.push(id(sx, sy, 3));
//	while (q.size()){
//		int u = q.front(); q.pop();
//		vis[u] = 0;
//		for (int i = head[u]; i; i = e[i].next)
//		if (dis[e[i].to] > dis[u] + e[i].dis){
//			dis[e[i].to] = dis[u] + e[i].dis;
//			if (!vis[e[i].to]){
//				vis[e[i].to] = 1;
//				q.push(e[i].to);
//			}
//		}
//	}
//	int ans = min(min(dis[id(px, py, 0)], dis[id(px, py, 1)]), min(dis[id(px, py, 2)], dis[id(px, py, 3)]));
//	if (ans < 10000000) s[++top] = ans;
//}
//int main(){
//	scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &px, &py); N = n * m;
//	for (int i = 1; i <= n; ++i)
//	for (int j = 1; j <= m; ++j)
//		scanf("%d", &a[i][j]);
//	for (int i = 1; i <= n; ++i)
//	for (int j = 1; j <= m; ++j){
//		if (!a[i][j]) continue;
//		for (int k = 0; k < 4; ++k){
//			int x = i + l[k], y = j + r[k];
//			if (!a[x][y]) continue;
//			Add(id(i, j, k), id(x, y, k), 1);
//		}
//	}
//	for (int i = 10; i; --i)
//		work(i);
//	for (int Top = top, i = 1; i <= Top; ++i)
//		printf("%d %d\n", i, s[top--]);
//	return 0;
//}

//#include<bits/stdc++.h>
//#define N 105
//using namespace std;
//
//int n, m, ok = 1;
//int fx, fy, ex, ey;
//int mx[] = { 1, -1, 0, 0 };
//int my[] = { 0, 0, 1, -1 };
//int a[N][N], f[N][N][11][4];
//
//void work(int lim){
//	memset(f, 0, sizeof f); ok = 0;
//	queue<int> qx, qy, qt, q; f[fx][fy][lim - 1][0] = 1;
//	qx.push(fx); qy.push(fy); qt.push(lim - 1); q.push(-1);
//	while (!qx.empty()){
//		int x = qx.front(); qx.pop();
//		int y = qy.front(); qy.pop();
//		int t = qt.front(); qt.pop();
//		int now = q.front(); q.pop();
//		if (x == ex and y == ey)
//			return printf("%d %d\n", lim, f[x][y][t][now]), ok = 1, void();
//		for (int i = 0; i<4; i++) if (((x == fx and y == fy) or i == now) or !t){
//			int tx = x + mx[i], ty = y + my[i];
//			int nt = i == now ? max(0, t - 1) : lim - 1;
//			if (!a[tx][ty] || tx>n || ty>m || tx<1 || ty<1 || f[tx][ty][nt][i]) continue;
//			f[tx][ty][nt][i] = f[x][y][t][now] + 1; qx.push(tx); qy.push(ty); qt.push(nt); q.push(i);
//		}
//	}
//}
//signed main(){
//	cin >> n >> m >> fx >> fy >> ex >> ey;
//	for (int i = 1; i <= n; i++)
//	for (int j = 1; j <= m; j++) cin >> a[i][j];
//	for (int i = 1; i <= 10 and ok; i++) work(i);
//}

//using namespace std;
//
//const int fx[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
//const int N = 100;
//
//int n;
//int m;
//int Fx;
//int Fy;
//int Tx;
//int Ty;
//int res;
//int s[N + 1][N + 1];
//int f[N + 1][N + 1][4];
//int dis[N + 1][N + 1][4];
//
//struct Node {
//	int x;
//	int y;
//	int z;
//};
//
//void print() {/*
//			  for(int i = 1; i <= n; i++) {
//			  for(int j = 1; j <= m; j++)
//			  printf("%-3d ", dis[i][j]);
//			  puts("");
//			  }
//			  for(int i = 1; i <= n; i++) {
//			  for(int j = 1; j <= m; j++)
//			  printf("%-3d ", f[i][j]);
//			  puts("");
//			  }*/
//}
//
//void BFS(int k) {
//	queue<Node>q;
//	while (!q.empty()) q.pop();
//	q.push((Node){ Fx, Fy, 0 });
//	q.push((Node){ Fx, Fy, 1 });
//	q.push((Node){ Fx, Fy, 2 });
//	q.push((Node){ Fx, Fy, 3 });
//	f[Fx][Fy][0] = 0;
//	f[Fx][Fy][1] = 0;
//	f[Fx][Fy][2] = 0;
//	f[Fx][Fy][3] = 0;//0、1、2、3表示从哪个方向来的，f记录连续走了多少步
//	while (!q.empty()) {
//		Node now = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int x = now.x + fx[i][0];
//			int y = now.y + fx[i][1];
//			if (x > n || y > m || x < 1 || y < 1) continue;
//			if (!s[x][y] || (x == Fx && y == Fy)) continue;
//			int a;
//			if (i == now.z)
//				a = min(k, f[now.x][now.y][now.z] + 1);
//			else {
//				if (f[now.x][now.y][now.z] != k) continue;
//				a = 1;
//			}
//			if (dis[x][y][i] && a <= f[x][y][i]) continue;
//			//之前提到的就是这里了
//			//这里是说如果之前到过并且连续走的步数比之前记录的少就放弃
//			f[x][y][i] = a;
//			q.push((Node){ x, y, i });
//			dis[x][y][i] = dis[now.x][now.y][now.z] + 1;
//			if (x == Tx && y == Ty) {
//				res = dis[x][y][i];
//				return;
//			}
//		}
//	}
//}
//
//int main() {
//	scanf("%d%d%d%d%d%d", &n, &m, &Fx, &Fy, &Tx, &Ty);
//	for (int i = 1; i <= n; i++)
//	for (int j = 1; j <= m; j++)
//		scanf("%d", &s[i][j]);
//	for (int i = 1; i <= 10; i++) {
//		res = -1;
//		memset(f, 0, sizeof(f));
//		memset(dis, 0, sizeof(dis));
//		BFS(i);
//		print();
//		if (res == -1) break;
//		printf("%d %d\n", i, res);
//	}
//	return 0;
//}

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	stack<string> s;

	return 0;
}