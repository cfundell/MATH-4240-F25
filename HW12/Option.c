#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int QueryOption() {
    int option;
    printf("ENTER CHOICE: ");
    scanf("%i", &option);
    return option;
}

void ExecuteOption(const int option, node** top) {
    int value;
    switch(option) {
        case 0: // dispaly possible operations
            DisplayOptions();
            break;
        case 1: // enter new value and push new node to stack
            printf("Enter integer value: ");
            scanf("%i", &value);
            Push(value, top);
            break;
        case 2: // pop value from top of stack
            if (*top!=NULL) {
                Pop(top,&value);
                printf("Popped value: %i\n", value);
            }
            else {
                printf("Stack is empty, no value to pop.");
            }
        case 3: // peek at top value
            if((*top)!=NULL) {
                value = Peek(*top);
                printf("Top value is %i\n", value);
            }
            else {
                printf("Stack is empty, no value to fetch.");
            }
            break;
        case 4: // display whole stack
            DisplayStack(*top);
            break;
        case 5: // print stack size
            GetStackSize(*top,&value);
            printf("Stack size is %i\n",value);
            break;
        default:
            printf("Error! Given option is unavailable. Please try again.\n");
            break;
    }
}