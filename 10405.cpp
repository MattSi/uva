/*
UVa:10405 
求两个字符串的最大公共子串

分析：递推公式

F(i, j) = 
1) s1[i] == s2[j] 则 F(i, j) = F(i-1, j-1) + 1
2) s1[i] != s2[j] 则 F(i, j) = MAX(F(i-1, j), F(i, j-1))



*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int SIZE=1024;

int dp[SIZE][SIZE];
int main() {
#ifndef ONLINE_JUDGE
	FILE* fp = freopen("./tests/10405.in", "r", stdin);
#endif

	char s1[SIZE], s2[SIZE];
	while(fgets(s1, SIZE, stdin)!=NULL && fgets(s2, SIZE, stdin)!= NULL){
		size_t len1 = strlen(s1); if(s1[len1-1]=='\n')s1[--len1]='\0';
		size_t len2 = strlen(s2); if(s2[len2-1]=='\n')s1[--len2]='\0';
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












