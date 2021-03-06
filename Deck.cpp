//Deck class definition

#include "Deck.h"

Deck::Deck()
{}

void Deck::addCards(std::string fileName)
{
	//Read card names off file given in main driver into a vector
	//The vector is shuffled and copied into a 2D array of Cards
	//This ensures a different grid each time

	std::vector<std::string> names;
	std::ifstream cardFile;
	std::string line;
	int count(0);

	cardFile.open(fileName);
	if(cardFile.fail())
	{ 
		std::cerr<<"Could not open file!\n";
		exit(1);
	}

	while(!cardFile.eof())
	{
		getline(cardFile, line);
		if(line!=""&&line!="\n"&&line!="\t"&&line!=" ")
		{ names.push_back(line); }
	}
	
	std::srand(std::time(0));
	std::random_shuffle(names.begin(), names.end());

	cards[0][0].setName(names[count]);
	for(int i=0; i<COLS; i++)
	{
		for(int j=0; j<ROWS; j++)
		{
			cards[i][j].setName(names[count]);
			count++;
		}
	}
	cardFile.close();
}

void Deck::print()
{
	//Creates the main display of the 'board'
	//Cards are hidden unless specifically flipped by player

	for(int i=0; i<ROWS; i++)
	{
		for(int j=0; j<COLS; j++)
		{
			if(cards[i][j].matched)
			{std::cout<<"[   OOO   ]";}
			else if(!cards[i][j].faceUp)
			{std::cout<<"[    X    ]";}
			else
			{std::cout<<cards[i][j].name<<"\t";}
		}
		std::cout<<std::endl;
	}
}
