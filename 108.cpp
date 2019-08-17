/*
UVa:108



*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int SIZE=127;

int dp[SIZE][SIZE];
int main() {
#ifndef ONLINE_JUDGE
	FILE* fp = freopen("./tests/108.in", "r", stdin);
#endif

    int n, tmp;
    while(scanf("%d", &n) == 1){
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                scanf("%d", &tmp);
		dp[i][j] = dp[i-1][j] + tmp;
            }
        }
    }
    

    return 0;
}












