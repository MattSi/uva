#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    int n;
#ifndef ONLINE_JUDGE
    FILE *fp = NULL;
    fp = freopen("./tests/264.in", "r", stdin);
    fp = freopen("./tests/264.out", "w", stdout);
#endif
    while(scanf("%d", &n) != EOF){
        int k = (int)floor((sqrt(8.0*n+1) -1) /2 -1e-9 )+ 1;
        int s = k*(k+1)/2;
        if(k % 2 == 0){
            printf("TERM %d IS %d/%d\n",n,  n-s+k, s-n+1);
        }
        else
            printf("TERM %d IS %d/%d\n",n,  s-n+1,n-s+k);
    }
	return 0;
}
