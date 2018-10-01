#include "Deck.h"

Deck::Deck()
{
//	cards = new Card[12][12]
}

void Deck::addCards(std::string fileName)
{
	
//	int next1, next2;
	std::vector<std::string> names;

	std::ifstream cardFile;
	std::string line;

	cardFile.open(fileName);
	if(cardFile.fail())
	{ 
		std::cerr<<"Could not open file!\n";
		exit(1);
	}
	std::random_shuffle(names.begin(), names.end());

	int count(0);
	for(int i=0; i<ROWS; i++)
	{
		for(int j=0; j<COLS; j++)
		{
			cards[i][j].setName(names[count]);
			count++;
		}
	}
	cardFile.close();
}

void Deck::print()
{
	for(int i=0; i<ROWS; i++)
	{
		for(int j=0; j<COLS; j++)
		{
			if(!cards[i][j].faceUp)
			{std::cout<<"[	X	]";}
			else
			{std::cout<<cards[i][j].name<<"\t";}
		}
		std::cout<<std::endl;
	}
}
