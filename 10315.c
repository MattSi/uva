#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
int black[N];
int white[N];

int black_cp[N];
int white_cp[N];


int map_card(char *card);
int compare(const void *arg1, const void *arg2);
int war();
int is_straight_flush(int card[]);
int is_4ofakind(int card[]);
int is_fullhouse(int card[]);
int is_flush(int card[], int card_cp[]);
int is_straight(int card[], int card_cp[]);
int is_3ofakind(int card[]);
int is_2paires(int card[], int card_cp[]);
int is_pair(int card[], int card_cp[]);
int value_card(int card[], int card_cp[]);
int main(int argc, char* argv[])
{
	char b[N][N], w[N][N];
	int i, r;
#ifndef ONLINE_JUDGE
	freopen("./tests/10315.in", "r", stdin);
	
#endif
	while(scanf("%s%s%s%s%s%s%s%s%s%s", b[0],b[1],
		 b[2],b[3],b[4], w[0], w[1], w[2], w[3], w[4]) == 10){
	
		/* 读入并转化黑方 */
		for(i=0; i<N; i++)
			black[i] = map_card(b[i]);

		/* 读入并转化白方 */
		for(i=0; i<N; i++)
			white[i] = map_card(w[i]);

		qsort(black, N, sizeof(int), compare);
		qsort(white, N, sizeof(int), compare);
		r = war();
		if(r>0)
			printf("Black wins.\n");
		else if(r==0)
			printf("Tie.\n");
		else
			printf("White wins.\n");
	}
	return 0;
}

int map_card(char *card){
	int card_value = 0;
	int clubs = 0;
	if(card[0] >= '2' && card[0]<='9')
		card_value = card[0] - '0';
	else if(card[0] == 'T')
		card_value = 0xA;
	else if(card[0] == 'J')
		card_value = 0xB;
	else if(card[0] == 'Q')
		card_value = 0xC;
	else if(card[0] == 'K')
		card_value = 0xD;
	else 
		card_value = 0xE;
	if(card[1] == 'C')
		clubs = 0;
	else if(card[1] == 'D')
		clubs = 1;
	else if(card[1] == 'H')
		clubs = 2;
	else 
		clubs = 3;
	card_value = card_value << 4;
	card_value += clubs;
	return card_value;
}

int compare(const void *arg1, const void *arg2){
	return *(int*)arg1 - *(int*)arg2;
}


int is_pair(int card[], int card_cp[]){
	
	if(
		(card[0] & 0xF0) == (card[1] & 0xF0) ){
			card_cp[0] = card[0];
			card_cp[1] = card[4];
			card_cp[2] = card[3];
			card_cp[3] = card[2];
			return 0x2f;
	}
	else if(
		(card[1] & 0xF0) == (card[2] & 0xF0)
		){
			card_cp[0] = card[1];
			card_cp[1] = card[4];
			card_cp[2] = card[3];
			card_cp[3] = card[0];
			return 0x2f;
	}
	else if(
		(card[2] & 0xF0) == (card[3] & 0xF0)
		){
			card_cp[0] = card[2];
			card_cp[1] = card[4];
			card_cp[2] = card[1];
			card_cp[3] = card[0];
			return 0x2f;
	}
	else if(
		(card[4] & 0xF0) == (card[3] & 0xF0)
		){
			card_cp[0] = card[3];
			card_cp[1] = card[2];
			card_cp[2] = card[1];
			card_cp[3] = card[0];
			return 0x2f;
	}
	else
		return 0;
}
int is_2paires(int card[], int card_cp[]){
	if(
		(card[0] & 0xF0) == (card[1] & 0xF0) &&
		(card[2] & 0xF0) == (card[3] & 0xF0)
		){
		card_cp[0] = card[2];
		card_cp[1] = card[0];
		card_cp[2] = card[4];
		return 0x3f;
	}
	else if(
		(card[0] & 0xF0) == (card[1] & 0xF0) &&
		(card[3] & 0xF0) == (card[4] & 0xF0)
		){
			card_cp[0] = card[3];
			card_cp[1] = card[0];
			card_cp[2] = card[2];
			return 0x3f;
	}
	else if(
		(card[1] & 0xF0) == (card[2] & 0xF0) &&
		(card[3] & 0xF0) == (card[4] & 0xF0)
		){
			card_cp[0] = card[3];
			card_cp[1] = card[1];
			card_cp[2] = card[0];
			return 0x3f;
	}
	return 0;
}
int is_3ofakind(int card[]){
	int result;
	if( (card[0] & 0xF0) == (card[1] & 0xF0) &&
		(card[1] & 0xF0) == (card[2] & 0xF0)) 
		result = ((4<<4)+(card[0]>>4));
	else if(
		(card[1] & 0xF0) == (card[2] & 0xF0) &&
		(card[2] & 0xF0) == (card[3] & 0xF0) 
		)
		result = ((4<<4)+(card[1]>>4));
	else if(
		(card[2] & 0xF0) == (card[3] & 0xF0) &&
		(card[3] & 0xF0) == (card[4] & 0xF0) 
		)
		result = ((4<<4)+(card[2]>>4));
	else
		result = 0;

	return result;
}
int is_straight(int card[], int card_cp[]){
	if( ((card[0]>>4) + 1) == (card[1]>>4) &&
		((card[1]>>4) + 1) == (card[2]>>4) &&
		((card[2]>>4) + 1) == (card[3]>>4) &&
		((card[3]>>4) + 1) == (card[4]>>4)){
			memcpy(card_cp, card, sizeof(int) * N);
			return ((5<<4) + 0xF) ;
	}
	else 
		return 0;
}

