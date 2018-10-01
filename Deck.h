#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Card.h"
class Deck
{
	static const int ROWS=6;
	static const int COLS=6;
	Card cards[ROWS][COLS];
	
	public:
	Deck();
	void addCards(std::string fileName);
	void print();
};

#endif
