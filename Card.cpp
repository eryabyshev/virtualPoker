#include "Card.h"
#include <sstream>


Card::Card(int value, wchar_t suit){
	
	this->m_value = value;
	this->m_suit = suit;

	std::wstringstream out;

	if(this->m_value < 10){
		out <<" "<< m_value << " " << (wchar_t)m_suit << " ";
		this->m_name = out.str();
	}
	else if (this->m_value == 10){
		out <<" "<< m_value << (wchar_t)m_suit << " ";
		this->m_name = out.str();
	}
	else if (this->m_value == 11){
		out <<" J " << (wchar_t)m_suit << " ";
		this->m_name = out.str();
	}
	else if (this->m_value == 12){
		out <<" Q " << (wchar_t)m_suit << " ";
		this->m_name = out.str();
	}
	else if (this->m_value == 13){
		out <<" K " << (wchar_t)m_suit << " ";
		this->m_name = out.str();
	}
	else if (this->m_value == 14){
		out <<" A " << (wchar_t)m_suit << " ";
		this->m_name = out.str();
	}
	else if (this->m_value == 15){
		out <<"Joker";
		this->m_name = out.str();
	}
	else {
		out << "!!!";
		this->m_name = out.str();
	}
}

void Card::print(){

	if(this->m_value == 15)
		std::cout << this->m_name.c_str();
	else
		std::cout <<" " << this->m_name.c_str()<< " " << this->m_suit;
}



bool operator < (const Card &a, const Card &b){
	return a.value() < b.value();
}

bool operator <= (const Card &a, const Card &b){
	return a.value() <= b.value();
}

bool operator == (const Card &a, const Card &b){
	return a.value() == b.value();
}

bool operator >= (const Card &a, const Card &b){
	return a.value() >= b.value();
}

bool operator > (const Card &a, const Card &b){
	return a.value() > b.value();
}






