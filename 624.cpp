/*
UVa:624 CD
把CD上的歌曲翻录到磁带上，每首歌的时间固定，问最多能翻录几首歌

这是一个动态规划问题：
首先要列出状态转移方程：

F(i, w) = 
1) F(i-1, w-wi) + wi (当第i首歌曲入选)
2) F(i-1, w)         (当第i首个没有入选)

若第i首歌入选，则需要有一个数组来记录vis[i][j] = true
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 25;
const int T = 10020;

int dp[N][T];
int vis[N][T];
int tracks[N];

void print(int n, int t) {
	if (n <= 0 || t <= 0)return;
	if (vis[n][t]) {
		print(n - 1, t - tracks[n]);
		printf("%d ", tracks[n]);
	}
	else {
		print(n - 1, t);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	FILE* fp = freopen("./tests/624.in", "r", stdin);
#endif
	int t, n;
	while (scanf("%d%d", &t, &n) == 2) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &tracks[i]);
		}
		memset(dp, 0, sizeof(dp));
		memset(vis, false, sizeof(vis));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= t; j++) {
				if (j < tracks[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					int x1 = dp[i - 1][j - tracks[i]] + tracks[i];
					int x2 = dp[i - 1][j];
					if (x2 < x1) {
						dp[i][j] = x1;
						vis[i][j] = true;
					}
					else {
						dp[i][j] = x2;
					}
				}
			}
		}
		print(n, t);
		printf("sum:%d\n", dp[n][t]);
	}



	return 0;
}












