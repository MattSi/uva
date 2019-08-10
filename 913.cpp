/*
UVa:913 Joana和奇数
Joana按照如下规律写了奇数列，若在某一行，她写了刚好55个奇数，问这一行最后3个奇数的和是多少？
 1
 3  5  7
 7 11 13 15 17
19 21 23 25 27 29 31

分析：
 x1
 x2  x3  x4
 x5  x6  x7  x8  x9
x10 x11 x12 x13 x14 x15 x16
x17 x18 x19 x20 x21 x22 x23 x24 x25 

*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>



int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/913.in", "r", stdin);
#endif
	long long odd, k, sum;
	while(scanf("%lld", &odd) == 1){
		k = (odd+1)/2;
		sum = 6* k*k-9;
		printf("%lld\n", sum);
	}
	return 0;
}












