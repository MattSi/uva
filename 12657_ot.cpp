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

程序是正确的：但超时
原因：
1. 大量Malloc操作
2. 反转操作不应该执行。

*/

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

struct Node{
	int val;
	struct Node *prev;
	struct Node *next;
};
Node *first_head = (Node*)malloc(sizeof(Node));
long long ans;
int n, m;

void init_list(int n){
	Node *curr = first_head;
	for(int i=0; i<n; i++){
		Node *p = (Node*)malloc(sizeof(Node));
		p->val = i+1;
		p->prev = curr;
		p->next = first_head;
		curr->next = p;
		curr = p;
		first_head->prev = p;
	}
}
void clear_list(){

}
Node* find_node(int v){
	Node *p = first_head->next;
	while(p!=first_head){
		if(p->val == v) return p;
		p = p->next;
	}
	return NULL;
}

void print_result(int case_num){
	Node *p = first_head->next;
	int odd = 1;
	while(p!=first_head){
		if(odd){
			odd = 0;
			ans += p->val;
		}else odd=1;
		p = p->next;
	}
	printf("Case %d: %lld\n", case_num, ans);
}
void do_op(){
	int op, x, y, tv;
	Node *nx, *ny;
	for(int i=0; i<m; i++){
		scanf("%d", &op);
		switch(op){
		case 1:
			scanf("%d%d", &x, &y);
			nx = find_node(x);
			ny = find_node(y);
			if(nx->next == ny) continue;// x在y的左边，啥也不用做
			nx->prev->next = nx->next;
			nx->next->prev = nx->prev;

			nx->prev = ny->prev;
			nx->next = ny;
			ny->prev->next = nx;
			ny->prev = nx;

			break;
		case 2:
			scanf("%d%d", &x, &y);
			nx = find_node(x);
			ny = find_node(y);
			if(nx->prev == ny) continue;// x在y的右边，啥也不用做
			nx->prev->next = nx->next;
			nx->next->prev = nx->prev;

			nx->prev = ny;
			nx->next = ny->next;
			ny->next->prev = nx;
			ny->next = nx;

			break;
		case 3:
			scanf("%d%d", &x, &y);
			nx = find_node(x);
			ny = find_node(y);
			tv = nx->val;
			nx->val = ny->val;
			ny->val = tv;
			break;
		default: 
			Node *h = first_head->next;
			Node *t = first_head->prev;
			while(true){
				if(h==t) break;
				if(h->prev == t && t->next==h) break;
				tv = h->val;
				h->val = t->val;
				t->val = tv;
				h = h->next;
				t = t->prev;
			}
			break;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/12657.in", "r", stdin);
#endif
	int cases=0;
	while(scanf("%d%d", &n, &m) != EOF){
		first_head->prev = first_head->next = NULL;
		ans = 0;
		init_list(n);
		do_op();
		print_result(++cases);
		clear_list();		
	}
	return 0;
}
