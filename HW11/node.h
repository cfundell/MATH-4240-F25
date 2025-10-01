#include <stdio.h>
#include <stdlib.h>
#ifndef __NODE_H__
#define __NODE_H__

typedef struct node node;
struct node
{
    int position; 
    int value;
    node* next;
};

void GenerateList(node** head, const int num);
void Print(const int forward, const node* head);
int GetKey();
void SearchList(const node* head, const int key);

#endif