/*
UVa:696

给定一个r行，c列的国际象棋棋盘，问最多能放多少个马Knight不相互攻击。

+--+--+--+--+--+
|k |  |k |  |k |
+--+--+--+--+--+
|  |k |  |k |  |
+--+--+--+--+--+
|k |  |k |  |k |
+--+--+--+--+--+
|  |k |  |k |  |
+--+--+--+--+--+
|k |  |k |  |k |
+--+--+--+--+--+

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
	FILE *fp = freopen("./tests/696.in", "r", stdin);
#endif
	int row, col;
	while(scanf("%d%d\n", &row, &col)==2 ){
		if(row==0 && col==0)break;
		int min_v = min(row, col);
		int max_v = max(row, col);
		if(min_v == 0){
			printf("0 knights may be placed on a %d row %d column board.\n", row, col);
		}else if(min_v == 1){
			printf("%d knights may be placed on a %d row %d column board.\n", max_v, row, col);
		}else if(min_v == 2){
			int r = (max_v%4)>=2?2:(max_v%4);
			int ans = (max_v/4*2+r)*2;
			printf("%d knights may be placed on a %d row %d column board.\n", ans, row, col);
		}
		else{
			int ans = (row * col +1)/2;
			printf("%d knights may be placed on a %d row %d column board.\n", ans, row, col);
		}
	}
	return 0;
}
