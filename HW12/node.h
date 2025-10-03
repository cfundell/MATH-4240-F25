#include <stdio.h>
#include <stdlib.h>
#ifndef __NODE_H__
#define __NODE_H__

typedef struct node node;
struct node
{
    int position; 
    char value;
    node* next;
};

void DeleteStack(node** top);
void DisplayOptions();
void PrintNode(node* top);
void DisplayStack(node* top);
void GetStackSize(node* top, int* stack_size);
int QueryOption();
void ExecuteOption(const int option, node** top);
char Peek(node* top);
void Pop(node** top, int* output);
void Push(const char input, node** top);

#endif