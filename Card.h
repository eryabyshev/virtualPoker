#pragma once
#include <iostream>
#include <cstring>
#include <io.h>

#include <fcntl.h>


class Card{
	std::wstring m_name;
	wchar_t m_suit;
	int m_value;
	
public:
	Card(int value, wchar_t suit);
	std::wstring name() const {return m_name;}
	int value() const {return m_value;}
	wchar_t suit() const {return m_suit;}
	void print();

	friend bool operator < (const Card &a, const Card &b);
	friend bool operator <= (const Card &a, const Card &b);

	friend bool operator == (const Card &a, const Card &b);

	friend bool operator >= (const Card &a, const Card &b);
	friend bool operator < (const Card &a, const Card &b);
	
	
};

