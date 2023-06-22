#include <iostream> 
using namespace std;
#include "Jaszczurka.h"

// uzupelnij

// Klasa Jaszczurka


ostream& operator<<(ostream& out, const Jaszczurka& p)
{
	p.info(out);
	return out;
}

// Klasa Jaszczurka_Zwyczjna

void Jaszczurka::przyjmij_atak(int obrazenia)
{
	punktyZycia -= obrazenia;
}

void Jaszczurka_Zwyczjna::info(ostream& out) const {
	out << "Jaszczurka Zwyczjna - poziom ochrony: " << poziom_ochrony << " punkty zycia: " << punktyZycia;
}


int Jaszczurka_Zwyczjna::ugryzienie() const {
	return 3;
}

int Jaszczurka_Zwyczjna::wykonaj_atak(int poziom_ochrony_przeciwnika) const {
	if (sila_ataku > poziom_ochrony_przeciwnika) {
		return ugryzienie();
	}

	return 0;
}

// Klasa Jaszczurka_Elektryczna

int Jaszczurka_Elektryczna::ile_jaszczurek = 0;

void Jaszczurka_Elektryczna::info(ostream& out) const {
	out << "Jaszczurka Elektryczna - poziom ochrony: " << poziom_ochrony << " punkty zycia: " << punktyZycia;
}

Jaszczurka_Elektryczna::Jaszczurka_Elektryczna() {
	punktyZycia = 10;
	sila_ataku = 4;
	poziom_ochrony = 2;

	ile_jaszczurek++;
}

Jaszczurka_Elektryczna::~Jaszczurka_Elektryczna() { ile_jaszczurek--; }

int Jaszczurka_Elektryczna::porazenie() const {
	return 3 * ile_jaszczurek;
}

int Jaszczurka_Elektryczna::wykonaj_atak(int poziom_ochrony_przeciwnika) const {

	if (ile_jaszczurek >= 3) {
		return porazenie();
	}
	else if (sila_ataku > poziom_ochrony_przeciwnika) {
		return ugryzienie();
	}

	return 0;
}
