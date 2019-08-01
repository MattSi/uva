/*
UVa:488 三角波
给定2个整数，振幅和频率，在屏幕上打印波形

输入：
1

3
2
输出：

1
22
333
22
1

1
22
333
22
1

*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

void print_amp(int amp){
	for(int i=1; i<=amp; i++){
		for(int j=1; j<=i; j++){
			printf("%d", i);
		}
		printf("\n");
	}
	for(int i=amp-1; i>=1; i--){
		for(int j=1; j<=i; j++){
			printf("%d", i);
		}
		printf("\n");
	}
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/488.in", "r", stdin);
#endif
	int cases, amp, fre,z=0;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d\n%d",&amp, &fre);
		for(int i=1; i<=fre; i++){
			print_amp(amp);
			if(cases || i<fre) printf("\n");
		}

	}
	return 0;
}
