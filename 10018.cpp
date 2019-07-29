/*
UVa:10018
将一个数反转相加
例如26258 -> 85262, 相加得111520,
再将111520反转相加得 111520->025111, 相加得：136631. 首尾相同

问给定一个数，多少次操作得到首尾相同的数
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;


long long  revertadd(long long n){
	long long rn = 0, m, orign = n;
	while(n>0){
		m = n % 10;
		rn = rn*10 +m;
		n/=10;
	}
	return rn+orign;
}

bool equaln(long long  n){
	long long rn = 0, m, orign=n;
	while(n>0){
		m = n % 10;
		rn = rn*10 +m;
		n/=10;
	}
	return rn==orign;
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10018.in", "r", stdin);
#endif
	int cases,  count;
	long long n;
	scanf("%d", &cases);
	while(cases--){
		count = 0;
		scanf("%lld", &n);
		while(true){
			n = revertadd(n);
			count++;
			if(equaln(n)) break;
		}
		printf("%d %lld\n", count, n);
	}
	return 0;
}
