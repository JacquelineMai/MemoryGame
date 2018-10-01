#Makefile
#Jacqui Mai

main: main.o Deck.o Card.o
	g++ -std=c++11 -g -o main main.o Deck.o Card.o

Deck.o: Deck.cpp Deck.h
	g++ -std=c++11 -c -g Deck.h Deck.cpp

Card.o: Card.cpp Card.h
	g++ -std=c++11 -c -g Card.h Card.cpp

clean:
	rm -f main *.o *h.gch
