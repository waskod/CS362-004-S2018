#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//Note: segmentation faults may or may not be handled properly by this test

// counters for each type of failure
int drawFailCount = 0;
int effectFailCount = 0;
int handFailCount = 0;
int discardFailCount = 0;

// function for cheking smithy function
void checkSmithyEffect(int player, struct gameState *postEffectState)
{

	// creating a cariable to keep track of the state before we change things
	struct gameState preEffectState;
	memcpy(&preEffectState, postEffectState, sizeof(struct gameState));
	int bonus = 0;

	// get the response from calling the card effect smithy
	int effectRes = cardEffect(smithy, 0, 0, 0, postEffectState, 0, &bonus);

	// draw three cards
	int card1 = drawCard(player, &preEffectState);
	int card2 = drawCard(player, &preEffectState);
	int card3 = drawCard(player, &preEffectState);

	// attempt to discard
	int discardRes = discardCard(0, player, &preEffectState, 0);

	// get values of hand and deck counts
	int postEffectHandCount = postEffectState->handCount[player];
	int postEffectDeckCount = postEffectState->deckCount[player];

	int preEffectHandCount = preEffectState.handCount[player];
	int preEffectDeckCount = preEffectState.deckCount[player];

	// check for values that might indicate a failure
	if (card1 == -1 && preEffectState.deckCount[player] != 0)
	{
		drawFailCount++;
	}
	if (card2 == -1 && preEffectState.deckCount[player] != 0)
	{
		drawFailCount++;
	}
	if (card3 == -1 && preEffectState.deckCount[player] != 0)
	{
		drawFailCount++;
	}
	if (effectRes)
	{
		effectFailCount++;
	}
	if (discardRes)
	{
		discardFailCount++;
	}
	if (!(postEffectHandCount == preEffectHandCount && postEffectDeckCount == preEffectDeckCount))
	{
		handFailCount++;
	}
}

int main()
{

	printf("Begining Test for Smithy:\n");
	srand(time(NULL));

	int player;
	struct gameState myGameState;
	int numIterations = 10000;

	int i, k;
	for (i = 0; i < numIterations; i++)
	{
		for (k = 0; k < sizeof(struct gameState); k++)
			((char *)&myGameState)[k] = floor(Random() * 256);

		player = floor(Random() * MAX_PLAYERS);
		myGameState.deckCount[player] = floor(Random() * MAX_DECK);
		myGameState.discardCount[player] = floor(Random() * MAX_DECK);
		myGameState.handCount[player] = floor(Random() * MAX_HAND);
		myGameState.playedCardCount = floor(Random() * (MAX_DECK - 1));
		myGameState.whoseTurn = player;
		checkSmithyEffect(player, &myGameState);
	}

	int failCount = effectFailCount + discardFailCount + drawFailCount + handFailCount;

	printf("Total Tests: %d\n", numIterations);
	printf("Tests Passed: %d\n", numIterations - failCount);
	printf("Tests Failed: %d\n", failCount);

	if (failCount == 0)
	{
		printf("Passed All Tests!\n\n");
	}
	printf("\n");
	printf("Card Effect Fails: %d\n", effectFailCount);
	printf("Card Draw Fails %d\n", drawFailCount);
	printf("Hand/Deck Count Fails: %d\n", handFailCount);
	printf("Discard Fails: %d\n", discardFailCount);


	printf("\n=================================== Code Coverage ==================================\n\n");
	return 0;
}