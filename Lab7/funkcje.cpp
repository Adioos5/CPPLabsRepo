#include <iostream>
using namespace std;
#include "funkcje.h"
#include "kredyt.h"


bool cmp_wartosc(const kredyt& k1, const kredyt& k2)
{
	//kryterium sortowania po wartoœciach kredytu
	//uzupe³nij

	return k1.wartosc>k2.wartosc;	//popraw!
}

bool cmp_wartosc_info(const kredyt& k1, const kredyt& k2)
{
	//kryterium sortowania po wartoœciach kredytu, a s¹ takie same to po info
	//uzupe³nij
	if (cmp_wartosc(k1, k2)) {
		return true;
	}
	else {
		return strcmp(k1.info, k2.info) > 0;
	}

}


//-----------------------------------------------------------------
void wypisz(kredyt** kr, int n, const char* opis)		//GOTOWA
{
	cout << endl << opis;
	for (int i = 0; i < n; i++) cout << *kr[i];
	cout << endl;
}

void sortuj(kredyt** kr, int n, bool cmp(const kredyt&, const kredyt&))
{
	//uzupe³nij (w³asna implementacja)



}