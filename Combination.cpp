#include "Combination.h"
#include <cmath>
#include <vector>

Combination::Combination(const std::vector<Card> &combination){
	
	m_combination = combination;
	std::sort(m_combination.begin(), m_combination.end());
	this->analysis();
}

Combination::Combination(){
	this->m_coeffcientOfWin = 0;
	this->m_prioritet = 0;
	this->m_name = "Nop";
}

Combination::Combination(const Combination &from){
	this->m_coeffcientOfWin = from.m_coeffcientOfWin;
	this->m_combination = from.m_combination;
	this->m_name = from.m_name;
	this->m_prioritet = from.m_prioritet;
}


bool pair(std::vector<Card> comb){
	for(int i = 0; i < comb.size() - 1; i++){
		if((comb[i].value() - comb[i + 1].value()) == 0)
			return true;
	}
		return false;		
}

bool twoPairs(std::vector<Card> comb){
	int overlap = 0;
	for(int i = 0;  i < comb.size() - 1; i++){
		if((comb[i].value() - comb[i + 1].value()) == 0)
			overlap++;
	}
	return overlap == 2;			
}

bool three(std::vector<Card> comb){
	for(int i = 0; i < comb.size() - 2; i++){
		if(((comb[i].value() - comb[i + 1].value()) == 0) &&
		(comb[i + 1].value() - comb[i + 2].value()) == 0)
			return true;
	}
		return false;
}


bool straight(std::vector<Card> comb){
	//if loop straight
	bool acoOnLastPositionAndTwoOnFirstPosition = ((comb[comb.size() - 1].value() == 14) && comb[0].value() == 2); 
	bool placeOneAndThree = ((comb[1].value() == 3) && (comb[3].value() == 13));
	 
	if(acoOnLastPositionAndTwoOnFirstPosition && placeOneAndThree && 
		((comb[2].value() == 4) || (comb[2].value() == 12)))
			return true;
	//ordinary case
	int overlap = 0;
	for(int i = comb.size() - 1; i > 0; i--)
		if(comb[i].value() - comb[i - 1].value() == 1)
			overlap++;
	return overlap == 4;
}

bool fullHouse(std::vector<Card> comb){
	// 8 8 8 J J
	int sumOfFirstThreePosition = comb[0].value() + comb[1].value() + comb[2].value();
	int avgOffirstThreePosition = sumOfFirstThreePosition / 3;
	int remanderOfFirstThreePosition = sumOfFirstThreePosition % 3;

	int sumOfLastTwoPosition = comb[3].value() + comb[4].value();
	int avgOfLastTwoPosition = sumOfLastTwoPosition / 2;
	int remanderTwoPosition = sumOfLastTwoPosition % 2;

	if(avgOffirstThreePosition == comb[0].value() && remanderOfFirstThreePosition == 0 &&
		avgOfLastTwoPosition == comb[3].value() && remanderTwoPosition == 0)
		return true;
	// 8 8 J J J
	int sumOfFirstTwoPosition = comb[0].value() + comb[1].value();
	int avgOffirstTwoPosition = sumOfFirstThreePosition / 2;
	int remanderOfTwoPosition = sumOfFirstThreePosition % 2;

	int sumOfLastThreePosition = comb[2].value() + comb[3].value() + comb[4].value();
	int avgOfLastThreePosition = sumOfLastTwoPosition / 3;
	int remanderThreePosition = sumOfLastTwoPosition % 3;

	if(avgOffirstTwoPosition == comb[0].value() && remanderOfTwoPosition == 0 &&
		avgOfLastTwoPosition == comb[2].value() && remanderTwoPosition == 0)
		return true;
	return false;
}

bool four(std::vector<Card> comb){
	// 5 5 5 5 A
	int sumOffirstFourPosition = comb[0].value() + comb[1].value() + comb[2].value() + comb[3].value();
	int avgOffirstFourPosition = sumOffirstFourPosition / 4;
	int remanderOffirstFourPosition = sumOffirstFourPosition % 4;

	if(avgOffirstFourPosition == comb[0].value() && remanderOffirstFourPosition == 0)
		return true;
	// 2 A A A A
	int sumOfLastFourPosition = comb[1].value() + comb[2].value() + comb[3].value() + comb[4].value();
	int avgOfLastFourPosition = sumOfLastFourPosition / 4;
	int remanderOfLastFourPosition = sumOfLastFourPosition % 4;

	if(avgOfLastFourPosition == comb[1].value() && remanderOfLastFourPosition == 0)
		return true;
	return false;
}

bool suit(std::vector<Card> comb){
	int overlap = 0;
	for(int i = 0; i < comb.size() - 1; i++){
		if(comb[i].suit() == comb[i + 1].suit())
			overlap++;
	}
	return overlap == 4;
}

bool straightFlush(std::vector<Card> comb){
	if(straight(comb) && suit(comb))
		return true;
	return false;
}

bool poker(std::vector<Card> comb){
	if(comb[4].value() == 15 && four(comb))
		return true;
	if(comb[4].value() == 15 && comb[3].value() == 15 && three(comb))
		return true;
	return false;
}

