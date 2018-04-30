// Unit test 4 for dominion.c function: 
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
	printf("\n=============== Begin Test Whose Turn ===================\n");
    struct gameState myGameState;
    int testResult;
	int cards[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
	
	printf("Expected Result: 3 rounds of turns\n");
	
	int i;
    for (i = 1 ; i < 4 ; i++)
	{
        testResult = initializeGame(2, cards, 5, &myGameState);
        testResult = whoseTurn(&myGameState);
        assert(testResult == G.whoseTurn);
		printf("round: %d\n", i);
	}
	printf("\n=============== End Test Whose Turn ===================\n");

	return 0;
}