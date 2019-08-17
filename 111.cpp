/*
UVa:111 历史考试分数
有n个历史事件，记作x1, x2, ..., xn
每个学生过来给这些时间按照年代排序，按照最长的顺序给分，求最大分值

分析：其实就是换了一个表达方式的最长公共子串。

*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int SIZE=128;

int dp[SIZE][SIZE];
int main() {
#ifndef ONLINE_JUDGE
	FILE* fp = freopen("./tests/111.in", "r", stdin);
#endif
	int n;
	int s1[SIZE], s2[SIZE];
	scanf("%d", &cases);
	memset(s1, 0, sizeof(s1));
	for(int i=1; i<=n; i++){
		scanf("%d", &s1[i]);
	}
	while(true){
		memset(s2, 0, sizeof(s2));

	}
	memset(dp, 0, sizeof(dp));
		for(int i=1; i<=len1; i++){
			for(int j=1; j<=len2; j++){
				if(s1[i-1] == s2[j-1]){
					dp[i][j] = dp[i-1][j-1]+1;
				}else{
					int x1 = dp[i-1][j];
					int x2 = dp[i][j-1];
					dp[i][j] = max(x1, x2);
				}
			}
		}
		printf("%d\n", dp[len1][len2]);

	}

	return 0;
}












