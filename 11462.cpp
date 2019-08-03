/*
UVa:11462

年龄排序：给定一个国家的人口的年龄，1<=age<100, 按照从小到大的顺序排列
*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int SIZE=102;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11462.in", "r", stdin);
#endif
    int cases, age[SIZE], a;
    while(scanf("%d", &cases)==1 && cases!=0){
        memset(age, 0, sizeof(int)*SIZE);
        for(int i=1; i<=cases; i++){
            scanf("%d", &a);
            age[a]++;
        }
        bool first = true;
        for(int i=1; i<=100; i++){
            if(age[i]==0)continue;
            for(int j=1; j<=age[i]; j++){
                if(first){printf("%d", i); first=false;}
                else printf(" %d", i);
            }
        }
        printf("\n");
    }
	return 0;
}
