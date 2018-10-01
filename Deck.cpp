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

	while(!cardFile.eof())
	{
		getline(cardFile, line);
		names.push_back(line);
	}

	std::random_shuffle(names.begin(), names.end());
//	std::cout<<"postshuffle"<<std::endl;
	int count(0);
//	std::cout<<"preloop"<<std::endl;

	cards[0][0].setName(names[count]);
//	std::cout<<"first in array"<<cards[0][0].name<<std::endl;

	for(int i=0; i<COLS; i++)
	{
//		std::cout<<"outerloop"<<std::endl;
		for(int j=0; j<ROWS; j++)
		{
//			std::cout<<"innerloop"<<std::endl;
			cards[i][j].setName(names[count]);
//			std::cout<<"after inner"<<std::endl;
			count++;
		}
	}
//	std::cout<<"postloop"<<std::endl;
	cardFile.close();
}

void Deck::print()
{
	for(int i=0; i<ROWS; i++)
	{
		for(int j=0; j<COLS; j++)
		{
			if(cards[i][j].matched)
			{std::cout<<"[	O	]";}
			else if(!cards[i][j].faceUp)
			{std::cout<<"[	X	]";}
			else
			{std::cout<<cards[i][j].name<<"\t";}
		}
		std::cout<<std::endl;
	}
}
