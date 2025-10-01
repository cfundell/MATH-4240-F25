#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include "node.h"

void Print(const int forward, const node* head) {
    if (head==NULL) {
        printf(" The list is empty.\n\n"); return;
    }
    printf("\n");
    printf(" *************************************************\n");
    printf(" *                                               *\n");
    printf(" *   POS:    VAL:    ADDRESS:        NEXT:       *\n");
    printf(" *                                               *\n");
    printf(" *************************************************\n");
    PrintList(head);
    printf(" *************************************************\n");
}

void PrintLine(const int pos, char val, const node* head, const node* next) {
    printf("*   %3i     %c     %15p        %15p        *\n", pos, val, head, next);
}

void PrintList(const node* head) {
    PrintLine(head->position, head->value, head, head->next);
    if (head->next == NULL) {
        return;
    }
    PrintList(head->next);
}