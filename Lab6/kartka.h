#pragma once
#include "tab.h"
#include "historia.h"
#include "szlaczek.h"

class kartka 
{
	tab obrazek;

	historia* h{nullptr};

public:
	kartka(int m); // wype�nia kartk� kolorem CIEMNY_ZIELONY

	kartka() = delete;
	kartka(const kartka& k) = delete;
	kartka& operator=(const kartka& k) = delete;

	~kartka();
	
	int size() const { return obrazek.size(); }
	void jajo(); //wszystko poza jajem jest zamalowane kolorem t�a (JASNO_SZARY)
	void dodaj( const szlaczek& sz);

	void resetuj(int m);	//nowa kartka z jajem (z rozmiarem m)

	void zapisz() const;	//etap 3
	void cofnij();			//etap 3
	
	friend std::ostream& operator<<(std::ostream& out, const kartka& k);

	//8-szary,9-niebieski,10-zielony,11-trukusowy,12-czerwony,13-fioletowy,14-��ty
	enum kolory {CIEMNY_ZIELONY=2, JASNO_SZARY=7, SZARY, NIEBIESKI, ZIELONY, TURKUSOWY, CZERWONY, FIOLETOWY, ZOLTY};
};

