#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256
char **words;
int *position; /* replace index */
int rulenumber; /* number of rules*/
void init(){
    int i;
    words = (char**)malloc(N * sizeof(char*));
    position = (int*)malloc(N * sizeof(int));
    for(i=0; i<N; i++)
        words[i] = (char*)malloc(N * sizeof(char));
    rulenumber = 0;    
}
void clean(){
    int i;
    for(i=0; i<N; i++)
        free(words[i]);
    free(words);
    free(position);
}

void replace(char word[]){
    int i;
    char tmp[N], *p, *pws;
    for(i=0; i<rulenumber; i++){
        pws = words[i];
        while((p=strstr(word,words[i])) != NULL){
            memset(tmp, 0, N);
            strncpy(tmp, word, p-word);
            strcat(tmp, words[i]+ position[i]);
            strcat(tmp, p+strlen(words[i]));
            strcpy(word, tmp);
        }
    }    
    printf("%s\n", word);
}

int main(int argc, char *argv[]){
    int i, count;
    char word[N], *p, *nouse;
#ifndef ONLINE_JUDGE
    FILE *fp = NULL;
    fp = freopen("./tests/10115.in", "r", stdin);
    fp = freopen("./tests/10115.out", "w", stdout);
#endif    
    init();
    while(scanf("%d\n", &count) != EOF){
        if(count == 0)break;
        rulenumber = 0;
        for(i=0; i<count; i++){
            nouse = fgets(word, N, stdin);
            if(word[strlen(word) - 1] == '\n')word[strlen(word) - 1] = '\0';
            strcpy(words[i], word);
            position[i] = strlen(word) + 1;
            nouse = fgets(word, N,stdin);
            if(word[strlen(word) - 1] == '\n')word[strlen(word) - 1] = '\0';
            p = words[i] + position[i];
            strcpy(p, word);
            rulenumber++;
        }
        nouse = fgets(word, N, stdin);
        if(word[strlen(word) - 1] == '\n')word[strlen(word) - 1] = '\0';
        replace(word);
    }
    clean();   
    return 0;
}
