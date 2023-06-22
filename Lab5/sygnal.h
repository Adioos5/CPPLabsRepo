#pragma once

#include <iostream>

using namespace std;

class wykres;

class sygnal
{
private:
	int ilosc_probek;
	int* probki;

public:
	int* get_probki() { return probki; }

	//Do uzupełnienia
	sygnal(int = 0, int* = nullptr);
	sygnal(const sygnal&);
	~sygnal();

	friend ostream& operator<<(ostream&, const sygnal&);
	friend sygnal operator+(const sygnal&, const sygnal&);
	
	friend class wykres;
};