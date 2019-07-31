/*
UVa:10110

有n盏灯，初始状态都是关闭的，第i次操作时，将n盏灯中能整除i的那一盏状态反转。
问第n次操作后，第n盏灯的状态。

本质上是求n的质因数的奇偶性。只有n是完全平方数时，n的所有质因数的个数才是奇数。
判断即可
*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10110.in", "r", stdin);
#endif
	long long n;
	while(scanf("%lld", &n) == 1 && n!=0){
		long long r = sqrt(n);
		if(n == r*r)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
