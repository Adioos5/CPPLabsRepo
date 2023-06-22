#pragma once
#include <iostream> 
#include <string>
using namespace std;
#include "Postac.h"

class Zaklecie;
class Przedmiot;

class Mag : public Postac
{
protected:
	static const int ilosc_zaklec = 6;
	Zaklecie* zaklecia[ilosc_zaklec];

	int wielkosc_ekwipunku = 4;
	Przedmiot** ekwipunek;

public:
	Mag(string imie, int punktyZycia, int zrecznosc, int sila, int poziom);
	Mag(const Mag& z) = delete; 
	Mag& operator= (const Mag& z) = delete;
	virtual ~Mag();

	int czy_dostepne_ofensywne() const;
	int czy_dostepne_defensywne() const;

	void przygotowanie();
	int wykonaj_atak(int poziom_ochrony_przeciwnika) override;

	virtual void info(ostream&) const override;
};

