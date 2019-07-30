/*
UVa:11417
给定一个数N，求出任意两个小于N的数的最大公约数之和
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int N=501;
int G[505];

int gcd(int x, int y){
	int z;
	while(y!=0){
		z = x%y;
		x=y;
		y=z;
	}
	return x;
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11417.in", "r", stdin);
#endif
	int n;
	memset(G, 0, sizeof(G));
	G[1] = 0; G[2] = 1;
	for(int i=3; i<=N; i++){
		G[i] = G[i-1];
		for(int j=1; j<i; j++){
			G[i] += gcd(j, i);
		}
	}
	while(scanf("%d", &n)==1 && n!=0){
		printf("%d\n", G[n]);
	}
	return 0;
}
