/*
UVa:11461

给定一个区间，求其中的平方数个数
*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11461.in", "r", stdin);
#endif
	int a, b;
	while(scanf("%d%d\n", &a, &b)==2 && a!=0 && b!=0){
		int sqb = (int)sqrt(b*1.0);
		int sqa = (int)sqrt(a*1.0);
		int ans = sqb-sqa +1;

		if(sqa*sqa <a) ans--;
		printf("%d\n", ans);

	}
	return 0;
}
