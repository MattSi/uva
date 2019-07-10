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
    int empty = 1;
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
            if( board[i][j] != '.'){
                empty = 0;
            }
		}
	}
	return empty;
}

int in_map(int i, int j){
	return (i>=0 && i<SIZE) && (j>=0 && j<SIZE);
}

int w_check_pawn(int i, int j){
	/* 白色卒大写P，位于棋盘下部，往上攻 */
	char piece = board[i][j];
	if((in_map(i-1, j-1) && board[i-1][j-1]=='k') || (in_map(i-1, j+1) && board[i-1][j+1] == 'k')){
		return 1;
	}
	return 0;
}
int b_check_pawn(int i, int j){
	/* 黑色卒小写p，位于棋盘上部，往下攻 */
	if((in_map(i+1, j-1) && board[i+1][j-1]=='K') || (in_map(i+1, j+1) && board[i+1][j+1] == 'K')){
		return 1;
	}
	return 0;
}

int knight_di[] = {-1, -2, -2, -1, 1, 2,  2,  1};
int knight_dj[] = {-2, -1,  1,  2, 2, 1, -1, -2};   
int check_knight(int i, int j, char target){
	/* 马可以循环攻击 */
	int n, flag = 0;
	for(n = 0; n < 8; n++)
		if(in_map(i+knight_di[n], j+knight_dj[n]) && board[i+knight_di[n]][j+knight_dj[n]]==target){
			flag = 1;
			break;
		}
	return flag;
}

int bishop_di[] = {-1, -1, 1,  1};
int bishop_dj[] = {-1,  1, 1, -1};
int check_bishop(int i, int j, char target){
	/* 象可以沿着对角线，向前或向后，攻击王时，中间不能有遮挡 */
	int flag, di, dj, t;

	/* 1. 分别对左上、右上、右下、左下的方向进行检查  */
	flag = 0;
	for(t = 0; t < 4; t++){
		di = bishop_di[t], dj = bishop_dj[t];
		while(1){
			if(!in_map(i+di, j+dj)) break;
			if(board[i+di][j+dj] == '.'){
				di += bishop_di[t];
				dj += bishop_dj[t];
			}else if(board[i+di][j+dj] == target) {
				flag = 1; return flag;
			}else{
				break;
			}
		}
	}
	return flag;
}

int rook_di[] = { 0, -1, 0, 1};
int rook_dj[] = {-1, 0,  1, 0}; 
int check_rook(int i, int j, char target){
	/* 车可以沿着水平或者竖直方向移动。 攻击王时，中间不能有遮挡。*/
	int flag, di, dj, t;
	/* 1. 分别对左、上、右、下的方向进行检查  */
	flag = 0;
	for(t = 0; t < 4; t++){
		di = rook_di[t], dj = rook_dj[t];
		while(1){
			if(!in_map(i+di, j+dj)) break;
			if(board[i+di][j+dj] == '.'){
				di += rook_di[t];
				dj += rook_dj[t];
			}else if(board[i+di][j+dj] == target) {
				flag = 1; return flag;
			}else{
				break;
			}
		}
	}
	return flag;

}

int queen_di[] = { 0, -1, -1, -1, 0, 1, 1,  1};
int queen_dj[] = {-1, -1,  0,  1, 1, 1, 0, -1};  
int check_queen(int i, int j, char target){
	int flag, di, dj, t;
	/* 1. 分别对左、上、右、下的方向进行检查  */
	flag = 0;
	for(t = 0; t < 8; t++){
		di = queen_di[t], dj = queen_dj[t];
		while(1){
			if(!in_map(i+di, j+dj)) break;
			if(board[i+di][j+dj] == '.'){
				di += queen_di[t];
				dj += queen_dj[t];
			}else if(board[i+di][j+dj] == target) {
				flag = 1; return flag;
			}else{
				break;
			}
		}
	}
	return flag;
}


int king_di[] = {0,  -1, -1, -1, 0, 1, 1,  1};
int king_dj[] = {-1, -1,  0,  1, 1, 1, 0, -1};
int check_king(int i, int j, char target){
	int flag, di, dj, t;
	flag = 0;
	for(t = 0; t<8; t++){
		di = king_di[t];
		dj = king_dj[t];
		if(!in_map(i+di, j+dj)) continue;
		if(board[i+di][j+dj] == target){
			flag = 1;
			return flag;
		}
	}
	return flag;
}

void find_check(int d){
	int i, j, flag;
	char piece;

	printf("Game #%d: ", d);
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			if(board[i][j] == '.') continue;
			flag = 0;
			switch(board[i][j]){
				case 'p': if(b_check_pawn(i, j)) flag = 1;       break;
				case 'P': if(w_check_pawn(i, j)) flag = -1;      break;
				case 'n': if(check_knight(i, j, 'K')) flag = 1;  break;
				case 'N': if(check_knight(i, j, 'k')) flag = -1; break;
				case 'b': if(check_bishop(i, j, 'K')) flag = 1;  break;
				case 'B': if(check_bishop(i, j, 'k')) flag = -1; break;
				case 'r': if(check_rook(i, j, 'K')) flag = 1;    break;
				case 'R': if(check_rook(i, j, 'k')) flag = -1;   break;
				case 'q': if(check_queen(i, j, 'K')) flag = 1;   break; 
				case 'Q': if(check_queen(i, j, 'k')) flag = -1;  break;
				case 'k': if(check_king(i, j, 'K')) flag = 1;    break;
				case 'K': if(check_king(i, j, 'k')) flag = -1;   break;
				default:
					break;
			}
			if(flag == 1) {
				printf("white king is in check.\n");
				return;
			}
			if(flag == -1) {
				printf("black king is in check.\n");
				return;
			}
		}
	}
	
	printf("no king is in check.\n");
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("./tests/10196.in","r", stdin);
#endif
    char buff[SIZE];
	int d=0;
	while(1){
		read_board();
        fgets(buff, SIZE, stdin);
		if(is_board_empty() == TRUE){
			break;
		}
		find_check(++d);
	}
	return 0;
}















