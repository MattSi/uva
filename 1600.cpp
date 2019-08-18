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

const int SIZE = 25;
int board[SIZE][SIZE];
int   vis[SIZE][SIZE];
const int R[] = { 0, -1, 0, 1 };
const int C[] = { -1, 0, 1, 0 };

struct Node {
	int r;
	int c;
	int step;
	Node(int rr, int cc, int sstep) :r(rr), c(cc), step(sstep) {}
};
queue<Node> que;
int K;

bool valid_position(int r, int c) {
	if(r>=1 &&r<=)
}
void push_queue(Node& node) {
	for (int i = 0; i < 4; i++) {

	}
}

int travel(int m, int n) {
	int step = 0;
	que.push(Node(1,1,step));
	vis[1][1] = step;

	while (!que.empty()) {
		Node tmp = que.front(); que.pop();
		int r = tmp.r;
		int c = tmp.c;
		int s = tmp.step;
		if (r == m && c == n) {
			return s;
		}
		push_queue(tmp);
	}
	return -1;
}
int main() {
#ifndef ONLINE_JUDGE
	FILE* fp = freopen("./tests/1600.in", "r", stdin);
#endif
	int cases, m, n;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d%d", &m, &n);
		scanf("%d", &K);
		memset(board, 0, sizeof(board));
		memset(vis, -1, sizeof(vis));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &board[i][j]);
		while (!que.empty())que.pop();
		int ans = travel(m, n);
		printf("%d\n", ans);
	}

	return 0;
}
