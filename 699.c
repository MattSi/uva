#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXN 1024
int heap[MAXN];
int left, right;
typedef struct _node{
	int value;
	struct _node *left;
	struct _node *right;
}Node;

Node *build(){
	int value;
	Node *node;
	scanf("%d", &value);
	if(value == -1) return NULL;
	node = (Node*)calloc(1, sizeof(Node));
	node->value = value;
	node->left = build();
	node->right = build();
	return node;
}

void init(){
	memset(heap, 0, sizeof(heap));
	left = right = MAXN / 2;
}

void trav(Node *root){
	if(!root)return;
	
	trav(root->left);
	printf("%3d", root->value);
	trav(root->right);
}

void heaping(Node *root, int p){
	if(!root) return;
	heap[p] += root->value;
	if(p<left) left = p;
	if(p>right) right = p;
	heaping(root->left, p-1);
	heaping(root->right, p+1);
}

int main(int argc, char* argv[]){
	Node *root;
	int i, index=1;
#ifndef ONLINE_JUDGE
	freopen("./tests/699.in", "r", stdin);
#endif
	while(1){
		root = build();
		if(!root) break;
		init();
		heaping(root, MAXN/2);
		
		printf("Case %d:\n", index++);
		for(i=left; i<=right; i++){
			printf("%d", heap[i]);
			if(i<right) printf(" ");
		}
		
		printf("\n\n");
	}
	return 0;
}
