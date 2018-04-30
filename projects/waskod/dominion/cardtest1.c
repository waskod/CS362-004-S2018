// Unit test for Card 1: Smithy
#include "myassert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main (int argc, char** argv) 
{
	printf("\n=============== Begin Testing Smithy Card ===================\n");
	struct gameState myGameState;

	myGameState.numActions = 1;
	myGameState.whoseTurn = 0;
	
	myGameState.handCount[0] = 1;
	myGameState.hand[0][0] = smithy;
	
	myGameState.discardCount[0] = 0;
	myGameState.deckCount[0] = 3;
	
	int i;
	for(i=0; i<3 i++)
		myGameState.deck[0][i] = province;  

	playCard(0,0,0,0,&myGameState);
	
	printf("Expected Hand Count: 3\n");
	printf("Actual Hand Count: %d\n", myGameState.handCount[0]);

	printf("Expected Deck Count: 3\n");
	printf("Actual Deck Count: %d\n", myGameState.deckCount[0]);
	
	printf("Expected cards: province, province, province\n");
	
	for(i=0; i<3; i++)
	{
		if(myGameState.hand[0][0] == province)
			printf("Hand at %d: province\n", i);
		else
			printf("Hand at %d: not province\n", i);
	}

	printf("Expected Deck Count: 0\n");
	printf("Actual Deck Count: %d\n", myGameState.numActions);
	
	printf("\n=============== End Testing Smithy Card ===================\n");

  return 0;
}
