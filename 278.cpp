/*
UVa:278, 是696的升级版

给定一个r行，c列的国际象棋棋盘，问最多能放多少个棋子不相互攻击。
棋子有r(车)
Q(后)
k(马)
K(王)


*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int cal(char c, int m, int n){
	if(m > n) return cal(c, n, m);
	if(c=='r' || c=='Q') return m;
	if(c=='K') return ((n+1)/2)*((m+1)/2);
	if(m==1) return n;
	else if(m==2){
		int r = (n%4)>=2?2:n%4;
		return (n/4*2+r)*2;
	}
	else return (n*m+1)/2;
}
int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/278.in", "r", stdin);
#endif
	int row, col, cases;
	char ch[10];
	scanf("%d", &cases);
	getchar();
	while(cases--){
		scanf("%s%d%d", ch, &row, &col);
		int ans = cal(ch[0], row, col);
		printf("%d\n", ans);
	}
	return 0;
}
