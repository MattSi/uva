/*
UVa:11727 Cost Cutting
公司削减预算，请人走路，只留不是最贵，也不是最便宜的人。

给你3个数，求中间值
*/


#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11727.in", "r", stdin);
#endif
	int cases, a, b, c, ans, k=0;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d%d%d", &a, &b, &c);
		if(a > b){
			if(a<=c) ans = a;
			else{
				if(b>=c) ans = b;
				else ans = c;
			}
		} else {
			if(a>c) ans = a;
			else{
				if(b>c) ans = c;
				else ans = b;
			}
		}
		printf("Case %d: %d\n",++k, ans);
	}
	return 0;
}
