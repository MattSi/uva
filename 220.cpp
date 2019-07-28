/*
UVa:220
模拟黑白棋的游戏进程。
输入一个8*8的棋盘以及当前下一次操作的游戏者，处理3种指令：
L指令打印出所有的合法操作，按照从上到下，从左到右的顺序排列（没有合法操作时输出No legal move）
Mrc指令放一枚棋子在(r,c)。如果当前游戏者没有合法操作，则先切换游戏者在操作。输入保证这个操作是合法的。
Q指令推出游戏，并打印当前棋盘。


1
--------
--------
--------
---WB---
---BW---
--------
--------
--------
W
L
M35
L
Q
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE=8;
char board[SIZE+1][SIZE+2];
char curr_player;

void init_board(){
	char buf[8];
	for(int i=1; i<=SIZE; i++){
		scanf("%s", board[i]);
	}
	scanf("%s", buf);
	curr_player = buf[0];
}

void switch_player(){
	if(curr_player == 'W') curr_player = 'B';
	else curr_player = 'W';
}
char get_cp_player(char c_player){
	if(c_player == 'W') return 'B';
	else return 'W';
}

bool is_p_valid(int r, int c, char c_player){
	char cp = get_cp_player(c_player);
	bool valid = true;
	if(board[r][c] != '-') return false;
	


	return true;
}

void p_valid_pos(){
	for(int i=1; i<=SIZE; i++){
		for(int j=1; j<=SIZE; j++){
		
		}
	}
}
void simulate(){
	char cmd[8];
	while(true){
		scanf("%s", cmd);
		if(cmd[0] == 'L'){
			//打印当先选手的所有合法操作
			printf("打印合法操作\n");
		}else if(cmd[0] == 'M'){
			// 放棋子
			printf("放棋子\n");
		}else if(cmd[0] == 'Q'){
			printf("Q cmd.\n");
			break;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/220.in", "r", stdin);
#endif
	int cases;
	未完成
	scanf("%d", &cases);
	while(cases--){
		init_board();
		simulate();
	}
	return 0;
}
