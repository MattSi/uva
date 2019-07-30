/*
UVa:11547
给定一个数，经过一系列运算，求它的（个，十，百）十位上的数字
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11547.in", "r", stdin);
#endif
	int cases, n;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d", &n);
		n = (n*567/9+7492)*235/47-498;
		if(n<0) n *= -1;
		n /= 10;
		printf("%d\n", n%10);
	}

	
	return 0;
}
