#pragma once
//#include <iostream>
//using std::ostream;
#include "samolot.h"


class Lotnisko
{
private:
	const int id_lotniska;
	static int max_id_lotniska;

	int ilosc_samolotow;

	static const int MAX_ILOSC_SAMOLOTOW = 5;
	Samolot *samoloty[MAX_ILOSC_SAMOLOTOW];

public:
	Lotnisko();

	bool operator+=(Samolot &);
	bool zezwol_na_start(Samolot &);
	void przekieruj(Samolot &, const char*) const;

	void naprawa(Samolot &s);

};