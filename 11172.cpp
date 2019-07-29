/*
UVa:11172

*/


#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11172.in", "r", stdin);
#endif
	int cases, a, b;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d%d", &a, &b);
		if(a==b)printf("=\n");
		else if(a>b)printf(">\n");
		else printf("<\n");
	}
	return 0;
}
