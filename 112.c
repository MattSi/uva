#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    int type;
    struct _node *p;
    struct _node *l;
    struct _node *r;
}Node;

void build_tree(Node *node){

}
int main(int argc, char* argv[]){
#ifndef ONLINE_JUDGE
    freopen("./tests/112.in", "r", stdin);
#endif
    Node* node = (Node*)calloc(1, sizeof(Node));
    return 0;
}
