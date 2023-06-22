#include <iostream>
using namespace std;
#include "kartka.h"


kartka::kartka(int m) : obrazek{m, element(CIEMNY_ZIELONY)}
{
	jajo();
	h = new (nothrow) historia(obrazek);
}

void kartka::dodaj( const szlaczek& sz) 
{
	sz.rysuj(obrazek);
	jajo();

}

void kartka::jajo()
{ //wszystko poza jajem jest zamalowane kolorem JASNO_SZARY
		
	int sx = obrazek.size() / 2;
	int sy = obrazek.size() / 2;
	int r = min(sx, sy) - 1;

	element el(JASNO_SZARY);

	for (int i = 0;i < obrazek.size();i++) {
		for (int j = 0;j < obrazek.size();j++) {
			if ((i - sx) * (i - sx) + (j - sy) * (j - sy) > r * r) {
				obrazek(i, j) = el;
			}
		}
	}

}

void kartka::resetuj(int m)
{
	obrazek = tab(m, element(CIEMNY_ZIELONY));
	jajo();

}

void kartka::zapisz() const 
{
	h->write(obrazek);

}

void kartka::cofnij()
{
	obrazek = h->undo();
	

}

kartka::~kartka() 
{ 
	delete h;

}

std::ostream& operator<<(std::ostream& out, const kartka& k)
{
	//wypisanie tylko obrazka

	int m = k.obrazek.size();

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < m;j++) {
			out << k.obrazek(i, j);
		}
		out << endl;
	}


	return out;

}





