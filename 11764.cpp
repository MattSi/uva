/*
UVa:11764,Jumping Mario
Mario跳墙，跳高墙记一次高跳，跳矮墙记一次矮跳。统计多少次高跳，多少次矮跳

*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int SIZE=128;
int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11764.in", "r", stdin);
#endif
	int cases,n,z=0;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d", &n);
		int h = 0, l=0, curr, prev;
		scanf("%d", &prev);
		for(int i=2; i<=n; i++){
			scanf("%d", &curr);
			if(curr > prev) h++;
			else if(curr < prev)l++;

			prev = curr;
		}
		printf("Case %d: %d %d\n", ++z, h, l);
	}
	return 0;
}
