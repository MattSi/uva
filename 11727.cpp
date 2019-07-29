/*
UVa:11727

*/


#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11727.in", "r", stdin);
#endif
	int cases, a, b, i, ans, k=0;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d%d", &a, &b);
		i = a%2? a: a+1; ans=0;
		while(i<=b){
			ans += i;
			i += 2;
		}
		printf("Case %d: %d\n",++k, ans);
	}
	return 0;
}
