#pragma once
#include <iostream>


class kredyt 
{
protected:
	double wartosc;	//wartosc kredytu
	double oproc;	//w procentach - rocznie, np. 9%, 12%
	int ile_lat;
	int ile_rat_rok;
	
	const char* info;  // dodatkowa informacja o kredycie, opis

public:
	kredyt() : wartosc(0), oproc(0), ile_lat(0), ile_rat_rok(0), info("") { }
	kredyt( double wartosc, double oproc, int ile_lat, int ile_rat_rok, const char* info="xxxxxxxxxx");

	//kredyt(const kredyt& k);				//zdefiniuj, je¿eli uwa¿asz ¿e jest potrzebne
	//kredyt& operator = (const kredyt& k);	//zdefiniuj, je¿eli uwa¿asz ¿e jest potrzebne
	virtual ~kredyt();						//zdefiniuj, je¿eli uwa¿asz ¿e jest potrzebne

	double rata() const;

	virtual void wypisz(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const kredyt& os);
	friend bool cmp_wartosc(const kredyt& k1, const kredyt& k2);
	friend bool cmp_wartosc_info(const kredyt& k1, const kredyt& k2);

};