#include "Deck.h"
#include "Card.h"
#include <iostream>

void playGame(Deck deck);


int main()
{
	Deck deck;
	deck.addCards("cards.txt");	
	playGame(deck);

	return(0);
}

void playGame(Deck deck)
{
	//Runs the game- the player is presented with the board until all matches are made
	//Flipping and comparing cards are simple tasks, so opted not to separate into smaller functions

	int count =0, points=0;
	std::string next;
	int firstPos1, firstPos2, secPos1, secPos2;
	std::cout<<"Welcome to Memory! Are you ready to make the matches of a lifetime?\n";
	while(count!=36)
	{
		deck.print();
		std::cout<<"\n Enter the coordinates of two cards you would like to flip.\n Use the format \"[x,y][x,y]\". Do not add any extra spaces or characters.\n";
		std::cin>>next;

		firstPos1=next[1]-48-1;
		firstPos2=next[3]-48-1;
		secPos1=next[6]-48-1;
		secPos2=next[8]-48-1;

	//Make sure player chooses cards on the board
		if(firstPos1>5||firstPos1<0||firstPos2>5||firstPos2<0||secPos1>5||secPos1<0||secPos2>5||secPos2<0)
		{ std::cout<<"Invalid position! Try again!\n\n";}

		else
		{
		deck.cards[firstPos1][firstPos2].faceUp=true;
		deck.cards[secPos1][secPos2].faceUp=true;
		deck.print();
		if(deck.cards[firstPos1][firstPos2].name == deck.cards[secPos1][secPos2].name)
		{
			count+=2;
			points+=5;
			std::cout<<"A match made in heaven! You have "<<points<<" points!\n\n\n\n\n";
			deck.cards[firstPos1][firstPos2].matched = true;
			//When cards are marked as matched, they will only display [  O  ], even if the player selects that card again
			deck.cards[secPos1][secPos2].matched = true;
		}
		else
		{
			points-=1;
			std::cout<<"Sorry, no match this time.\n\n\n\n\n";
			deck.cards[firstPos1][firstPos2].faceUp=false;
			deck.cards[secPos1][secPos2].faceUp = false;
		}
			
		}
	}

	if(count==36)
	{
		std::cout<<"Congratulations, you won! You have "<<points<<" points! Buy yourself something nice.\n"; 
	}
}
