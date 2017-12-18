#include "Deck.h"



Deck::Deck(){
	
	this->newDeck();

}

void Deck::print(){
	for(int i = 0; i < this->cards; i++){
		this->deck[i].print();
		std::cout << std::endl;
	}
}

void Deck::newDeck(){

	deck.clear();
	this->cards = 54;
	
	for (int i = 2; i <= 14; i++)
		deck.push_back(Card(i, L'\u2665'));//heart 

	for (int i = 2; i <= 14; i++)
		deck.push_back(Card(i, L'\u2666'));//diamond 

	for (int i = 2; i <= 14; i++)
		deck.push_back(Card(i, L'\u2663')); //club

	for (int i = 2; i <= 14; i++)
		deck.push_back(Card(i, L'\u2660')); //spade

	//add Joker
	deck.push_back(Card( 15, 0));
	deck.push_back(Card( 15, 0));
	this->shuffle();
}


void Deck::shuffle(){
	srand(unsigned(time(0)));
	for (int i = 0; i < this->cards; i++) {
		int newPosition = rand() % this->cards;
		std::swap(this->deck[i], this->deck[newPosition]);
	}
}

void Deck::printFlop(std::vector<Card> flop){
	std::wcout << " _____   _____   _____   _____   _____\n";
	std::wcout << "|     | |     | |     | |     | |     |\n";
	std::wcout << "|     | |     | |     | |     | |     |\n";
	std::wcout << "|" << flop[0].name().c_str() << "| |" << flop[1].name().c_str() << "| |" << flop[2].name().c_str() << "| |"  << flop[3].name().c_str() << "| |" << flop[4].name().c_str() << "|\n";
	std::wcout << "|     | |     | |     | |     | |     |\n";
	std::wcout << "|_____| |_____| |_____| |_____| |_____|\n";
}
	

std::vector<Card> Deck::flop(){
	int quantityOfCardsOnFloap = 5;
	std::vector<Card>cardFlop;
	for(int i = 0; i < quantityOfCardsOnFloap; i++){
		cardFlop.push_back(this->deck.back());
		this->deck.pop_back();
	}
	this->printFlop(cardFlop);
	this->cards = this->deck.size();
	return cardFlop;
}
	

Card& Deck::operator [](int position){
	if(position >= 0 && position < this->count())
		return this->deck[position];
	std::cerr << "Error operator []\n";
	return deck[0];
}




		


