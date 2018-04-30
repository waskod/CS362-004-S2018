// Unit test for card 2: Adventurer
#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main (int argc, char** argv) 
{
	printf("\n=============== Begin Testing Adventurer Card ===================\n");
	struct gameState myGameState;
	int choice1 = 0, choice2 = 0, choice3 = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2, k, 4, &myGameState);
	if(cardEffect(adventurer, choice1, choice2, choice3, &G, 0, NULL) == 0)
		printf("Adventurer card behaved correctly\n");
	else
		printf("Adventurer card did not behave correctly\n");
  	printf("\n=============== End Testing Adventurer Card ===================\n");

}