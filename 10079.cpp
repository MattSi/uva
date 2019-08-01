/*
UVa:10079 切Pizza饼
一个pizza饼，切n刀，最大可切多少块？

f(n) = f(n-1) + n;
求此递推方程，得到f(n) = n(n+1)/2 + 1

*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10079.in", "r", stdin);
#endif
	int n;
	while(scanf("%d", &n) == 1){
		if(n<0)break;
		printf("%lld\n", (long long)n*(n+1)/2 + 1);
	}
	return 0;
}
