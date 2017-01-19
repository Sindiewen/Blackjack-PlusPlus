//
//  main.cpp
//  Blackjack++
//
//  Created by Rachel Vancleave on 1/18/17.
//  Copyright © 2017 Rachel Vancleave. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "CardManager.h"
#include "DeckDefinitions.h"

using namespace std;

// Game Update Loop
void Update();
void ProcessInput();
void UpdateGame();
void Render();

int main()
{
	
	// Seeds a random number every second
	//srand(static_cast<int>(time(0)));
	
	// Calls the update function
	Update();
	
    return 0;
}

void Update()
{
	// CardManager Object
	cardManager BJDeck;
	
	// Variables
	int currentHand[deckMax];		// Stores the players current hand
	int handIterator = 0;		// Iterates throguh the players hand
	
	
	
	
	
	bool quit = false;			// If the quit action has been initiated

	
	// Initializes empty hand
	for (int i = 0; i < deckMax; i++)
	{
		// Empties the hand
		currentHand[i] = 0;
	}
	
	// While the game is not quitted
	while (!quit)
	{
	
		
		// Prints player their current hand
		cout << "Current Hand: ";
		for (int i = 0; i < deckMax; i++)
		{
			cout << currentHand[i] << " ";
		}
		
		// Tells player basic controls
		cout << "\nh = hit, s = stand\n>";
		
		if (cin.get() == 'h')
		{
			cin.ignore();	// Clears the input buffer
			
			// Stores the currently drawn card to the players hand
			currentHand[handIterator] = BJDeck.drawCard();
			
			// Iterates the hand by 1
			handIterator++;
		}
			
		else if (cin.get() == 'q')
		{
			cout << "Quiting game..." << endl;
			quit = true;
		}
			
			
	}
}



















