/*
某个城市有个火车站：有N节车厢从A方向驶入车站，按进站顺序编号为1-n。
你的任务是判断是否能让它们按照某种特定的顺序进入B方向的铁轨，并使出车站。

10
5 7 10 9 8 6 4 3 2 1
5 6 4 8 7 3 2 9 1 10
0
0
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;

const int MAXN=1000;
int target[MAXN+10];

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/514.in", "r", stdin);
#endif
	int n;
	stack<int> s;
	
	while(scanf("%d", &n) == 1){		
		if(!n)break;
		while(true){
			memset(target, 0, sizeof(target));
			while(!s.empty())s.pop();
			scanf("%d", &target[0]);
			if(target[0] == 0){
				printf("\n");
				break;
			}
			for(int i=1; i<n; i++){
				scanf("%d", &target[i]);
			}
			int A = 1, B = 0;
			bool ok = true;
			while(B<n){
				if(target[B] == A){
					A++; B++;
				}else if(!s.empty() && s.top() == target[B]){
					B++; s.pop();
				}else if(A<=n) {
					s.push(A++);
				}else {
					ok = false;
					break;
				}
			}
			if(ok)printf("Yes\n");
			else printf("No\n");
		}	
	}
	
	return 0;
}
