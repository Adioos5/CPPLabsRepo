#include <iostream>
using namespace std;
#include <iomanip>
#include "kredytF.h"


//-----------------------------------------------------------------
void kredytF::init_prognoza(int ile_rat, double* prognoza)
{
	this->ile_rat=ile_rat;
	this->prognoza=nullptr;

	//uzupe³nij
	//alokacja pamiêci na tablicê, któr¹ wype³niamy wartoœciami z 2go parametru, lub gdy brak zerujemy
	if (ile_rat > 0) {
		this->prognoza = new double[ile_rat];
		if (!this->prognoza) return;
		if (prognoza) {
			for (int i = 0;i < ile_rat;i++) {
				this->prognoza[i] = prognoza[i];
			}
		}
		else {
			for (int i = 0;i < ile_rat;i++) {
				this->prognoza[i] = 0;
			}
		}
	}


}
//-------------------------------------------------------------------
kredytF::kredytF(double wartosc, double oproc, int ile_lat, int ile_rat_rok, const char* info)
{
	//uzupe³nij
	//wywo³aj init_prognoza oraz rozlicz
	init_prognoza(ile_rat, prognoza);
	rozlicz();
	


}

kredytF::kredytF(const kredytF& kF): kredyt(kF) {
	init_prognoza(kF.ile_rat, kF.prognoza);
}

kredytF& kredytF::operator=(const kredytF& k) {
	if (&k == this)
		return *this;

	this->wartosc = k.wartosc;
	this->oproc = k.oproc;
	this->ile_lat = k.ile_lat;
	this->ile_rat_rok = k.ile_rat_rok;
	delete[] prognoza;
	init_prognoza(k.ile_rat, k.prognoza);

	return *this;
}

//-----------------------------------------------------------
void kredytF::rozlicz() const	// ile kredytu jeszcze do sp³acenia po wplaceniu (i) rat
{
	double w;
	double odsetki;
	double r = rata();

	for (int i = 0;i < ile_rat;i++) {
		w = wartosc;
		for (int j = 0;j <= i;j++) {
			odsetki = w * oproc;
			w -= r - odsetki;
		}
		prognoza[i] = w;
	}

}
//-----------------------------------------------------------
void kredytF::wypisz(ostream& out) const
{
	kredyt::wypisz(out);
	
	out << "prognoza: [ ";
	for (int i = 0;i < ile_rat;i++) {
		out << prognoza[i] << " ";
	}
	out << "]";

}

kredytF::~kredytF() {
	delete[] prognoza;
}
//-------------------------------------------------------------

