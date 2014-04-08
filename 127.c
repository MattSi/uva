#include <stdio.h>

#define CARDS 52

typedef struct _heap{
    int number;
    int stack[CARDS + 1];
}Heap;

Heap heap[CARDS];


