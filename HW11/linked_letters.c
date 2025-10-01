#include <stdio.h>
#include <math.h>
#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time()
#include "node.h"

int main() {
    srand(time(NULL)); // Random seed for rand()

    // Declare head node
    node* head = NULL;

    // Set number of nodes and generate list
    const int num_nodes;
    printf("Enter desired number of values: \n");
    scanf("%d", &num_nodes);
    GenerateList(&head,num_nodes);

    // Print to terminal
    Print(1, head);

    // Ask for key and search
    if (num_nodes > 0 ) {
        int key = GetKey();
        SearchList(head,key);
    }

    return 0;
}
