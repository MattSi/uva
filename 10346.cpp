/*
UVa:10346
Peter有n支香烟，抽完的k支烟屁股还可以组合成一支。问一共可以抽多少支烟。

12 3
=======
17
*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10346.in", "r", stdin);
#endif
	int n, k, sum, butt;
	while(scanf("%d%d", &n, &k) == 2){
		sum =0, butt=0;
		while(n>0){
			sum += n;
			butt += n;
			n = butt/k;
			butt = butt % k;
		}
		printf("%d\n", sum);
	}
	return 0;
}
