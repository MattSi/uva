#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LEN 8192
typedef struct _node{
    char type;
    int nextchild;
    struct _node *c1;
    struct _node *c2;
    struct _node *c3;
    struct _node *c4;
}Node;

Node* stack[LEN];
int pt = 0;
void push(Node* node){
    stack[pt++] = node;
}
Node* top(){
    return stack[pt-1];
}
void pop(){
    if(pt>0)
        pt--;
}
int isempty(){
    return (pt==0)?1:0;
}

Node* build_tree(char *buff){
    char *p = buff;
    Node *node, *tmp;
    /* init stack */
    memset(stack, 0, sizeof(stack));
    pt = 0;
    while(*p){
        if(*p == 'p'){
            node = (Node*)calloc(1, sizeof(Node));
            node->type = 'p';
            node->nextchild = 0;
            if(!isempty()){

            }
            push(node);
            p++;
        }else if (*p == 'e' || *p == 'f'){
        }
    }
    return NULL;
}

int main(int argc, char* argv[]){
    return 0;
}
