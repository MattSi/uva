/*
如果X加上X的各个数字之和得到Y，就说X是Y的生成元。
给出n（1<=n<=100000）求最小生成元。
无解则输出0

例如n=216，121，2005的解分别为198，0，1979
*/
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE = 100200;
int tar[SIZE];

void solve(){
	//求解100005个数字的生成元.
	for(int i=1; i<SIZE; i++){
		tar[i] = i;
		int tmp = i;
		while(tmp !=0){
			tar[i] += tmp%10;
			tmp /=10;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/1583.in", "r", stdin);
#endif
	int cases, t;
	bool is_fixed;
	solve();
	scanf("%d", &cases);
	while(cases--){
		scanf("%d", &t);
		is_fixed = false;
		for(int i=0; i<SIZE; i++){
			if(tar[i] == t){
				printf("%d\n", i);
				is_fixed = true;
				break;
			}
		}
		if(!is_fixed){
			printf("0\n");
		}
	}
	return 0;
}
