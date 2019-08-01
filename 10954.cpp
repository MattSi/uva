/*
UVa:10954
给一列数，相加，要求相加的代价最小。（每次相加的和记为代价）


input
3
1 2 3
4
1 2 3 4
0
output
9
19

*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10954.in", "r", stdin);
#endif
	int n, v, cost;
	while(scanf("%d", &n)==1 && n!=0){
		pq = priority_queue<int, vector<int>, greater<int> >();
		cost = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &v);
			pq.push(v);
		}
		while(pq.size()>=2){
			int a = pq.top();pq.pop();
			int b = pq.top();pq.pop();
			
			cost+= (a+b);
			pq.push(a+b);
		}
		printf("%d\n", cost);
	}
	return 0;
}