int is_flush(int card[], int card_cp[]){
	int clubs = 0;
	if( (card[0]&0xF) == (card[1]&0xF) &&
		(card[1]&0xF) == (card[2]&0xF) &&
		(card[2]&0xF) == (card[3]&0xF) &&
		(card[3]&0xF) == (card[4]&0xF))
		clubs = 1;
	if(clubs){
		memcpy(card_cp, card, sizeof(int) * N);
		return ((6<<4) + 0xF);
	}
	else
		return 0;
}
int is_fullhouse(int card[]){
	int result;
	if( (card[0] & 0xF0) == (card[1] & 0xF0) &&
		(card[1] & 0xF0) == (card[2] & 0xF0) &&
		(card[3] & 0xF0) == (card[4] & 0xF0) 
		)
		result = ((7<<4)+(card[0]>>4));
	else if(
		(card[0] & 0xF0) == (card[1] & 0xF0) &&
		(card[2] & 0xF0) == (card[3] & 0xF0) &&
		(card[3] & 0xF0) == (card[4] & 0xF0)
		)
		result = ((7<<4)+(card[4]>>4));
	else 
		result = 0;
	return result;
}
int is_4ofakind(int card[]){
	int result;
	if( (card[0] & 0xF0) == (card[1] & 0xF0) &&
		(card[1] & 0xF0) == (card[2] & 0xF0) &&
		(card[2] & 0xF0) == (card[3] & 0xF0) 
		)
		result = ((8<<4)+(card[0]>>4));
	else if(
		(card[3] & 0xF0) == (card[4] & 0xF0) &&
		(card[1] & 0xF0) == (card[2] & 0xF0) &&
		(card[2] & 0xF0) == (card[3] & 0xF0) 
		)
		result = ((8<<4)+(card[4]>>4));
	else
		result = 0;

	return result;
}
int is_straight_flush(int card[]){
	int clubs = 0;

	/* 判断同花顺 */
	if( (card[0]&0xF) == (card[1]&0xF) &&
		(card[1]&0xF) == (card[2]&0xF) &&
		(card[2]&0xF) == (card[3]&0xF) &&
		(card[3]&0xF) == (card[4]&0xF))
		clubs = 1;
	else 
		clubs = 0;

	if(clubs){
		if( ((card[0]>>4) + 1) == (card[1]>>4) &&
			((card[1]>>4) + 1) == (card[2]>>4) &&
			((card[2]>>4) + 1) == (card[3]>>4) &&
			((card[3]>>4) + 1) == (card[4]>>4))
			return (9<<4) + (card[4]>>4);
		else
			return 0;
	}
	else
		return 0;
}
int value_card(int card[], int card_cp[]){
	int clubs = 0;
	int result;
	
	result = is_straight_flush(card);
	if(result)return result;
	result = is_4ofakind(card);
	if(result)return result;
	result = is_fullhouse(card);
	if(result)return result;
	result = is_flush(card, card_cp);
	if(result)return result;
	result = is_straight(card, card_cp);
	if(result)return result;
	result = is_3ofakind(card);
	if(result)return result;
	result = is_2paires(card, card_cp);
	if(result)return result;
	result = is_pair(card, card_cp);
	if(result)return result;
	
	return 0;
	
}

int check_highcard(int black[], int white[]){
	int i;
	int b, w, r;
	for(i=0; i<N; i++){
		b = (black[N-i-1] & 0xF0);
		w = (white[N-i-1] & 0xF0);
		r = b - w;
		if(r>0) return 1;
		else if(r<0) return -1;
	}
	return 0;
}


/* 斗牌， 返回1black赢， 返回-1white赢， 返回0平了*/
int war(){
	int bv, wv, i, t;
	memset(black_cp, 0, sizeof(black_cp));
	memset(white_cp, 0, sizeof(white_cp));

	bv = value_card(black, black_cp);
	wv = value_card(white, white_cp);
	if(bv > wv)
		return 1;
	else if(bv < wv)
		return -1;
	else{
		if(bv == 0 ){
			return check_highcard(black, white);
		}
		else if( bv ==0x6F || bv == 0x5F){
			return check_highcard(black_cp, white_cp);
		}
		else if(bv ==0x3f){
			for(i=0; i<3; i++){
				t = (black_cp[i]>>4)-(white_cp[i]>>4);
				if(t>0)
					return 1;
				else if(t<0)
					return -1;
			}
			return 0;
		}
		else if(bv == 0x2f){
			for(i=0; i<4; i++){
				t = (black_cp[i] >>4) - (white_cp[i]>>4);
				if(t>0)
					return 1;
				else if(t<0)
					return -1;
			}
			return 0;
		}
	}
	return 0;
}