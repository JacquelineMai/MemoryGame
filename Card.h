#ifndef CARD_H
#define CARD_H

#include <string>

class Card{
	public:
		Card();
		std::string name;
		bool faceUp;
		bool matched;
		void setName(std::string name);
};

#endif
