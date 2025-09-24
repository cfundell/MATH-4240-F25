#include <stdio.h>
#include <math.h>
#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time()

int main() {
    srand(time(NULL));

    int run_count = 0;
    int wins = 0;
    int losses = 0;
    while (run_count < 100) {
        // Where is prize?
 
        int prize = rand()%3; // 
        int notprize1 = (prize + 1)%3;
        int notprize2 = (prize + 2)%3;

        // Ask for door
        printf("\nTime to play the Monty Hall Game!\n");
        int pick = -1;
        while(pick<0 || pick >2) {
            printf("Pick a door (0, 1, or 2): ");
            pick = rand()%3;
        }

        printf("\n You entered: %d\n", pick);

        // Other door
        int other;
        int other_other;
        printf("\n Hm ...\n\n");

        if (pick == prize) {
            int ss = rand()%2;
            if (ss==0) {
                other = notprize1;
                other_other = notprize2;
            }
            else {
                other = notprize2;
                other_other = notprize1;
            }
        }
        else {
            other_other = prize;
            if (pick == notprize1) {
                other = notprize2;
            }
            else {
                other = notprize1;
            }
        }

        printf("With great certainty, I can assure you that the prize is not behind door: %i\n", other);

        // Want to change?
        int change = -1;
        while (change !=0 && change !=1) {
            printf("\n To keep your original choice, Door %i, press 0. To switch to Door %i, press 1: ", pick, other_other);
            change = 1;
        }

        int final_pick; 
        if (change == 0) {
            final_pick = pick;
            printf("\n You chose to keep your original choice, Door %i\n", final_pick);
        }
        else {
            final_pick = other_other;
            printf("\n You chose to switch doors, to Door %i\n", final_pick);
        }

        // Check final answer
        if (final_pick == prize) { 
            printf("\n CONGRATS. You picked the right door!\n\n");
            wins = wins + 1;
        }
        else {
            printf("\n TOO BAD. You chose the wrong door! It was behind %i\n\n", prize);
            losses = losses + 1;
        }

        run_count = run_count + 1;
    }

    run_count = run_count;
    printf("\nMonty Hall Simulator ran %i times, always switching to the other door. Won %i times and lost %i games.\n\n", run_count, wins, losses);

    return 0;
}