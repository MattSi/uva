#include <stdio.h>
#include <string.h>

/*
 * 1. 大写字母代表白字，小写字母代表黑子。白方位于棋盘下部，黑方位于棋盘上部
 * 2. 卒（pP），笔直向前移动，一次一格。但在吃子时，只能考虑吃掉斜前方一格的棋子
 * 3. 马（nN），马走日，不憋腿
 * 4. 象（bB），可沿对角线向前、向后走任意格
 * 5. 车（rR），可沿着水平向前、向后走任意格
 * 6. 后（qQ），可沿水平、竖直、对角线向前、向后走任意格
 * 7. 王（kK），可沿水平、竖直、对角线向前、向后走一格
 * */

/*
 * 输入：多个棋盘，每个棋盘由8行，8列的字母表示。.代表没有棋子，不包含无效字符。最后以空棋盘结束。
 *
 * 输出：对于读入的每个棋盘，输出如下信息之一（d代表从1开始的局面编号）：分别表示白王被将军，黑王被将军和双方均未被将军
 *
 * Game #d: white king is in check.
 * Game #d: black king is in check.
 * Game #d: no king is in check.
 *
 */

#define SIZE 8
#define TRUE 1
#define FALSE 0

char board[SIZE][SIZE];

void read_board(){
	int r;
	char row[10];
	size_t len;
	for(r = 0; r<SIZE; r++){
		fgets(row, 10, stdin);
		len = strlen(row);
		if(len > 0 && row[len - 1] == '\n'){
			row[--len] = '\0';
		}
		strncpy(board[r], row, SIZE);
	}
}

int is_board_empty(){
	int i, j;
	/* 0 means empty, 1 means not empty */
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			if(board[i][i] != '.')
				return FALSE;
		}
	}
	return TRUE;
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("./tests/10196.in","r", stdin);
#endif
	while(1){
		read_board();
		if(is_board_empty() == TRUE){
			printf("Empty");
			break;
		}
		printf("Not empty");

	}
	return 0;
}















