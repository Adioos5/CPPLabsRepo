#include <iostream> 
using namespace std;
#include "Zaklecie.h"

// klasa Zaklecie

Zaklecie::Zaklecie(string nazwa,  string opis, int poziom_trudnosci) : nazwa(nazwa), opis(opis),  poziom_trudnosci(poziom_trudnosci) {}

void Zaklecie::info(ostream& out) const
{
	out << nazwa << " (" << opis << ", poziom " << poziom_trudnosci << ", dostepnosc " << dostepnosc << ") ";
}

ostream& operator<<(ostream& out, const Zaklecie& p)
{
	p.info(out);
	out << endl;
	return out;
}

// klasa ZaklecieOfensywne

ZaklecieOfensywne::ZaklecieOfensywne(string nazwa, string opis, int poziom_trudnosci, int obrazenia) : Zaklecie(nazwa, opis, poziom_trudnosci), obrazenia(obrazenia) {}

int ZaklecieOfensywne::wypowiedz_zaklecie() {
	dostepnosc = false;

	return obrazenia;
}

void ZaklecieOfensywne::info(ostream& out) const {
	Zaklecie::info(out);
	out << " Zadawane obrazenia: " << obrazenia;
}

// klasa ZaklecieDefensywne

ZaklecieDefensywne::ZaklecieDefensywne(string nazwa, string opis, int poziom_trudnosci, int odzyskane_punkty_zycia) : Zaklecie(nazwa, opis, poziom_trudnosci), odzyskane_punkty_zycia(odzyskane_punkty_zycia) {}

int ZaklecieDefensywne::wypowiedz_zaklecie() {
	dostepnosc = false;

	return odzyskane_punkty_zycia;
}

void ZaklecieDefensywne::info(ostream& out) const {
	Zaklecie::info(out);
	out << " Punkty zycia do odzyskania: " << odzyskane_punkty_zycia;
}