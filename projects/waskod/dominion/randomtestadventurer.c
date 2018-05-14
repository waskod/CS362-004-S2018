#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

// fail counter variables
int deckFailCount = 0;
int shuffleFailCount = 0;
int treasureFailCount = 0;
int effectFailCount = 0;
int drawFailCount = 0;

// function to check the adventurerCard
void checkAdventurerEffect(int player, struct gameState *postEffect)
{

	// creating a variable to keep track of the state before we change things
	struct gameState preEffect;
	memcpy(&preEffect, postEffect, sizeof(struct gameState));

	int temphand[MAX_HAND];

	int postEffectTreasure = 0;
	int preEffectTreasure = 0;
	int drawntreasure = 0;
	int cardDrawn, card;
	int bonus = 0;
	int shuffleRes, drawRes;
	int i;
	int j = 0;

	int effectRes = cardEffect(adventurer, 0, 0, 0, postEffect, 0, &bonus);
	if (effectRes)
		effectFailCount++;

	while (drawntreasure < 2)
	{
		if (preEffect.deckCount[player] < 1)
		{
			shuffleRes = shuffle(player, &preEffect);
			if (shuffleRes == -1 && preEffect.deckCount[player] >= 1)
				shuffleFailCount++;
		}

		drawRes = drawCard(player, &preEffect);

		if (drawRes == -1 && preEffect.deckCount[player] != 0)
			drawFailCount++;

		cardDrawn = preEffect.hand[player][preEffect.handCount[player] - 1];

		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else
		{
			temphand[j] = cardDrawn;
			preEffect.handCount[player]--;
			j++;
		}
	}

	while (j - 1 >= 0)
	{
		preEffect.discard[player][preEffect.discardCount[player]++] = temphand[j - 1];
		j = j - 1;
	}

	for (i = 0; i < postEffect->handCount[player]; i++)
	{
		card = postEffect->hand[player][i];
		if (card == copper || card == silver || card == gold)
			postEffectTreasure++;
	}

	for (i = 0; i < preEffect.handCount[player]; i++)
	{
		card = preEffect.hand[player][i];
		if (card == copper || card == silver || card == gold)
			preEffectTreasure++;
	}

	if (postEffectTreasure != preEffectTreasure)
		treasureFailCount++;

	int postEffectHandCount = postEffect->handCount[player];
	int postEffectDeckCount = postEffect->deckCount[player];
	int postEffectDiscardCount = postEffect->discardCount[player];

	int preEffectHandCount = preEffect.handCount[player];
	int preEffectDeckCount = preEffect.deckCount[player];
	int preEffectDiscardCount = preEffect.discardCount[player];

	if (!(postEffectHandCount == preEffectHandCount && postEffectDeckCount == preEffectDeckCount && postEffectDiscardCount == preEffectDiscardCount))
		deckFailCount++;
}

int main()
{
	printf("Begining Test for Adventurer:\n");
	srand(time(NULL));

	int treasures[] = {copper, silver, gold};

	int i, k, player;
	struct gameState myGameState;
	int numTreasures;
	int numIterations = 10000;
	int min = 3;

	for (i = 0; i < numIterations; i++)
	{
		for (k = 0; k < sizeof(struct gameState); k++)
			((char *)&myGameState)[k] = floor(Random() * 256);

		player = floor(Random() * MAX_PLAYERS);
		myGameState.deckCount[player] = floor(Random() * ((MAX_DECK - min) + 1) + min);
		numTreasures = floor(Random() * ((myGameState.deckCount[player] - min) + 1) + min);

		for (k = 0; k < numTreasures; k++)
			myGameState.deck[player][k] = treasures[rand() % 3];

		myGameState.discardCount[player] = 0;
		myGameState.handCount[player] = floor(Random() * ((MAX_HAND - min) + 1) + min);
		myGameState.whoseTurn = player;

		checkAdventurerEffect(player, &myGameState);
	}

	int failCount = effectFailCount + drawFailCount + shuffleFailCount + deckFailCount + treasureFailCount;

	printf("Total Tests: %d\n", numIterations);
	printf("Tests Passed: %d\n", numIterations - failCount);
	printf("Tests Failed: %d\n", failCount);

	if (failCount == 0)
		printf("Passed All Tests!\n\n");

	printf("Effect Fails: %d\n", effectFailCount);
	printf("Card Draw fails: %d\n", drawFailCount);
	printf("Shuffle Fails: %d\n", shuffleFailCount);
	printf("Hand/Deck Count Fails: %d\n", deckFailCount);
	printf("Treasure Count Fails: %d\n", treasureFailCount);

	printf("\n=================================== Code Coverage ==================================\n\n");
	return 0;
}