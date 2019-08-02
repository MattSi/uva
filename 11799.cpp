/*
UVa:11799

找最大的数
*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
const int SIZE=128;
int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11799.in", "r", stdin);
#endif
	int cases, z=0, n;
	int v, t;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d", &n);
		t = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &v);
			if(v>t) t=v;
		}
		printf("Case %d: %d\n", ++z, t);
	}
	return 0;
}
