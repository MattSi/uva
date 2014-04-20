#include <stdio.h>
#include <string.h>

#define MAX 99999
int map[10];

int cal_numbers(int n);

int main(int argc, char *argv[]){

    int n;
    int flag = 0;
    char *nomsg = "There are no solutions for %d.\n";
#ifndef ONLINE_JUDGE
    freopen("./tests/725.in", "r", stdin);
#endif
    while(1){
        scanf("%d", &n);
        if(n==0)break;
        if(flag)printf("\n");
        if(!cal_numbers(n)){
            printf(nomsg, n);
        }
        flag = 1;
        
    }

    return 0;
}

int chknumber(int n){
    /*
     * 1. check item in number
     * 2. check identity in number
     *
     * */
    int bits, i;
    int flag = 1;
    memset(map, 0, sizeof(map));
    bits = (n/10000 == 0)? 4:5;
    if(bits==4) map[0] = 1;

    while(n>0){
        i = n - (n/10)*10;
        n /= 10;
        if(map[i]){
            flag = 0;
        }
        else{
            map[i] = 1;
        }
    }
    return flag;
}
int chknumber2(int n){
    int bits, i;
    bits = (n/10000 == 0)?4:5;
    if(bits == 4 && map[0] == 1)
        return 0;
    while(n>0){
        i = n - (n/10)*10;
        n /= 10;
        if(map[i])
            return 0;
        else
            map[i] =1;
    }
    return 1;
}
int cal_numbers(int n){
    int i = 1234;
    int prod;
    int flag = 0;
    for(; i<MAX; i++){
        if(chknumber(i)){
            prod = n * i;
            if(prod > 99999)
                continue;
            else{
                if(chknumber2(prod)){
                    printf("%05d / %05d = %d\n", prod, i, n);
                    flag = 1;
                }
            }
        }
    }
    return flag;
}
