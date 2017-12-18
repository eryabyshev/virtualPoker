
#include "Deck.h"
#include "Combination.h"
#include <string>
#include <cstdlib>

#include <io.h>
#include <fcntl.h>



float checkInput(std::string input);
void winPrint();
void losePrint();
void virualPokerPrint();

int main(){

	_setmode(_fileno(stdout), _O_U16TEXT);
	
	float const BET = 10;
	virualPokerPrint();
	system("pause");
	system("cls");

	std::string inputBank;
	std::wcout << "Enter your bank : ";
	std::getline(std::cin, inputBank);
	//input check
	float bank;
	while (true){
		bank = checkInput(inputBank);
		if(bank < BET && bank != -1)
			std::wcout <<"Bank is below the min bet\t min bet: " << BET << "$\nTry again: ";
		if (bank != -1 && bank >= BET)
			break;
		std::getline(std::cin, inputBank);
	}
	
	std::wcout << "\n\n\n";
	//create new deck
	Deck deck;

	while(true){
		//start the game
		std::wcout << "Your bank: " << bank << " $\n";
		std::wcout << "Bet: " << BET << " $\n";
		system("pause");
		system("cls");
		
		float bet = BET;
		bank -= bet;
		//creat of a combination and analysis it
		Combination comb(deck.flop());
		bet *= comb.coffcient();
		if(comb.prioritet() == 0)
			losePrint();
		else{
			std::wcout << "\n" << comb.name().c_str() << "\n";
			winPrint();
		}
		bank +=bet;
		bet = BET;
		system("pause");
		system("cls");
		if(bank <= 0 || BET > bank){
			std::wcout << "You don't have money! Bay!\n";
				break;
		}
		if(deck.empty()){
			deck.newDeck();
			std::wcout << "Warning!Open new deck!\n";
			system("pause");
		}
		
	}
}
	

float checkInput(std::string input){
	if(input == "")
		return -1;
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			std::wcout << "Input error! Try again input!\n";
			return -1;
		}
		return (float)atoi(input.c_str());
	}
}

void virualPokerPrint(){
	std::wcout << "$   $  $  $$$$ $$$$$  $  $    $     $\n" ;   
	std::wcout << "$   $  $  $  $   $    $  $   $ $    $\n";
	std::wcout << "$   &  $  $$$$   $    $  $  $   $   $\n";
 	std::wcout << "$   $  $  $$     $    $  $  $$$$$   $\n";
	std::wcout << " $ $   $  $ $    $    $  $  $   $   $\n";
	std::wcout << "  $    $  $  $   $    $$$$  $   $   $$$$$\n\n\n";

	std::wcout << "  $$$$  $$$$$  $  $  $$$$$  $$$$\n";
	std::wcout << "  $  $  $   $  $ $   $      $  $\n";
	std::wcout << "  $$$$  $   $  $$    $$$    $$$$\n";
 	std::wcout << "  $     $   $  $$    $      $$\n";
	std::wcout << "  $     $   $  $ $   $      $ $\n";
	std::wcout << "  $     $$$$$  $  $  $$$$   $  $\n\n\n";
}


void winPrint(){
	std::wcout << "\n\n\n";
	std::wcout << "$   $  $$$$$  $   $      $    $    $   $   $$  $\n";
	std::wcout << "$   $  $   $  $   $      $    $    $   $   $ $ $\n";
	std::wcout << " $ $   $   $  $   $      $    $    $   $   $ $ $\n";
 	std::wcout << "  $    $   $  $   $      $    $    $   $   $ $ $\n";
	std::wcout << "  $    $   $  $   $      $   $ $  $    $   $  $$\n";
	std::wcout << "  $    $$$$$  $$$$$        $     $     $   $  $$\n";
}



void losePrint(){
	std::wcout << "\n\n\n";
	std::wcout << "$   $  $$$$$  $   $      $       $$$$$   $$$$$   $$$$$\n";
	std::wcout << "$   $  $   $  $   $      $       $   $   $       $\n";
	std::wcout << " $ $   $   $  $   $      $       $   $   $$$$$   $$$$$\n";
 	std::wcout << "  $    $   $  $   $      $       $   $       $   $\n";
	std::wcout << "  $    $   $  $   $      $       $   $       $   $\n";
	std::wcout << "  $    $$$$$  $$$$$      $$$$$   $$$$$   $$$$$   $$$$$\n";
}