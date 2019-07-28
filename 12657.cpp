/*
你有一行盒子，从左到右依次编号为1，2，3，。。。， n。
可以执行以下4种操作

1 X Y： 表示把盒子X移动到盒子Y的左边（如果X已经在Y的左边，则忽略该操作）
2 X Y： 表示把盒子X移动到盒子Y的右边（如果X已经在Y的右边，则忽略该操作）
3 X Y： 将X和Y交换位置
4 表示反转整条链。

指令保证合法：X!=Y
输入包含不超过10组数据，每组数据第一行为盒子个数n和指令条数m (1<=n, m<=100000)
每组数据输出一行：所有奇数位置的盒子编号之和。位置从左到右编号为1-n

*/

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

const int SIZE = 100005;
int nleft[SIZE];
int nright[SIZE];

void init(int n) {
	for (int i = 1; i <= n; i++) {
		nleft[i] = i - 1;
		nright[i] = (i + 1) % (n + 1);
	}
	nright[0] = 1;
	nleft[0] = n;
}


//将x移动到y的左边
void move_left(int n, int x, int y) {
	if (nright[x] == y) return;
	int lx = nleft[x], rx = nright[x], ly = nleft[y], ry = nright[y];

	nright[lx] = rx;
	nleft[rx] = lx;


	nright[ly] = x;
	nleft[x] = ly;

	nright[x] = y;
	nleft[y] = x;
}

//将x移动到y的右边
void move_right(int n, int x, int y) {
	if (nright[y] == x) return;
	int lx = nleft[x], rx = nright[x], ly = nleft[y], ry = nright[y];

	nright[lx] = rx;
	nleft[rx] = lx;

	nright[y] = x;
	nleft[x] = y;

	nright[x] = ry;
	nleft[ry] = x;
	
}

void swap_node(int x, int y) {
	int lx = nleft[x], rx = nright[x], ly = nleft[y], ry = nright[y];

	if (lx == y) { //Y在X的左边
		nright[ly] = x;  nleft[x] = ly;
		nright[x] = y;   nleft[y] = x;
		nright[y] = rx;  nleft[rx] = y;
		return;
	}
	if (rx == y) { //Y在X的右边
		nright[lx] = y; nleft[y] = lx;
		nright[y] = x;  nleft[x] = y;
		nright[x] = ry; nleft[ry] = x;
		return;
	}

	nright[lx] = y;
	nleft[ry] = x;
	nleft[x] = ly;
	nright[x] = ry;
	nleft[y] = lx;
	nright[y] = rx;
	nleft[rx] = y;
	nright[ly] = x;
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	FILE* fp = freopen("./tests/12657.in", "r", stdin);
#endif
	int cases = 0, n, m, odd, p;
	long long ans;
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(nleft, 0, sizeof(nleft));
		memset(nright, 0, sizeof(nright));
		init(n);
		int op, x, y, inv = 0;
		while (m--) {
			scanf("%d", &op);
			if (op == 4) inv = !inv;
			else {
				scanf("%d%d", &x, &y);
				if (op == 3) { swap(x, y); }
				else {
					if (op != 3 && inv) op = 3 - op;
					if (op == 1) move_left(n, x, y);
					else move_right(n, x, y);
				}
			}
		}
		ans = 0, p = 0;
		for (int i = 1; i <= n; i ++) {
			p = nright[p];
			if (i % 2 == 1) ans += p;
		}
		if (n % 2 == 0 && inv) ans = (long long)n * (n + 1) / 2 - ans;
		printf("Case %d: %lld\n", ++cases, ans);
	}
	return 0;
}
