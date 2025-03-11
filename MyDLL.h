#ifndef MYDLL_H
#define MYDLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct Node {
    uint16_t key;
    unsigned char *number;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    size_t max_elements;
    size_t element_size;
    size_t count;
} DLL;

void MyDLLInit(DLL *list, size_t max_elements, size_t element_size);
int MyDLLInsert();
int MyDLLRemove();
unsigned char *MyDLLFind();
unsigned char *MyDLLFindNext();
unsigned char *MyDLLFindPrevious();

#endif