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
const int BUFF_SIZE = 8192;
char puzzle[SIZE][SIZE+5];
char cmds[BUFF_SIZE];

bool read_puzzle(int &x, int &y){
	memset(puzzle, 0, sizeof(puzzle));
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

bool boundary_check(int r, int c){
	if(r<0 || r>=SIZE || c<0||c>=SIZE){
		return false;
	}
	return true;
}

bool move_puzzle(int &r, int &c){
	size_t len = strlen(cmds);
	for(int i=0; i<len; i++){
		switch(cmds[i]){
		case 'A':
			if(!boundary_check(r-1, c))
				return false;
			else {
				puzzle[r][c] = puzzle[r-1][c];
				puzzle[r-1][c] = ' ';
				r--;
			}
			break;
		case 'B':
			if(!boundary_check(r+1, c))
				return false;
			else {
				puzzle[r][c] = puzzle[r+1][c];
				puzzle[r+1][c] = ' ';
				r++;
			}
			break;
		case 'R':
			if(!boundary_check(r, c+1))
				return false;
			else {
				puzzle[r][c] = puzzle[r][c+1];
				puzzle[r][c+1] = ' ';
				c++;
			}
			break;
		case 'L':
			if(!boundary_check(r, c-1))
				return false;
			else {
				puzzle[r][c] = puzzle[r][c-1];
				puzzle[r][c-1] = ' ';
				c--;
			}
			break;
		case '0':
			return true;
			break;
		case '\r':
		case '\n':
			break;
		default:
			return false;
		}
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/227.in", "r", stdin);
#endif
	int r, c;
	int ch, i, cases=0;

	while(read_puzzle(r, c)){
		//PUZZLE输入合法，接下来读入指令。	
		memset(cmds, 0, sizeof(cmds));
		i =0;
		while(true){
			ch = getchar();
			cmds[i++] = ch;
			if(ch == '0'){
				getchar();
				break;
			}
		}
		if(cases >0) printf("\n");
		printf("Puzzle #%d:\n", ++cases);
		if(move_puzzle(r, c)){
			//Print Puzzle
			for(i=0; i<SIZE; i++){
				printf("%c %c %c %c %c\n", puzzle[i][0], puzzle[i][1],  puzzle[i][2], puzzle[i][3], puzzle[i][4]);
			}
		} else {
			// Print Error
			printf("This puzzle has no final configuration.\n");
		}
	}
	return 0;
}
