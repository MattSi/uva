/*
UVa:10071

*/


#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10071.in", "r", stdin);
#endif
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF){
		printf("%d\n", 2*a*b);
	}
	return 0;
}
