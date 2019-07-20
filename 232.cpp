/*
UVa:232
输入一个r行c列的网格(1<=r, c<=10)。黑格用*表示，每个白格都填入一个字母。
如果一个白格的左边相邻位置或者上面相邻的位置没有白格（可能是黑格，也可能出了网格边界），则称这个白格是一个起始格。
首先，将所有的起始格按照从上到下，从左到右的顺序编号为1，2，3...

接下来要找出所有的横向单词Across，这些单词必须从一个起始格开始，向右延申到一个黑格的左边，或者网格的最右列。
最后找出所有的竖向单词Down，这些单词必须从一个起始格开始，向下延申到一个黑格的上面，或者整个网格的最下行。


*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;
const int SIZE=12;

char puzzle[SIZE][SIZE];
int  init_g[SIZE][SIZE];

bool boundary_check(int r, int c, int row, int col){
	if(r<0 || r>=row || c<0 || c>=col){
		return false;
	}else if(puzzle[r][c] == '*'){
		return false;
	}
	return true;
}

void mark_init_g(int row, int col){
	int i, j;
	int ind=0;
	memset(init_g, 0, sizeof(init_g));
	for(i=0; i<row; i++)
		for(j=0; j<col; j++){
			if (puzzle[i][j] == '*'){
				continue;
			}
			if( !boundary_check(i-1, j, row, col) || !boundary_check(i, j-1, row, col))
				init_g[i][j] = ++ind;
		}
}

void print_across(int row, int col){
	printf("Across\n");
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){			
			if(init_g[i][j] == 0) continue;
			if(j==0 || puzzle[i][j-1]=='*'){
				printf("%3d.", init_g[i][j]);
				int k = j;
				while(true){
					if(k>=col || puzzle[i][k]=='*'){
						printf("\n");
						break;
					}else{
						printf("%c", puzzle[i][k++]);
					}
				}
			}
		}
	}
}

void print_down(int row, int col){
	printf("Down\n");
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(init_g[i][j] == 0) continue;
			if(i==0 || puzzle[i-1][j]=='*'){
				printf("%3d.", init_g[i][j]);
				int k = i;
				while(true){
					if(k >= row || puzzle[k][j] == '*'){
						printf("\n");
						break;
					}else{
						printf("%c", puzzle[k++][j]);
					}
				}
			}
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/232.in", "r", stdin);
#endif
	int row, col, cases=0;
	int i, j;
	while(scanf("%d%d\n", &row, &col) == 2){
		memset(puzzle, 0, sizeof(puzzle));
		if(cases++)printf("\n");
		for(i = 0; i < row; i++){
			fgets(puzzle[i], SIZE, stdin);
		}
		printf("puzzle #%d:\n", cases);
		mark_init_g(row, col);
		print_across(row, col);
		print_down(row, col);
	}
	return 0;
}
