/*
UVa:579
输入一个时间，求出分针和时针之间的夹角

输入：
3:00
2:10
3:04
11:59
5:01
4:00
2:05
12:00
1:59
1:01
0:00
输出：
90.000
5.000
68.000
5.500
144.500
120.000
32.500
0.000
65.500
24.500
*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

const int SIZE=1024;
int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/579.in", "r", stdin);
#endif
	int h, m;
	while(scanf("%d:%d", &h, &m)==2){
		if(!h && !m) break;
		double hang = 30*(h+1.0/60*m);
		double mang = m*6.0;
		double ans = (hang - mang);
		if(ans<0) ans +=360.0;
		if(ans>180.0) ans = 360.0-ans;
		printf("%.3f\n", ans);
	}
	return 0;
}
