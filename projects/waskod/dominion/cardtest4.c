// Unit test for card 4: village
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) 
{
	printf("\n=============== Begin Testing Village Card ===================\n");
	struct gameState myGameState;

	myGameState.whoseTurn = 0;
	myGameState.numActions = 1;
	myGameState.handCount[0] = 1;
	
	myGameState.hand[0][0] = village;
	
	myGameState.discardCount[0] = 0;
	myGameState.deckCount[0] = 1;
	myGameState.deck[0][0] = province;


	playCard(0,0,0,0, &myGameState);

	printf("Expected actions: 2\n");
	printf("Actual actions: %d\n", myGameState.numActions);
	
	printf("Expected deck count: 0\n");
	printf("Actual deck count: %d\n", myGameState.deckCount[0]);
	
	printf("Expected hand count: 1\n");
	printf("Actual hand count: %d\n", myGameState.handCount[0]);
	
	printf("Expected hand card: province\n");
	if(myGameState.hand[0][0] == province)
		printf("Hand card is province\n");
	else
		printf("Hand card is not province\n");
	
	printf("\n=============== End Testing Village Card ===================\n");

  return 0;
}