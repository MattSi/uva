/*
UVa:572

输入一个m行，n列的字符串矩阵。统计字符@组成多少个八连块。
如果2个字符'@'所在的格子相邻（横，竖，对角线方向），就说它们属于同一个八连块。
例如
    ****@
	*@@*@
	*@**@
	@@@*@
	@@**@
上图中有两个八连块
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;
const int SIZE=128;
char pic[SIZE][SIZE];
int  idx[SIZE][SIZE];
int row, col, ans;

void dfs(int i, int j, int cnt){
	if(i<0 || i>=row || j<0 || j>=col) return; //出界
	if(idx[i][j] >0 || pic[i][j]!='@' ) return; // 已走过或者不是'@'
	idx[i][j] = cnt;
	for(int dr = -1; dr<=1; dr++){
		for(int dc = -1; dc<=1; dc++){
			if(dr!=0 || dc!=0) dfs(i+dr, j+dc, cnt);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/572.in", "r", stdin);
#endif
	int cnt;
	while(scanf("%d%d", &row, &col) == 2 && row && col){
		memset(pic, 0, sizeof(pic));
		memset(idx, 0, sizeof(idx));
		cnt= 0;
		for(int i=0; i<row; i++) scanf("%s", pic[i]);
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				if(idx[i][j] == 0 && pic[i][j]=='@') dfs(i, j, ++cnt);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
