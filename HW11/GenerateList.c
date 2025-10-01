#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include "node.h"

// In ASCII, capital letters are #65-90 and lowercase are #97-122
char get_character(int n) {    
    char random_char;

    int capital_decider = rand(); 
    if (capital_decider % 2 == 1) {
        random_char = (n % 26) + 65; 
    }
    else {
        random_char = (n % 26) + 97;
    }

    return random_char;
}

void GenerateList(node** head, const int num_nodes) {
    node* temp; srand(time(NULL));

    for (int i=0; i<num_nodes; i++) {
        temp = (node*)malloc(sizeof(node));
        temp->value = get_character(rand()); temp->position = 0;
        printf("%c",temp->value);

        if (*head == NULL) {
            *head = temp;
            (*head)->next = NULL;
        }
        else {
            temp->next = *head;
            *head = temp;
        }
    }

    printf("\n");

    node* ptr = *head; int pos = 1;
    while(ptr!=NULL) {
        ptr->position = pos;
        pos = pos + 1;
        ptr = ptr->next;
    }
}