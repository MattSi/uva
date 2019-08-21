/*
UVa:1600
巡逻机器人， 一个机器人要从一个m*n的网格，左上角走到右下角。空地用0表示， 障碍用1表示。
机器人每次可以往4个方向走1格，但不能连续穿越k个障碍。(0<=k<=20) 求最短长度。
起点和终点保证是空地。

*/
#include <stdio.h> 
#include <string.h>
#include <queue>
using namespace std;

int g[32][32];
int dist[32][32][32];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int main() {
	int testcase;
	int N, M, K;
	scanf("%d", &testcase);
	while (testcase--) {
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &g[i][j]);
		memset(dist, 63, sizeof(dist));
		dist[0][0][0] = 0;
		queue<int> X, Y, S;
		int x, y, s, tx, ty, ts;
		X.push(0), Y.push(0), S.push(0);
		while (!X.empty()) {
			x = X.front(), X.pop();
			y = Y.front(), Y.pop();
			s = S.front(), S.pop();
			for (int i = 0; i < 4; i++) {
				tx = x + dx[i], ty = y + dy[i];
				if (tx < 0 || ty < 0 || tx >= N || ty >= M)
					continue;
				if (g[tx][ty])
					ts = s + 1;
				else
					ts = 0;
				if (ts > K)	continue;
				if (dist[tx][ty][ts] > dist[x][y][s] + 1) {
					dist[tx][ty][ts] = dist[x][y][s] + 1;
					X.push(tx), Y.push(ty), S.push(ts);
				}
			}
		}
		int ret = 0x3f3f3f3f;
		for (int i = 0; i <= K; i++)
			ret = min(ret, dist[N-1][M-1][i]);
		printf("%d\n", ret == 0x3f3f3f3f ? -1 : ret);
	}
	return 0;
}
