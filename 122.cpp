/*
输入一颗二叉树，你的任务是从上到下，从左到右的顺序输出各节点的值。
每个节点都按照根节点到它的移动顺序给出（L表示左，R表示右）。
在输入中，每个节点的左括号和右括号之间没有空格，相邻节点之间用一个空格隔开。
每棵树的输入用一对空括号()结束。这对括号本身不代表节点。



(11,LL) (7,LLL) (8,R)(5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
(3,L) (4,R) ()

5 4 8 11 13 4 7 2 1
not complete
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;

struct Node{
	int val;
	struct Node* left;
	struct Node* right;
};
const int SIZE=1024;
char buff[SIZE];
bool isDup = false;
bool isHole = false;
Node *root = NULL;

void init_root(){
	root = (Node*)malloc(sizeof(Node));
	root->val = -1;
	root->left = NULL;
	root->right = NULL;
	isDup = false;
	isHole = false;
}

void read_node(char* buff){
	if(isDup) return;
	int val;
	char s[256];
	Node *r;
	sscanf(buff+1, "%d,%s", &val, s);
	r = root;
	for(int i=0; s[i]!=')'; i++){
		if(s[i] == 'L'){
			if(!r->left){
				r->left = (Node*)malloc(sizeof(Node));
				r->left->val = -1;
				r->left->left = NULL;
				r->left->right = NULL;
			}
			r = r->left;
		}else{
			if(!r->right){
				r->right = (Node*)malloc(sizeof(Node));
				r->right->val = -1;
				r->right->left = NULL;
				r->right->right = NULL;
			}
			r = r->right;
		}
	}
	if(r->val >=0) isDup = true;
	else r->val = val;
	return;
}

void dfs(Node *root){
	if(!root)return;
	if(root->val < 0){
		isHole = true;
		return;
	}
	dfs(root->left);
	dfs(root->right);
}
void do_travel(){
	if(isHole || isDup) { printf("not complete\n"); return;}
	queue<Node*> q;
	Node *r = root;
	printf("%d", r->val);
	if(r->left!=NULL) q.push(r->left);
	if(r->right!=NULL) q.push(r->right);
	while(!q.empty()){
		Node *p = q.front();
		printf(" %d", p->val);
		if(p->left!=NULL) q.push(p->left);
		if(p->right!=NULL) q.push(p->right);
		q.pop();
	}
	printf("\n");
}

void clean_tree(Node *root){
	if(root==NULL) return;
	clean_tree(root->left);
	clean_tree(root->right);
	free(root);	
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/122.in", "r", stdin);
#endif

	init_root();
	while(scanf("%s", buff)!=EOF){
		if(strcmp(buff,"()") == 0){
			dfs(root);
			do_travel();
			clean_tree(root);
			init_root();
		}else{
			read_node(buff);
		}
	}
	return 0;
}
