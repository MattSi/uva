/*
UVa:11636: HelloWorld
一行文字，复制粘贴成N行，求最少要复制多少次。

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
	FILE *fp = freopen("./tests/11636.in", "r", stdin);
#endif
	int n, cases=0;
	while(scanf("%d", &n)==1 && n>0){
		printf("Case %d: %d\n", ++cases, (int)ceil(log2(n*1.0)));
	}
	return 0;
}
