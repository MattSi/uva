/*
UVa:536 二叉树给定前序，中序遍历
求后续遍历


*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int SIZE=30;

struct Node{
	char v;
	struct Node *left;
	struct Node *right;
};

Node* build_tree(char *preod, int s1, int f1, char *inord, int s2, int f2){
	Node *root;
	int mid=0, step=0;
	if(s1>f1) return NULL;
	
	root = (Node*)malloc(sizeof(struct Node));
	root->v = preod[s1];
	root->left = NULL;
	root->right = NULL;
	for(int i= s2; i<=f2; i++){
		if(root->v == inord[i]){
			mid = i;
			break;
		}
	}
	step = mid-s2;
	root->right = build_tree(preod, s1+1+step, f1, inord, mid+1, f2);
	root->left = build_tree(preod, s1+1, s1+step, inord, s2, mid-1);
	return root;
}

void post_travel(Node *tree){
	if(tree==NULL)return;
	post_travel(tree->left);
	post_travel(tree->right);
	printf("%c", tree->v);
}
int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/536.in", "r", stdin);
#endif
	char preord[SIZE], inord[SIZE];

	while(scanf("%s%s", preord, inord)==2){
		size_t pre_len = strlen(preord);
		size_t in_len  = strlen(inord);
		Node *tree = build_tree(preord, 0, pre_len-1, inord, 0, in_len-1);
		post_travel(tree);
		printf("\n");
	}


	return 0;
}

