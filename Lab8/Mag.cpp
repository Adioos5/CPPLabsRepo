#include <iostream> 
using namespace std;
#include "Mag.h"
#include "Przedmiot.h"
#include "Bron.h"
#include "Zbroja.h"
#include "Artefakt.h"
#include "Zaklecie.h"

// klasa Mag


Mag::Mag(string imie, int punktyZycia, int zrecznosc, int sila, int poziom) : Postac(imie, punktyZycia, zrecznosc, sila, poziom)
{
	for (int i = 0; i < ilosc_zaklec; i++)
		zaklecia[i] = nullptr;
	zaklecia[0] = new ZaklecieOfensywne("Widmowe Ostrza", "zadje 2 obrazenia", 1, 2);
	zaklecia[1] = new ZaklecieDefensywne ("Leczniczy dotyk", "leczy 4 obrazenia", 1, 4);
	zaklecia[2] = new ZaklecieOfensywne("Ognista strzala", "zadaje 6 obrazen", 2, 6);
	zaklecia[3] = new ZaklecieDefensywne("Powiew leczenia", "leczy 6 obrazen", 2, 6);
	zaklecia[4] = new ZaklecieOfensywne("Piorun smierci", "zadaje 16 obrazen", 4, 16);
	zaklecia[5] = new ZaklecieDefensywne("Ozdrowienie", "leczy 16 obrazen", 4, 16);

	ekwipunek = new (nothrow) Przedmiot*[4];
	ekwipunek[0] = new Bron("Kij", "klasyczny kij drewniany", 2);
	ekwipunek[1] = new Przedmiot("Butelka", "butelka z woda pitna");
	ekwipunek[2] = new Bron("Sztylet", "sztylet krotki", 1);
	ekwipunek[3] = new Artefakt("Amulet zielonego kamienia", "amulet zwiekszajacy poziom ochrony", Artefakt::typ_artefaktu::MODYFIKUJACY_OCHRONE, 3);
}

Mag::~Mag() {

	for (int i = 0;i < ilosc_zaklec;i++) delete zaklecia[i];
	for (int i = 0;i < wielkosc_ekwipunku;i++) delete ekwipunek[i];
}

int Mag::wykonaj_atak(int poziom_ochrony_przeciwnika) {

	if (punktyZycia < 10 && czy_dostepne_defensywne() != -1) punktyZycia += zaklecia[czy_dostepne_defensywne()]->wypowiedz_zaklecie();
	else if(punktyZycia < 10 && czy_dostepne_defensywne() == -1) return Postac::wykonaj_atak(poziom_ochrony_przeciwnika);
	else if(punktyZycia >= 10) {
		if (czy_dostepne_ofensywne() != -1) return zaklecia[czy_dostepne_ofensywne()]->wypowiedz_zaklecie();
		else return Postac::wykonaj_atak(poziom_ochrony_przeciwnika);
	}

	return 0;
}

int Mag::czy_dostepne_ofensywne() const {
	
	ZaklecieOfensywne* po = nullptr;

	for (int i = 0;i < ilosc_zaklec;i++) {
		po = dynamic_cast<ZaklecieOfensywne*>(zaklecia[i]);
		if (po) {
			if (poziom >= zaklecia[i]->poziom_trudnosci) return i;
		}
	}

	return -1;
}

int Mag::czy_dostepne_defensywne() const {
	ZaklecieDefensywne* po = nullptr;

	for (int i = 0;i < ilosc_zaklec;i++) {
		po = dynamic_cast<ZaklecieDefensywne*>(zaklecia[i]);
		if (po) {
			if (poziom >= zaklecia[i]->poziom_trudnosci) return i;
		}
	}

	return -1;
}

void Mag::przygotowanie() {
	for (int i = 0;i < ilosc_zaklec;i++) {
		zaklecia[i]->dostepnosc = true;
	}

	Bron* pb = nullptr;
	for (int i = 0;i < wielkosc_ekwipunku;i++) {
		pb = dynamic_cast<Bron*>(ekwipunek[i]);
		if (pb) {
			ekwipunek[i] = nullptr;
			break;
		}
	}

	Zbroja* pz = nullptr;
	for (int i = 0;i < wielkosc_ekwipunku;i++) {
		pz = dynamic_cast<Zbroja*>(ekwipunek[i]);
		if (pz) {
			poziom_ochrony += pz->wykorzystaj_ochrone();
			ekwipunek[i] = nullptr;
			break;
		}
	}

	Artefakt* pa = nullptr;
	for (int i = 0;i < wielkosc_ekwipunku;i++) {
		pa = dynamic_cast<Artefakt*>(ekwipunek[i]);
		if (pa) {
			switch (pa->jaki_typ_artefaktu()) {
			case Artefakt::typ_artefaktu::MODYFIKUJACY_OCHRONE:
				poziom_ochrony += pa->wykorzystaj_artefakt();
				break;
			case Artefakt::typ_artefaktu::MODYFIKUJACY_ATAK:
				sila_ataku += pa->wykorzystaj_artefakt();
				break;
			default:
				break;
			}

			ekwipunek[i] = nullptr;
			break;
		}
	}

	bron_w_reku = pb;
	zbroja_na_ciele = pz;
	artefakt = pa;


}


void Mag::info(ostream& out) const
{
	Postac::info(out);
	cout << "Zaklecia: " << endl;
	for (int i = 0; i < ilosc_zaklec; i++)
		out << *zaklecia[i];
	cout << "Ekwipunek: " << endl;
	for (int i = 0; i < wielkosc_ekwipunku; i++)
	{
		if (ekwipunek[i])
			out << i + 1 << ". " << *ekwipunek[i];
		else
			out << i + 1 << ". " << "pusto" << endl;
	}
}



