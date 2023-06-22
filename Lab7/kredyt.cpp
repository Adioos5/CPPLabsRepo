#include <iostream>
using namespace std;
#include <iomanip>
#include "kredyt.h"

kredyt::kredyt(double wartosc, double oproc, int ile_lat, int ile_rat_rok, const char* info): wartosc(wartosc), oproc(oproc), ile_lat(ile_lat), ile_rat_rok(ile_rat_rok), info(info)
{
	//uzupe³nij


}

kredyt::~kredyt(){}


double kredyt::rata() const
{
	double q = 1 + oproc;
	int n = ile_rat_rok * ile_lat;
	double rata = wartosc * pow(q, n) * (q - 1) / (pow(q,n - 1));

	return rata;
}

void kredyt::wypisz(ostream& out) const
{
	out << info << "kredyt: " << wartosc << "(" << oproc << "%) lata: " << ile_lat << "r/r: " << ile_rat_rok << "rata: " << rata();

}

ostream& operator<<(ostream& out, const kredyt& os)
{
	os.wypisz(out);
	return out;
}




