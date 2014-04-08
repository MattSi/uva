#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COL 60
char words[102][60];
int number;
int get_col(int length){
    return (COL-length) / (length + 2) + 1;
}
int get_row(int col){
    double row = number * 1.0 / col;
    return (int)ceil(row);
}
void print_fill(int currlen, int mostlen){
    int i;
    for(i=0; i<mostlen+2-currlen;i++)
        printf(" ");
}

void print(int row, int col, int length){
    int i, j, currp = 0;
    for(i=0; i<COL; i++)printf("-");
    printf("\n");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            if(i + row*j < number){
                printf("%s", words[i + row*j]);
                print_fill(strlen(words[i+row*j]), length);
            }
        }
        printf("\n");
    }
}
int comp(const void *arg1, const void *arg2){
    char *a = (char*) arg1, *b =(char*) arg2;
    return strcmp(a, b);
}
int main(int argc, char* argv[])
{
    int i, len, col, row, maxlen, nouse;
    char word[COL];
#ifndef ONLINE_JUDGE
    FILE *fp = NULL;
    fp = freopen("./tests/400.in", "r", stdin);
    fp = freopen("./tests/400.out", "w", stdout);
#endif
    while(scanf("%d\n", &number) != EOF){
        maxlen = 0;
        memset(words, 0, sizeof(words));
        for(i=0; i<number; i++){
            nouse = scanf("%s", words[i]);
            len = strlen(words[i]);
            if(len > maxlen )maxlen = len;
        }
        qsort(words, number, sizeof(words[0]), comp);
        col = get_col(maxlen);
        row = get_row(col);
        print(row, col, maxlen);
    }
	return 0;
}

