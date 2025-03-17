#include "MyDLL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    DoublyLinkedList list;
    MyDLLInit(&list, 10, sizeof(int)); // Lista com até 10 elementos

    int data1 = 42, data2 = 84, data3 = 126;
    
    MyDLLInsert(&list, 1, (unsigned char *)&data1);
    MyDLLInsert(&list, 2, (unsigned char *)&data2);
    MyDLLInsert(&list, 3, (unsigned char *)&data3);

    unsigned char *found = MyDLLFind(&list, 1);
    if (found) {
        printf("Elemento encontrado: %d\n", *(int *)found);
    } else {
        printf("Elemento não encontrado\n");
    }

    found = MyDLLFindNext(&list, 1);
    if (found) {
        printf("Elemento encontrado: %d\n", *(int *)found);
    } else {
        printf("Elemento não encontrado\n");
    }

    found = MyDLLFindPrevious(&list, 2);
    if (found) {
        printf("Elemento encontrado: %d\n", *(int *)found);
    } else {
        printf("Elemento não encontrado\n");
    }

    MyDLLRemove(&list, 3);
    found = MyDLLFind(&list, 3);
    if (found) {
        printf("Elemento encontrado: %d\n", *(int *)found);
    } else {
        printf("Elemento não encontrado\n");
    }

    return 0;
}

