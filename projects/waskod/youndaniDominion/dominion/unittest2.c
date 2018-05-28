// Unit test 2 for dominion.c function: buyCard
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
	printf("\n=============== Begin Testing Buy Card===================\n");
	struct gameState myGameState;
	int testResult;
	
	
	printf("----- Testing Plenty of Coins -----\n");
	myGameState.coins = 10;
	myGameState.numBuys = 2;
	testResult = buyCard(2, &myGameState);
		
		printf("Starting Coins: 10\n");
		printf("Expected Remaining Coins: 8\n");
		printf("Actual Remaining Coins: %d\n", myGameState.coins);
		
		printf("Starting BuyCount: 2\n");
		printf("Expected Remaining BuyCount: 1\n");
		printf("Actual Remaining BuyCount: %d\n", myGameState.numBuys);
		
		printf("Should purchase be accepted? YES\n");
		
		if(testResult == 0)
			printf("Accepted\n");
		else
			printf("Denied\n");
		
	
	printf("----- Testing too few coins -----\n");
	
	myGameState.coins = 0;
	myGameState.numBuys = 2;
 	testResult = buyCard(2, &myGameState);
	
	printf("Starting Coins: 0\n");
	printf("Expected Remaining Coins: 0\n");
	printf("Actual Remaining Coins: %d\n", myGameState.coins);
		
	printf("Starting BuyCount: 2\n");
	printf("Expected Remaining BuyCount: 1\n");
	printf("Actual Remaining BuyCount: %d\n", myGameState.numBuys);
		
	printf("Should purchase be accepted? NO\n");
		
	if(testResult == 0)
		printf("Accepted\n");
	else
		printf("Denied\n");
				
		
 	printf("----- Testing exact amount -----\n");
	
	myGameState.coins = 2;
	myGameState.numBuys = 2;
 	testResult = buyCard(2, &myGameState);
	
	printf("Starting Coins: 2\n");
	printf("Expected Remaining Coins: 0\n");
	printf("Actual Remaining Coins: %d\n", myGameState.coins);
		
	printf("Starting BuyCount: 2\n");
	printf("Expected Remaining BuyCount: 1\n");
	printf("Actual Remaining BuyCount: %d\n", myGameState.numBuys);
		
	printf("Should purchase be accepted? YES\n");
		
	if(testResult == 0)
		printf("Accepted\n");
	else
		printf("Denied\n");
				
		
		
	printf("----- Testing insufficient buy ammount, enough coins -----\n");
	
	myGameState.coins = 10;
	myGameState.numBuys = 0;
 	testResult = buyCard(2, &myGameState);
	
	printf("Starting Coins: 10\n");
	printf("Expected Remaining Coins: 10\n");
	printf("Actual Remaining Coins: %d\n", myGameState.coins);
		
	printf("Starting BuyCount: 0\n");
	printf("Expected Remaining BuyCount: 0\n");
	printf("Actual Remaining BuyCount: %d\n", myGameState.numBuys);
		
	printf("Should purchase be accepted? NO\n");
		
	if(testResult == 0)
		printf("Accepted\n");
	else
		printf("Denied\n");

	printf("----- Testing insufficient buy ammount, insufficient coins -----\n");
	
	myGameState.coins = 0;
	myGameState.numBuys = 0;
 	testResult = buyCard(2, &myGameState);
	
	printf("Starting Coins: 0\n");
	printf("Expected Remaining Coins: 0\n");
	printf("Actual Remaining Coins: %d\n", myGameState.coins);
		
	printf("Starting BuyCount: 0\n");
	printf("Expected Remaining BuyCount: 0\n");
	printf("Actual Remaining BuyCount: %d\n", myGameState.numBuys);
		
	printf("Should purchase be accepted? NO\n");
		
	if(testResult == 0)
		printf("Accepted\n");
	else
		printf("Denied\n");
		
	printf("\n=============== End Testing Buy Card===================\n");
	
 	return 0;	
}