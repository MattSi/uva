/*
UVa:10696
f91递归函数：
很简单
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int f91(int n){
	if(n>=101) return n-10;

	return f91(f91(n+11));
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10696.in", "r", stdin);
#endif
	int n;
	while(scanf("%d", &n)==1 && n!=0){
		int ans = f91(n);
		printf("f91(%d) = %d\n", n, ans);
	}
	return 0;
}
