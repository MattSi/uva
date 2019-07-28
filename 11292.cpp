/*
UVa11292:王国里有一条n个头的恶龙，你希望雇佣一些骑士把它杀死。有m个骑士供选择，一个能力值为x的骑士可以杀掉直径不超过x的头，且需要支付x个金币。
如何雇佣骑士才能砍掉恶龙所有的头，且需要支付的金币最少？
注意，一个骑士只能砍一个头，且不能被雇佣2次。

输入：每组第一行为正整数n和m(1<=n,m<=20000)
以下n行为一个整数，即恶龙头的直径，以下m行为一个整数，即每隔骑士的能力。输入结束标志为n=m=0

如果误解，输出: "Loowater is doomed!"
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
const int SIZE = 20000+5;

int dragon[SIZE];
int war[SIZE];

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11292.in", "r", stdin);
#endif
    int n,m;
    while(scanf("%d%d", &n,&m)==2 && m!=0 && n!=0){
        for(int i=0; i<n; i++){
            scanf("%d", &dragon[i]);
        }
        for(int i=0; i<m; i++){
            scanf("%d", &war[i]);
        }
        if(n>m){printf("Loowater is doomed!\n");continue;}
        sort(dragon, dragon+n);
        sort(war, war+m);
        int dm=0, dn=0, ans=0; 

        for(; dm<m; dm++){
            if(war[dm]>=dragon[dn]){
                ans += war[dm];
                if(++dn == n) break;
            }
        }
        if(dn == n)printf("%d\n", ans);
        else printf("Loowater is doomed!\n");
    }

	return 0;
}
