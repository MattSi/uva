/*
有N个大理石，每个大理石上写了一个非负整数。首先，要把大理石从小到大排序， 然后回答Q个问题。
每个问题是问：是否有一个大理石上写着某个整数x，如果是，还要回答哪一块大理石上写着x。

本题着重练习STL中的排序和查找。
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10000;
int main(int argc, char **argv){
	int a[maxn], n, q, i, x;
	int kase = 0;

#ifndef ONLINE_JUDGE
	FILE *fp = NULL;
	fp = freopen("./tests/10474.in", "r", stdin);
#endif
	while(scanf("%d%d", &n, &q) == 2 && n!=0){
		printf("CASE# %d:\n", ++kase);
		for(i=0; i<n; i++) scanf("%d", &a[i]);
		sort(a, a+n);
		for(i=0; i<q; i++){
			scanf("%d", &x);
			int p = lower_bound(a, a+n, x) - a; //lower_bound的作用是查找 “大于或者等于x的第一个位置”, 返回的是一个迭代器iterator
			if(a[p] == x) printf("%d found at %d\n", x, p);
			else printf("%d not found", x);
		}
	}
	return 0;
}
