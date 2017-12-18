#include "Deck.h"
#include <cstring>

class Combination{
	float m_coeffcientOfWin;
	std::string m_name;
	std::vector<Card> m_combination;
	int m_prioritet;

	void analysis();

	void setCof(float cof) {this->m_coeffcientOfWin = cof;}
	void setPrioritet(int prioritet) {this->m_prioritet = prioritet;}
	void setName(std::string name){this->m_name = m_name;}
	


public:
	Combination();
	Combination(const std::vector<Card> &combination);
	Combination(const Combination &from);

	float coffcient() const {return this->m_coeffcientOfWin;}
	std::string name() const {return this->m_name;}
	int prioritet() const {return this->m_prioritet;}

	friend bool operator < (const Combination &a, const Combination &b);
	friend bool operator <= (const Combination &a, const Combination &b);

	friend bool operator == (const Combination &a, const Combination &b);

	friend bool operator >= (const Combination &a, const Combination &b);
	friend bool operator > (const Combination &a, const Combination &b);

	Combination& operator = (const Combination &from);
};