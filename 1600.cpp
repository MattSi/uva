/*
UVa:1600
巡逻机器人， 一个机器人要从一个m*n的网格，左上角走到右下角。空地用0表示， 障碍用1表示。
机器人每次可以往4个方向走1格，但不能连续穿越k个障碍。(0<=k<=20) 求最短长度。
起点和终点保证是空地。

*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
const int SIZE=25;
int board[SIZE][SIZE];
int   vis[SIZE][SIZE];
queue<int> que;

int travel(int m, int n, int k){
	int tmp = 100*m+n;
	que.push(tmp);
	while(!que.empty()){
		tmp = que.front(); que.pop();
		m = tmp/100;
		n = tmp%100;
		if(vis[m][n] == -1)
	}
	return -1;
}
int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/1600.in", "r", stdin);
#endif
	int cases, k, m, n;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d%d", &m, &n);
		scanf("%d", &k);
		memset(board, 0, sizeof(board));
		memset(vis, -1, sizeof(vis));
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				scanf("%d", &board[i][j]);
		while(!que.empty())que.pop();
		int ans = travel(m,n,k);
		printf("%d\n", ans);
	}

	return 0;
}
