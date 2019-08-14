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
int dp2[SIZE][SIZE];
int main() {
#ifndef ONLINE_JUDGE
	FILE* fp = freopen("./tests/108.in", "r", stdin);
#endif

    int n;
    while(scanf("%d", &n) == 1){
        memset(dp, 0, sizeof(dp));
        memset(dp2,0, sizeof(dp2));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                scanf("%d", &dp[i][j]);
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int max_v = dp[i][j];
                if(i>1){
                    if(max_v <dp2[i-1][j]) max_v = dp2[i-1][j];
                }
                if(j>1){
                    if(max_v <dp2[i][j-1]) max_v = dp2[i][j-1];
                }

                int x2=0; 
                //for(int k=1; k<=i; k++){
                //    x2 += dp[k][j];
               // }
                if(j>1)
                    x2+=dp2[i][j-1] + dp[i][j];
                if(max_v<x2)max_v=x2;

                int x3=0;
                for(int k=1; k<=j;k++){
                    x3 += dp[i][k];
                }
                if(i>1)
                    x3+=dp2[i-1][j];
                if(max_v<x3) max_v=x3;
                
                dp2[i][j]=max_v;
                
            }
        }
        printf("%d\n", dp2[n][n]);
    }
    

	return 0;
}












