#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
/*
3n+1 问题，
如果n是偶数，则减半
如果n是奇数，则n=3n+1
对于给定的n， 从n开始到n=1这个序列的长度，被称为循环节长度。
给定两个整数，a，b，求出a到b最长的循环节。

坑
1）计算过程中，n的中间值可能很大，必须用长整型long long
2）可以用填表法，加速计算过程。
*/
#define N 1000001
int *ansArray;

int cycle(int i){
	int ans = 1;
	long long n;
	if(ansArray[i] != 0){
		return ansArray[i];
	}
	n = i;
	while(n != 1){
		if(n % 2 == 0){
			n = n/ 2;
		}else{
			n = n*3 + 1;
		}
		ans++;
	}
	ansArray[i] = ans;
	return ans;
}

int main(int argc, char* argv[]){

    int i, j,  p, ans, maxlen;
    int ii, jj;
#ifndef ONLINE_JUDGE
    freopen("./tests/100.in", "r", stdin);
#endif
	ansArray = (int *)calloc(N, sizeof(int));	
    while(scanf("%d%d", &ii, &jj)>0){
        maxlen = 1;
        i = MIN(ii,jj);
        j = MAX(ii,jj);
        for(p=i; p<=j; p++){
			ans = cycle(p);
			if(ans>maxlen){
				maxlen = ans;
			}
        }
        printf("%d %d %d\n", ii, jj, maxlen);
    }
    return 0;
}
