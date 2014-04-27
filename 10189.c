#include <stdio.h>
#include <string.h>

#define MAXLEN 120

int main(int argc, char*argv[]){

    int row, col, i, j;
    int matrix[MAXLEN][MAXLEN];
    char line[MAXLEN];
    int field = 1;

#ifndef ONLINE_JUDGE
    freopen("./tests/10189.in", "r", stdin);
#endif
    while(scanf("%d%d\n", &row, &col)>0){
        if(row==0 && col==0)break;
        if(field>1)printf("\n");
        memset(matrix, 0, sizeof(matrix));
        for(i=1; i<row+1; i++){
            fgets(line, MAXLEN, stdin);
            for(j=0; j<col; j++){
                if(line[j] == '*'){
                    matrix[i][j+1] = -1;
                }
            }
        }

        for(i=1; i<=row; i++){
            for(j=1; j<=col; j++){
                if(matrix[i][j] == -1){
                    matrix[i-1][j-1] = matrix[i-1][j-1]==-1?-1:matrix[i-1][j-1]+1;
                    matrix[i-1][j] = matrix[i-1][j]==-1?-1:matrix[i-1][j]+1;
                    matrix[i-1][j+1] = matrix[i-1][j+1]==-1?-1:matrix[i-1][j+1]+1;
                    matrix[i][j-1] = matrix[i][j-1]==-1?-1:matrix[i][j-1]+1;
                    matrix[i][j+1] = matrix[i][j+1]==-1?-1:matrix[i][j+1]+1;
                    matrix[i+1][j-1] = matrix[i+1][j-1]==-1?-1:matrix[i+1][j-1]+1;
                    matrix[i+1][j] = matrix[i+1][j]==-1?-1:matrix[i+1][j]+1;
                    matrix[i+1][j+1] = matrix[i+1][j+1]==-1?-1:matrix[i+1][j+1]+1;
                }
            }
        }
        printf("Field #%d:\n", field++);
        for(i=1; i<=row; i++){
            for(j=1; j<=col; j++){
                if(matrix[i][j] == -1)printf("*");
                else printf("%d", matrix[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}
