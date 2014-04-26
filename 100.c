#include <stdio.h>


int main(int argc, char* argv[]){

    int i, j,  p, l, maxlen;
    long long k;
#ifndef ONLINE_JUDGE
    freopen("./tests/100.in", "r", stdin);
#endif
    while(scanf("%d%d", &i, &j)>0){
        maxlen = 0;
        for(p=i; p<=j; p++){
            l = 1;
            k = p;
            while(k!=1){
                if(k%2 == 0) k/=2;
                else k= 3*k+1;
                l ++;
            }
            if(l>maxlen)
                maxlen = l;
        }
        printf("%d %d %d\n", i, j, maxlen);
    }
    return 0;
}
