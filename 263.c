#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAIN_NUMBER 1000
void get2numbers(int number, int* max, int* min);
int ischaindistinct(int *chain, int len, int value);
int main(int argc, char* argv[])
{
#ifndef ONLINE_JUDGE
    FILE *fp  = freopen("./tests/263.in", "r", stdin);
    FILE *fp2 = freopen("./tests/263.out","w", stdout);
#endif
    int number, chainlength, sub, max, min, i;
    int *chain = (int*)calloc(sizeof(int), CHAIN_NUMBER);
    while(scanf("%d\n", &number)){
        if(!number)break;
        printf("Original number was %d\n", number);
        chainlength=0, sub=-1;
        memset(chain, 0, sizeof(int) * CHAIN_NUMBER);
        while(1){
            get2numbers(number, &max, &min);
            sub = max - min;
            printf("%d - %d = %d\n", max, min, sub);

            if(chainlength <= CHAIN_NUMBER && ischaindistinct(chain, chainlength, sub)){
                chain[chainlength++] = sub;
            }
            else{
                printf("Chain length %d\n\n", chainlength+1);
                break;
            }
            number = sub;
        }
    }
    return 0;
}

int ischaindistinct(int *chain, int len, int value){
    int i;
    for(i=0; i<len; i++){
        if(chain[i] == value)return 0;
    }
    return 1;
}
int compare(const void* arg1, const void* arg2){
    return *(char*)arg1 - *(char*)arg2;
}

void get2numbers(int number, int* max, int* min){
    #define BUFF_LEN 64
    char buff[BUFF_LEN], buff2[BUFF_LEN];
    int count[10]={0};
    int buflen, i, j=0, k=0;
    snprintf((char*)buff, (unsigned int)BUFF_LEN, "%d", number);
    buflen = strlen(buff);
    /* Using counting sort instead of quick sort */
    for(i=0; i<buflen; i++){
        count[buff[i] - '0']++;
    }
    for(i=0; i<10; i++){
        if(count[i] > 0)
            for(k=0; k<count[i]; k++)
                buff[j++]= i+ '0';
    }
    buff2[buflen]='\0';
    for(i=0; i<buflen; i++)
        buff2[i] = buff[buflen-1-i];
    *max = atoi(buff2);
    *min = atoi(buff);

}
