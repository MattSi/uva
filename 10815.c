
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ROW 50100
#define COL 128

char dic[ROW][COL]={0};
int dicnum = 0;
enum STATUS {Beginning=1, Wording};

void insert(char word[], int len){
    int i;
    for(i=0; i<dicnum; i++){
        if(!strcmp(word, dic[i]))return;
    }
    strncpy(dic[dicnum++], word, COL);
}

int compare(const void *arg1, const void *arg2){
    char* a = (char*)arg1;
    char* b = (char*)arg2;
    return strcmp(a,b);
}
int main(int argc, char* argv[])
{
    char word[COL], ch;
    int i=0, balpha;
    enum STATUS status = Beginning;
#ifndef ONLINE_JUDGE
    FILE* fp=NULL;
    fp = freopen("./tests/10815.in", "r", stdin);
    fp = freopen("./tests/10815.out", "w", stdout);
#endif
    while((ch = getchar()) != EOF){
        balpha = isalpha(ch);
        ch = tolower(ch);
        if(status == Beginning && !balpha){
            continue;
        }else if(status == Beginning && balpha){ /* word started */
            word[i++] = ch;word[i]='\0';
            status = Wording;
        }else if(status == Wording && balpha){
            word[i++] = ch; word[i] = '\0';
        }else if(status == Wording && !balpha){
            status = Beginning;
            insert(word, COL);
            word[0]='\0';
            i = 0;
        }
    }
    qsort(dic, dicnum, sizeof(dic[0]), compare);
    for(i = 0; i<dicnum; i++){
        printf("%s\n", dic[i]);
    }
	return 0;
}

