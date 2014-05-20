#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 53
int flush[101][N];
int poke[2][N];
int token_ring;

char* map1[] = {
	"error",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"10",
	"Jack",
	"Queen",
	"King",
	"Ace"
};

char* map2[] = {
	"Clubs",
	"Diamonds",
	"Hearts",
	"Spades"
};

void init(){
	int i;
	memset(flush, 0, sizeof(flush));
	memset(poke, 0, sizeof(poke));
	for(i=1; i<=52; i++){
		poke[0][i] = i;
	}
	token_ring = 0;
}
void print(){
	
	int i;
	int suit; /* 0 clubs, 1 diamonds, 2 hearts, 3, spades*/
	int value;
	for(i=1; i<N; i++){
		suit = (poke[token_ring][i] -1) / 13;
		value = poke[token_ring][i] - suit * 13;
		printf("%s of %s\n", map1[value], map2[suit]);
	}
}
int main(int argc, char* argv[])
{
	int cases, flush_number, i, j, ring;
	size_t len;
	char buff[8];
#ifndef ONLINE_JUDGE
	freopen("./tests/10205.in", "r", stdin);
#endif

	scanf("%d\n", &cases);
	while(cases-- > 0){
		init();
		scanf("%d", &flush_number);
		for(i=1; i<=flush_number; i++){
			for(j=1; j<=52; j++){
				scanf("%d\n", &flush[i][j]);
			}
		}
		while(fgets(buff, 8, stdin)){
            len = strlen(buff);
            if(buff[len-1] == '\n')
                buff[len-1] = '\0';
            if(buff[0] == '\0')
                break;
			/* 拿到当前洗牌的法 */
			i = atoi(buff);

			/* 根据拿到的令牌决定使用哪一个poke */
			ring = (token_ring + 1) % 2;
			for(j = 1; j < N; j++)
				poke[ring][j] = poke[token_ring][flush[i][j]];
			
			token_ring = (token_ring + 1) % 2;
        }
		print();
		if(cases > 0)
			printf("\n");
	}
	return 0;
}

