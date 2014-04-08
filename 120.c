#include <stdio.h>
#include <stdlib.h>
 
#define BUFF_SIZE 8192
int comp(const void *arg1, const void *arg2){
    return *(int*)arg2 - *(int*)arg1;
}

void rev(int orig[], int p, int ps){
    int i,j,tmp;
    for(i=p,j=ps; i<=j; i++,j--){
        tmp = orig[i];
        orig[i] = orig[j];
        orig[j] = tmp;
    }
}
void process(int orig[], int sorted[], int len){
    int i,j,p,ps;
    for(i=0;i<len;i++){
        printf("%d", orig[i]);
        sorted[i]=orig[i];
        if(i != len-1)printf(" ");
    }
    printf("\n");
    qsort(sorted, len, sizeof(sorted[0]), comp);
    for(i=0; i<len; i++){
        ps = len - 1 - i;
        for(j=0; j<len; j++){
            if(orig[j] == sorted[i]){
                p = j;
                break;
            }
        }
        if(p == ps) continue;
        if(p == 0){
            rev(orig, p,ps);  printf("%d ", len - ps);
        }else{
            rev(orig, 0, p);  printf("%d ", len - p);
            rev(orig, 0, ps); printf("%d ", len - ps);
        }
    }
    printf("0\n");
}

int main(int argc, char* argv[]){

#ifndef ONLINE_JUDGE
    FILE *fp = freopen("./tests/120.in", "r", stdin);
#endif
    int orig[BUFF_SIZE], sorted[BUFF_SIZE];
    int c, len=0;
    while((c = getchar())){
        if( c == '\n'){
            if(!len) continue;
            process(orig, sorted, len);
            len=0;
        }else if(c == EOF){
            if(len != 0)process(orig, sorted, len);
            break;                        
        }else{
            ungetc(c, stdin);
            scanf("%d", &orig[len++]);
        }
    }    
    return 0;
}






















