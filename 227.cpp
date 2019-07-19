/*
有一个5*5的网格。其中，恰好有个格子是空的，其他的格子各有一个字母。
一共有4种指令ABLR，分别表示把空格上、下、左、右的相邻字母转移到空格中。
输入初始网格和指令序列（以数字0结束），输出指令执行完毕后的网格。
如果有非法指令，应输出"This puzzle has no final configuration."
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

const int SIZE = 5;
char puzzle[SIZE][SIZE+5];

bool read_puzzle(int &x, int &y){
	memset(puzzle, 0, sizeof(puzzle));
	char ch;
	for(int i=0; i<SIZE; i++){
		fgets(puzzle[i], SIZE+5, stdin);
		puzzle[i][SIZE]='\0';
		if(puzzle[i][0] == 'Z'){
			return false;
		}
		for(int j=0; j<SIZE; j++){
			if(puzzle[i][j] == ' '){
				x = i;
				y = j;
			}
		}
	}

	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/227.in", "r", stdin);
#endif
	int x, y;
	while(read_puzzle(x, y)){
	//PUZZLE输入合法，接下来读入指令。	
	}
	return 0;
}
