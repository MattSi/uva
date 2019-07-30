/*
UVa:10812
猜橄榄球比分，给定两比分的和，与差的绝对值。求两比分。
比分没有负数
*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10812.in", "r", stdin);
#endif
	int cases; 
	long long sum, sub, x, y;
	scanf("%d", &cases);
	while(cases--){
		scanf("%lld%lld", &sum, &sub);
		x = (sum+sub)/2;
		y = (sum-sub)/2;
		if(y<0 || ((x+y)!= sum) || ((x-y)!=sub) )printf("impossible\n");
		else printf("%lld %lld\n", x, y);
	}
	return 0;
}
