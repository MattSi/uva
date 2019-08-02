/*
UVa:102

三个背包中有三种颜色的罐子（Brown， Green，Clear），
问使得每个背包中只有一种颜色的管子，需要移动的次数最小。（相同的按照字母序输出最小）
只有6种情况，还是暴力吧

BGC BGC BGC
123 456 789 

========
*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/102.in", "r", stdin);
#endif
	int g[10];
	int sum[7];
	string strs[7]= {"", "BCG","BGC","CBG","CGB","GBC","GCB"};
	while(scanf("%d%d%d%d%d%d%d%d%d",&g[1], &g[2] , &g[3] , &g[4] , &g[5] , &g[6] , &g[7] , &g[8] , &g[9] )==9 ){
		sum[1] /*BCG*/ = g[4]+g[7] + g[3]+g[9] +  g[2]+g[5];
		sum[2] /*BGC*/ = g[4]+g[7] + g[2]+g[8] +  g[3]+g[6];
		sum[3] /*CBG*/ = g[6]+g[9] + g[1]+g[7] +  g[2]+g[5];
		sum[4] /*CGB*/ = g[6]+g[9] + g[2]+g[8] +  g[1]+g[4];
		sum[5] /*GBC*/ = g[5]+g[8] + g[1]+g[7] +  g[3]+g[6];
		sum[6] /*GCB*/ = g[5]+g[8] + g[3]+g[9] +  g[1]+g[4];
		int v = sum[1], ind=1;;
		for(int i=1; i<=6; i++){
			if(sum[i]<v){v=sum[i]; ind=i;}
		}
		cout<<strs[ind]<<" "<<v<<endl;
	}
	return 0;
}
