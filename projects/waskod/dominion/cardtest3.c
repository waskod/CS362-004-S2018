// Unit test for card 4: Great Hall
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv)	
{
	printf("\n=============== Begin Testing Adventurer Card ===================\n");
	struct gameState myGameState;
	int testResult;

	myGameState.numActions = 0;
	myGameState.handCount[0] = 1;
	myGameState.hand[0][0] = great_hall;
	
	testResult = cardEffect(great_hall, 0, 0, 0, &myGameState, 0, 0);
	printf("Expected hand count: 1\n");
	printf("Actual hand count: %d", myGameState.handCount[0]);
	printf("Expected number of actions: 1\n");
	printf("Actual number of actions: %d\n", myGameState.numActions); 
	
	printf("\n=============== End Testing Adventurer Card ===================\n");
	
	return 0;
}