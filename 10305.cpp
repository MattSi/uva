/*
UVa:10305 拓扑排序
假设有n个变量，m个二元组(u,v)分别表示u小于v。那么，将所有变量从小到大排列起来是什么样子的？

5 4
1 2
2 3
1 3
1 5
0 0
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 105;
int c[maxn];
int topo[maxn];
int G[maxn][maxn];
int n, m, t;


bool dfs(int u) {
	c[u] = -1; //访问标志,表示访问进行中

	for (int v = 1; v <= n; v++) if (G[u][v]) {
		if (c[v] == -1) return false; //存在有向环，失败退出
		else if (!c[v] && !dfs(v)) return false;
	}
	c[u] = 1; topo[t--] = u;
	return true;
}
bool toposort() {
	t = n;
	for (int u = 1; u <= n; u++) if (!c[u])
		if (!dfs(u)) return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	FILE* fp = freopen("./tests/10305.in", "r", stdin);
	//FILE* fp2 = freopen("d:\\temp\\20190821\\10305.out", "w", stdout);
#endif
	int u, v;
	while (scanf("%d%d", &n, &m) == 2) {
		if (n == 0 && m == 0)break;
		memset(G, 0, sizeof(G));  memset(c, 0, sizeof(c));  memset(topo, 0, sizeof(topo));
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &u, &v);
			G[u][v] = 1;
		}
		bool res = toposort();
		for (int i = 1; i <= n; i++) {
			printf("%d ", topo[i]);
		}
		printf("\n");
	}
	return 0;
}
