/*
UVa:591
一堆转叠成一垛垛，求排成等高需移动多少次
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;




int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/591.in", "r", stdin);
#endif
	int n, hi,sum, cases=0;
	int N[100];
	while(scanf("%d", &n) == 1 && n!=0){
		sum = hi = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &N[i]);
			sum += N[i];
		}
		sum /= n;
		for(int i=0; i<n; i++){
			if(N[i] > sum) hi += (N[i] - sum);
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++cases, hi);
	}

	return 0;
}
