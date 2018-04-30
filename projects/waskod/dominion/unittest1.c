// Unit test 1 for dominion.c function: updateCoins
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
	struct gameState myGameState;
	myGameState.coins = 0;
	
	printf("\n=============== Begin Testing Update Coins ===================\n");
	
	printf("\n----- Testing Hand of All Copper -----\n");
	for(i=0; i < 10; i++)
	{
		myGameState.hand[0][i] = copper;
	}
	
	updateCoins(0,&myGameState, 0);
	
	printf("\nExpecting 10 Copper Coins\n");
	printf("Actual Ammount: %d\n", myGameState.coins);
	
	if(myGameState.coins == 10)
		printf("Copper Test: Passed\n");
	else
		printf("Copper Test: Passed\n");
	
	printf("\n----- Testing Hand of All Silver -----\n");
	for(i=0; i < 10; i++)
	{
		myGameState.hand[0][i] = silver;
	}
	
	updateCoins(0,&myGameState, 0);
	
	printf("\nExpecting 10 Silver Coins\n");
	printf("Actual Ammount: %d\n", myGameState.coins);
	
	if(myGameState.coins == 10)
		printf("Silver Test: Passed\n");
	else
		printf("Silver Test: Passed\n");
	
	printf("\n----- Testing Hand of All Gold -----\n");
	for(i=0; i < 10; i++)
	{
		myGameState.hand[0][i] = gold;
	}
	
	updateCoins(0,&myGameState, 0);
	
	printf("\nExpecting 10 Gold Coins\n");
	printf("Actual Ammount: %d\n", myGameState.coins);
	
	if(myGameState.coins == 10)
		printf("Gold Test: Passed\n");
	else
		printf("Gold Test: Passed\n");
	
	printf("\n----- Testing Hand of No Coins -----\n");
	int i;
	for(i=0; i < 10; i++)
	{
		myGameState.hand[0][i] = smithy;
	}

	updateCoins(0,&myGameState, 0);
	
	printf("\nExpecting 0 Coins\n");
	printf("Actual Ammount: %d\n", myGameState.coins);
	
	if(myGameState.coins == 0)
		printf("None Test: Passed\n");
	else
		printf("None Test: Passed\n");
	
	printf("\n=============== End Testing Update Coins ===================\n");

	return 0;
}