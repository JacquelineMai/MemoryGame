#include "Deck.h"
#include "Card.h"
#include <iostream>

int main()
{
	Deck deck;
	deck.addCards("cards.txt");
	deck.print();
	return(0);
}
