#include <stdio.h>
#include <string.h>

#define N 150

int xx[N];
int yy[N];
int pos;
int neg;
int main(int argc, char* argv[]){
    int n, i, j, x, y, k;
    int res, flag;
#ifndef ONLINE_JUDGE
    freopen("./tests/10167.in", "r", stdin);
#endif
    while(1){
        scanf("%d", &n);
        if(n==0)break;
        for(i=0; i<2*n; i++){
            scanf("%d%d", &xx[i], &yy[i]);
        }
        for(i=-500; i<=500; i++){ /* Ax + By = 0, i is A, j is B */
            flag = 0;
            for(j=-500; j<=500; j++){
                if(i==0 && j==0)continue;
                pos = 0;
                neg = 0;
                for(k=0; k<2*n; k++){
                    res = i*xx[k] + j*yy[k];
                    if(res > 0)pos++;
                    else if(res < 0)neg++;
                    else break;
                }
                if(k == 2*n && neg ==n && pos == n){
                    flag = 1;
                    printf("%d %d\n", i, j);
                    break;
                }
            }
            if(flag)
                break;
        }

    }
    return 0;
}
