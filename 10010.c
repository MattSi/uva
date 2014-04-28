#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>
#define N 50

char matrix[N][N];
int row, col;

int map(char ch){
    ch = toupper(ch);
    return (ch - 'A');
}

void getlocation(char ch, int *therow, int *thecol){
    int i, j, pos;
    pos = (*therow)*col + *thecol + 1;
    if(pos == row * col){
        *therow = -1; *thecol = -1;
        return;
    }
    while(pos<row*col){
        if((ch) == matrix[pos/col][pos%col]){
            *therow = pos / col;
            *thecol = pos % col;
            return;
        }
        pos++;
    }
    *therow = -1;
    *thecol = -1;
}

int match(char word[N], int len, int i, int j, int dir){
    int k=0;
    if(dir == 1){/*pure left*/
        if(j+1 < len)return 0;
        while(k<len)if(word[k++] != matrix[i][j--]) return 0;
        return 1;
    }
    else if(dir == 2){/*pure right*/
        if(col-j+1<len)return 0;
        while(k<len)if(word[k++] != matrix[i][j++]) return 0;
        return 1;
    }
    else if(dir == 3){/*pure up*/
        if(i+1<len)return 0;
        while(k<len)if(word[k++] != matrix[i--][j]) return 0;
        return 1;
    }
    else if(dir == 4){/*pure down*/
        if(row-i+1<len)return 0;
        while(k<len)if(word[k++] != matrix[i++][j]) return 0;
        return 1;
    }
    else if(dir == 5){/*left and up*/
        if(j+1<len || i+1<len)return 0;
        while(k<len)if(word[k++] != matrix[i--][j--]) return 0;
        return 1;
    }
    else if(dir == 6){/* left and down*/
        if(j+1<len || row-i+1<len) return 0;
        while(k<len)if(word[k++] != matrix[i++][j--]) return 0;
        return 1;
    }
    else if(dir == 7){/* right and up*/
        if(col-j+1 <len || i+1<len)return 0;
        while(k<len)if(word[k++] != matrix[i--][j++]) return 0;
        return 1;
    }
    else if(dir == 8){/* right and down */
        if(row-i+1<len || col-j+1<len)return 0;
        while(k<len)if(word[k++] != matrix[i++][j++]) return 0;
        return 1;
    }
    return 0;
}


int main(int argc, char* argv[]){
    int i,j,t,dir, len, find, nouse;
    int num, blankflag=0, wordnum;
    char word[N+10];
#ifndef ONLINE_JUDGE
    FILE* fp = NULL;
    fp = freopen("./tests/10010.in", "r", stdin);
#endif
    nouse = scanf("%d", &num);
    while(num--){
        if(blankflag++!=0)printf("\n");/*dont print blank line at first case*/
        nouse = scanf("%d%d", &row, &col);
        for(i = 0; i<row; i++){
            nouse = scanf("%s", word);
            t=0;
            while(word[t]!='\0'){
                matrix[i][t] = toupper(word[t]);
                t++;
            }
        }
        nouse = scanf("%d", &wordnum);
        for(t = 0; t<wordnum; t++){
            nouse = scanf("%s", word);
            len = strlen(word);
            for(i=0; i<len; i++)word[i] = toupper(word[i]);/* change input to upper case */
            find = 0; i=0;j=0;
            while(!find && (i+j)>=0){
                if(i+j == 0){     
                    for(dir=1; dir<=8; dir++){
                        if(match(word, len, i, j, dir)){
                            printf("%d %d\n", i+1, j+1);
                            find=1;
                            break;
                        }
                    }
                }
                getlocation(word[0], &i, &j);     
                for(dir=1; dir<=8; dir++){
                    if(match(word, len, i, j, dir)){
                        printf("%d %d\n", i+1, j+1);
                        find=1;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}


