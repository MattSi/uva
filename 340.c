#include <stdio.h>
#define LEN 1024
int findA(int pass[], int guess[], int len);
int findB(int pass[], int guess[], int len);
int main(int argc, char* argv[])
{
#ifndef ONLINE_JUDGE
    FILE *fp = freopen("./tests/340.in", "r", stdin);
#endif
    int num, i, game = 0;
    int pass[LEN],pass2[LEN], guess[LEN];
    while(1){
        scanf("%d", &num);
        if(!num)break;
        printf("Game %d:\n", ++game);
        for(i=0; i<num; i++){
            scanf("%d", &pass[i]);
        }
        while(1){
            for(i=0; i<num; i++){
                scanf("%d", &guess[i]);
                pass2[i] = pass[i];
            }
            if(guess[0] == 0)break;
            printf("    (%d,",  findA(pass2, guess, num));
            printf("%d)\n", findB(pass2, guess, num));
        }
        num = 0;
    }
	return 0;
}
int findA(int pass[], int guess[], int len)
{
    int i, num=0;
    for(i=0; i<len; i++)
        if(pass[i] == guess[i]){
            num++;
            pass[i] = 0;
            guess[i] = 0;
        }
    return num;
}
int findB(int pass[], int guess[], int len)
{
    int i,j, num=0;
    for(i=0; i<len; i++){
        if(guess[i] == 0)continue;
        for(j=0; j<len; j++){
            if(guess[i] == pass[j]){
                num++;
                pass[j] = 0;break;
            }
        }
    }
    return num;
}
