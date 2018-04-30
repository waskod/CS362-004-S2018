// Unit test 3 for dominion.c function: isGameOver
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char** argv)
{
	printf("\n=============== Begin Testing is Game Over ===================\n");
	
	struct gameState myGameState;
	int cards[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };
	int foo = initializeGame(2, cards, 3, &myGameState);
	int testResult = isGameOver(&myGameState);
	printf("Expected result: game is not over\n");
	if(testResult == 0)
		printf("Actual Result: game is not over");
	else
		printf("Actual Result: game is over";

	printf("\n=============== End Testing is Game Over ===================\n");
	return 0;
} 
