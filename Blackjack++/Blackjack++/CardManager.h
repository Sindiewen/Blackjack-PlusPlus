//
//  CardManager.h
//  Blackjack++
//
//  Created by Rachel Vancleave on 1/19/17.
//  Copyright © 2017 Rachel Vancleave. All rights reserved.
//

#ifndef CardManager_h
#define CardManager_h

#include "DeckDefinitions.h"

using namespace std;

// Manages the cards used in this game
class cardManager
{
public:
	// Public Class Function
	
	// Class Constructor
	cardManager();	// Runs when the class gets called
	
	int drawCard();
	
private:
	// Private Class Variables
	
	// Random value generator
	int randomValue;		// Stores random number for pulling from the deck
	int cardToRetrieve;		// Gets the card to retrieve from the deck array
	
	// Deck of Cards
	int deck[deckMax] = {card1, card2, card3, card4, card5, card6, card7, card8, card9, cardJ, cardK, cardQ};		// Stores the deck of cards
	
	
	
	// Private class Functions
	int randomNumber();
};

// Class Implementation //

cardManager::cardManager()
{
	// Seeds a random number every second
	srand(static_cast<int>(time(0)));
}


int cardManager::drawCard()
{
	// Get randomly seeded number
	bool cardGet = false;
	
	int cardToDraw = 0;
	int drawnCard  = 0;
	
	while (!cardGet)
	{
		// Stores the random number to draw from
		cardToDraw = randomNumber();
		
		// If the current deck location is not 0
		if (deck[cardToDraw] != 0)
		{
			
			cout << cardToDraw << endl;
			
			// Sets the drawn card to the card to draw from the deck
			drawnCard = deck[cardToDraw];
			
			// zero's out the location in the deck
			deck[cardToDraw] = 0;
			
			// Card has been drawn
			cardGet = true;
		}
	}
	
	// Returns the drawn card
	return drawnCard;
}











// Private Class Function Implementation


// Seeds random number
int cardManager::randomNumber()
{
	// Gets random value
	randomValue = rand();
	
	// Gets random number between 0 and the deck max value
	cardToRetrieve = (randomValue % deckMax);
	
	// Returns random value
	return cardToRetrieve;
}

#endif /* CardManager_h */
