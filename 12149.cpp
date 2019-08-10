/*
UVa:12149 Feynnman

N个小正方形组成的大正方形内，一共有多少个正方形
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>



int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/12149.in", "r", stdin);
#endif
	int n;
	while(scanf("%d", &n) == 1 && n !=0){
		printf("%d\n", n*(n+1)*(2*n+1)/6 );
	}
	return 0;
}












