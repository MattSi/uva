/*
UVa:11044 尼斯湖水怪

用声纳探测尼斯湖水怪，每个声纳的探测范围是9宫格，给定一个row * col的湖面，
问最少需要放多少个声纳。

湖边不需要声纳

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
	FILE *fp = freopen("./tests/11044.in", "r", stdin);
#endif
	int cases, row, col;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d%d", &row, &col);
		row -= 2; col -= 2;
		row = row<0? 0:row;
		col = col<0? 0:col;
		int r_r = row % 3?1:0;
		int r_c = col % 3?1:0;
		int ans = (row/3+r_r)*(col/3+r_c);
		printf("%d\n", ans);
	}
	return 0;
}

