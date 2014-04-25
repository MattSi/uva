#include <stdio.h>

#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
int main(int argc, char* argv[]){

    int i, j,  p, l, maxlen;
    int ii, jj;
    long long k;
#ifndef ONLINE_JUDGE
    freopen("./tests/100.in", "r", stdin);
#endif
    while(scanf("%d%d", &ii, &jj)>0){
        maxlen = 1;
        i = MIN(ii,jj);
        j = MAX(ii,jj);
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
        printf("%d %d %d\n", ii, jj, maxlen);
    }
    return 0;
}
