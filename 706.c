#include <stdio.h>
#include <string.h>


#define LEN 30 
char matrix[LEN][LEN*4];
char digits[10][10]={
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011",
};

void draw_digit(int col, int s, int digit);
int main(int argc, char* argv[]){
    int s , i, j;
    char num[10];
    size_t len;
#ifndef ONLINE_JUDGE
    freopen("./tests/706.in", "r", stdin);
#endif
    while(scanf("%d%s\n", &s, num)>0){
        if(s==0 && strcmp(num, "0")==0)break;
        memset(matrix, ' ', sizeof(matrix));
        for(i=0; i<LEN; i++){
            matrix[i][LEN*4-1]='\0';
        }
        len = strlen(num);
        for(i=0; i<len; i++){
            draw_digit(i, s, num[i]-'0');         
        }
        printf("%d\n", (s+2)*len +len-1);
        for(i=0; i<2*s+3; i++){
            for(j=0; i<(s+2)*len+len-1; j++)
                printf("%c", matrix[i][j]);
            printf("\n");
            printf("=======================\n");
        }
        printf("\n");
    }
    return 0;
}
void draw_digit(int col,int s, int digit){
    int rcol = col *(s+3); /* starter of the col */
    int i, j;
    char *p = digits[digit];
    for(i=0; i<7; i++){
        /*printf("%c", p[i]);*/
        switch(i)
        {
            case 0:
            for(j=0; j<s; j++)
                matrix[0][rcol+1+j] = '-';
                break;
            case 1:
            for(j=0; j<s; j++)
                matrix[1+j][rcol] = '|';
                break;
            case 2:
            for(j=0; j<s; j++)
                matrix[1+j][rcol+s+1] = '|';
                break;
            case 3:
            for(j=0; j<s; j++)
                matrix[s+1][rcol+1+j] = '-';
                break;
            case 4:
            for(j=0; j<s; j++)
                matrix[1+j+s][rcol] = '|';
                break;
            case 5:
            for(j=0; j<s; j++)
                matrix[1+j+s][rcol+s+1] = '|';
                break;
            case 6:
            for(j=0; j<s; j++)
                matrix[2*s+2][rcol+1+j] = '-';
                break;
            default:
                break;
        }
    }
}
