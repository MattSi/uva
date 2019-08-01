/*
UVa:573
蜗牛爬墙，墙高H，白天爬U，夜晚降D，第二天开始的疲劳因子是F，问几天能爬出，或者几天失败？

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
	FILE *fp = freopen("./tests/573.in", "r", stdin);
#endif
	int h, u, d, f;
	while(scanf("%d%d%d%d", &h, &u, &d, &f) == 4){
		if(h==0 && u==0 && d==0 && f==0)break;
		int day = 1;
		double inith=0.0,du;
		while(true){
			du = u *(1- (day-1)*f/100.0);
			if(du<0)du=0;
			inith += du;
			if(inith>h){printf("success on day %d\n", day); break;}
			inith -=d;
			if(inith<0){printf("failure on day %d\n", day);break;}
			day++;
		}
	}
	return 0;
}
