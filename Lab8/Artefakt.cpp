#include <iostream> 
using namespace std;
#include "Artefakt.h"

// klasa Artefakt

Artefakt::Artefakt(string nazwa, string opis, typ_artefaktu typ, int modyfikator) : Przedmiot(nazwa, opis), typ(typ), modyfikator(modyfikator) {}

int Artefakt::wykorzystaj_artefakt() const {
	return modyfikator;
}

void Artefakt::info(ostream& out) const {
	Przedmiot::info(out);
	out << " Modyfikator obrony: " << modyfikator;
}