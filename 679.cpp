/*
UVa:679
有棵二叉树，最大深度为D，且所有叶子的深度都相同。所有节点从上到下，从左到右编号为1，2，3，。。。，2^D-1，在节点1出放入一个小球，它会往下落。
每个内节点上都有一个开关，初始全部关闭，每次小球落在开关上，状态都会改变。当小球到达一个内节点时，如果该节点上的开关关闭，则往左，否则往右。
直到走到叶子节点。
一些小球从节点1出开始下落，最后一个小球将会落在哪里呢？
输入叶子深度D和小球个数I。

输出第I个小球最后所在的叶子编号。假设I不超过整棵树的叶子个数。D<=20, 输入最多包含1000组数据。
样例输入：
4 2
3 4
10 1
2 2
8 128
16 12345

样例输出：
12
7
512
3
255
36358

*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxd = 20;
int s[1<<maxd];


int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/679.in", "r", stdin);
#endif
	int cases, D, I;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d%d", &D, &I);
		int k = 1;
		for(int i=0; i<D-1; i++){
			if(I%2){k *=2; I = (I+1)/2;}
			else{k =k*2 +1; I/=2;}
		}
		printf("%d\n", k);
	}

	
	return 0;
}
