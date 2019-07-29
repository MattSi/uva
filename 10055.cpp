/*
UVa:10055

*/


#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10055.in", "r", stdin);
#endif
	long long a, b;
	while(scanf("%lld%lld", &a, &b) != EOF){
		if(a>b)printf("%lld\n", (a-b));
		else printf("%lld\n", (b-a));
	}
	return 0;
}
