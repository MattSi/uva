#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ROW 64
#define COL 16
#define NODE 20480

int matrix[ROW][COL];
int tree[NODE];
int number;

int comp(const void *arg1, const void *arg2){
    char *a, *b;
    a = (char*)arg1; b = (char*)arg2;
    return *a - *b;
}
void clean(){
    memset(matrix, 0, sizeof(matrix));
    memset(tree, 0, sizeof(tree));
    number = 0;
}

int main(int argc, char* argv[]){
    int i, j, len, flag, current, next, casenum=0;
    char word[16];
#ifndef ONLINE_JUDGE
    FILE *fp = NULL;
    fp = freopen("./tests/644.in", "r", stdin);
    fp = freopen("./tests/644.out", "w", stdout);
#endif
    clean();
    while(scanf("%s", word) != EOF){
        if(!strcmp(word, "9")){
            /* process ... */
            qsort(matrix, number, sizeof(matrix[0]), comp);
            flag = 1;
            for(i = 0; i<number; i++){
                current = 1;
                for(j = 0; j<=matrix[i][0]; j++){
                    next = matrix[i][j] == 0 ? current*2 : current*2 +1;
                    if(tree[next] == 'x'){
                        printf("Set %d is not immediately decodable\n", ++casenum);
                        flag = 0; break;
                    }
                    current = next;
                }
                tree[current] = 'x';
                if(!flag) break;
            } 
            if(flag)printf("Set %d is immediately decodable\n", ++casenum);
            clean();
        }
        else{
            len = strlen(word);
            matrix[number][0] = len;
            for(i = 0; i<len; i++){
                matrix[number][i+1] = word[i] - '0';
            }
            number++;
        }
    }
    return 0;
}
