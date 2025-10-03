#include <stdio.h>
#include "node.h"

void PrintNode(node* top) {
    printf("* %3i           %c      %15p       %15p      *\n", top->position, top->value, top, top->next);
    if (top->next == NULL) {
        return;
    }
    PrintNode(top->next);
}

void DisplayStack(node* top) {
    if (top==NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("*********************************************************************\n");
    printf("*   Pos:         Val:           Address:           Next:            *\n");
    printf("*********************************************************************\n");
    PrintNode(top);
    printf("*********************************************************************\n");
}