bool operator < (const Combination &a, const Combination &b){
	return a.m_prioritet < b.m_prioritet;
}
bool operator <= (const Combination &a, const Combination &b){
	return a.m_prioritet <= b.m_prioritet;
}
bool operator == (const Combination &a, const Combination &b){
	return a.m_combination == b.m_combination;
	
}
bool operator >= (const Combination &a, const Combination &b){
	return a.m_prioritet >= b.m_prioritet;
}
bool operator > (const Combination &a, const Combination &b){
	return a.m_prioritet > b.m_prioritet;
}

Combination& Combination::operator = (const Combination &from){
	if(this == &from)
		return *this;

	this->m_coeffcientOfWin = from.m_coeffcientOfWin;
	this->m_combination = from.m_combination;
	this->m_name = from.m_name;
	this->m_prioritet = from.m_prioritet;
	return *this;
}

Combination ifOneJoker(std::vector<Card> comb){
	std::vector<Card> flopForMod;
	Deck deckForSubstitution;
	Combination best;
	//fill first 4 card
	for(int i = 0; i < comb.size() - 1; i++)
		flopForMod.push_back(comb[i]);

	for(int i = 0; i < deckForSubstitution.count(); i++){
		if(deckForSubstitution[i].value() == 15)
			continue;
		flopForMod.push_back(deckForSubstitution[i]);
		Combination temp(flopForMod);
		if(temp > best)
			best = temp;
		flopForMod.pop_back();
	}
	return best;
}


//work for case with two Jokers
Combination ifTwoJokers(std::vector<Card> comb){
	std::vector<Card> flopForMod;
	Deck deckForSubstitution;
	Combination best;

	//fill first 3 card
	for(int i = 0; i < comb.size() - 2; i++)
		flopForMod.push_back(comb[i]);
	for(int i = 0; i < deckForSubstitution.count(); i++){
		if(deckForSubstitution[i].value() == 15)
			continue;
		//add first card - from deck, second card - JOKER
		flopForMod.push_back(deckForSubstitution[i]);
		flopForMod.push_back(Card(15, 0));
		Combination temp(ifOneJoker(flopForMod));
		if(temp > best)
			best = temp;
		//free last two flop cards
		flopForMod.pop_back(); 
		flopForMod.pop_back();
	}
	return best;
}

void Combination::analysis(){

	//if two Jokers
	if(this->m_combination[4].value() == 15 && this->m_combination[3].value() == 15){
		if(poker(this->m_combination)){
			this->m_coeffcientOfWin = 2;
			this->m_prioritet = 10;
			this->m_name = "Poker";
			return;
		}
		this->m_name = ifTwoJokers(m_combination).name();
		this->m_prioritet = ifTwoJokers(m_combination).prioritet();
		this->m_coeffcientOfWin = ifTwoJokers(m_combination).coffcient();
		return;
	}

	//if one Joker
	else if(this->m_combination[4].value() == 15){
		//if combination - Poker
		if(poker(this->m_combination)){
			this->m_coeffcientOfWin = 2;
			this->m_prioritet = 10;
			this->m_name = "Poker";
			return;
		}
		
		Combination oneJoker;
		oneJoker = ifOneJoker(this->m_combination);
		this->m_name = oneJoker.name();
		this->m_prioritet = oneJoker.prioritet();
		this->m_coeffcientOfWin = oneJoker.coffcient();
		return;
	}
	
	//if ordinary case
	else{
		if(straightFlush(this->m_combination)){
			this->m_coeffcientOfWin = 1.8f;
			this->m_prioritet = 9;
			this->m_name = "Straight Flush";
		}

		else if(suit(this->m_combination)){
			this->m_coeffcientOfWin = 1.7f;
			this->m_prioritet = 8;
			this->m_name = "Suit";
		}

		else if(four(this->m_combination)){
			this->m_coeffcientOfWin = 1.6f;
			this->m_prioritet = 7;
			this->m_name = "Four";
		}
		
		else if(fullHouse(this->m_combination)){
			this->m_coeffcientOfWin = 1.5f;
			this->m_prioritet = 6;
			this->m_name = "Full House";
		}


		else if(straight(this->m_combination)){
			this->m_coeffcientOfWin = 1.4f;
			this->m_prioritet = 5;
			this->m_name = "Straight";
		}

		else if(three(this->m_combination)){
			this->m_coeffcientOfWin = 1.3f;
			this->m_prioritet = 4;
			this->m_name = "Three";
		}
		
		else if(twoPairs(this->m_combination)){
			this->m_coeffcientOfWin = 1.2f;
			this->m_prioritet = 3;
			this->m_name = "Two Pairs";
		}
		else if(pair(this->m_combination)){
			this->m_coeffcientOfWin = 1.1f;
			this->m_prioritet = 2;
			this->m_name = "Pair";
		}
		else{
			this->m_coeffcientOfWin = 0;
			this->m_prioritet = 0;
			this->m_name = "Nop";
		}
	}
	
	
}