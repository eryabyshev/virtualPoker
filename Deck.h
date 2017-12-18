#pragma once
#include "Card.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

class Deck{
	int cards;
	std::vector<Card> deck;
	void shuffle();
	void printFlop(std::vector<Card> flop);

public:
	
	Deck();
	std::vector<Card>flop();
	void print();
	bool empty() {return this->cards < 5;}
	void newDeck();
	int count() {return deck.size();}
	
	Card& operator [](int position);
};