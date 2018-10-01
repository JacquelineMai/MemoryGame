#include "Deck.h"
#include "Card.h"
#include <iostream>

void playGame(Deck deck);


int main()
{
//	int count=36;
	Deck deck;
	deck.addCards("cards.txt");
//	deck.print();
	
	playGame(deck);


	return(0);
}

void playGame(Deck deck)
{

	int count =0;
	std::string next;
	int firstPos1, firstPos2, secPos1, secPos2;
	std::cout<<"Welcome to Memory! Are you ready to make the matches of a lifetime?\n";
	while(count!=36)
	{
		deck.print();
		std::cout<<"\n Enter the coordinates of two cards you would like to flip.\n Use the format \"[x,y][x,y]\". Do not add any extra spaces or characters.\n";
		std::cin>>next;

		firstPos1=next[1]-48-1;
//		std::cout<<firstPos1<<std::endl;
		firstPos2=next[3]-48-1;
//		std::cout<<firstPos2<<std::endl;
//		std::cout<<next[6]<<" "<<next[8]<<std::endl;
		secPos1=next[6]-48-1;
//		std::cout<<secPos1<<std::endl;
		secPos2=next[8]-48-1;
//		std::cout<<secPos2<<std::endl;

		deck.cards[firstPos1][firstPos2].faceUp=true;
		deck.cards[secPos1][secPos2].faceUp=true;
		deck.print();
		if(deck.cards[firstPos1][firstPos2].name == deck.cards[secPos1][secPos2].name)
		{
			count+=2;
			std::cout<<"A match made in heaven! You have "<<count/2<<" points!\n\n";
			deck.cards[firstPos1][firstPos2].matched = true;
			deck.cards[secPos1][secPos2].matched = true;
		}
		else
		{
			std::cout<<"Sorry, no match this time.\n\n";
			deck.cards[firstPos1][firstPos2].faceUp=false;
			deck.cards[secPos1][secPos2].faceUp = false;
		}

//		count = 0;
			
	}
}
