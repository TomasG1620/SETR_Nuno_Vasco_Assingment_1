#ifndef MYDLL_H
#define MYDLL_H

#include <stdint.h>


void MyDLLInit();
int MyDLLInsert();
int MyDLLRemove();
unsigned char *MyDLLFind();
unsigned char *MyDLLFindNext();
unsigned char *MyDLLFindPrevious();