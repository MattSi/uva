/*
UVa:374
求B^P mod M (B,P均可以很大)

公式1： B^P mod M = (B mod M)^P mod M
公式2： 
B^P mod M = (B^2)^(P/2) mod M (当P为偶数)
B^P mod M = ((B^2)^(P/2) * B) mod M (当P为奇数)


*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int big_mod(int b, int p, int m){
	if(p==0) return 1;
	if(p==1) return b;
	int ans = big_mod(b, p/2, m);
	if(p%2){
		return ((ans * ans)%m *b)%m;
	}else{
		return (ans * ans)%m;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/374.in", "r", stdin);
#endif
	int b, p, m;
	while(scanf("%d%d%d", &b, &p, &m) == 3){
		printf("%d\n", big_mod(b%m, p, m));
	}
	return 0;
}
