/*
UVa:10550 密码锁
给定一个密码锁，和一个初始状态（0-40）
密码是三个数字

1. 顺时针转满2圈，然后转到第一个数字
2. 逆时针转满1圈，然后转到第二个数字
3. 顺时针转到第三个数字

问：解开密码锁一共转多少度
*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10550.in", "r", stdin);
#endif
	int s, a, b, c, sum;
	int R=40;
	while(scanf("%d%d%d%d", &s, &a, &b, &c)==4){
		if(s+a+b+c==0) break;
		sum=0;
		if(s>a) sum+=(s-a)*9;
		else sum += (R+s-a)*9;

		if(b>a) sum += (b-a)*9;
		else sum += (R+b-a)*9;

		if(b>c) sum += (b-c)*9;
		else sum += (R+b-c)*9;

		sum += 1080;
		printf("%d\n", sum);
	}
	return 0;
}

