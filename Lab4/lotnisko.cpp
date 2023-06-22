//implementacja klasy Lotnisko
#include "lotnisko.h"

int Lotnisko::max_id_lotniska;

Lotnisko::Lotnisko(): ilosc_samolotow(0), id_lotniska(++max_id_lotniska) {
	for (int i = 0;i < MAX_ILOSC_SAMOLOTOW;i++) {
		samoloty[i] = nullptr;
	}
}

bool Lotnisko::zezwol_na_start(Samolot& s) {
	
	if (s.status == Samolot::GOTOWY) {
		int tmp;

		s.start();

		for (int i = 0;i < ilosc_samolotow;i++) {
			if (samoloty[i]->id == s.id) {
				tmp = i;
				samoloty[i] = nullptr;

				for (int i = tmp;i < ilosc_samolotow - 1;i++) {
					samoloty[i] = samoloty[i + 1];
				}

				samoloty[ilosc_samolotow - 1] = nullptr;
				ilosc_samolotow--;

				return true;
			}
		}
	}
	return false;
}

bool Lotnisko::operator+=(Samolot& s) {
	
	if (ilosc_samolotow < MAX_ILOSC_SAMOLOTOW) {

		samoloty[ilosc_samolotow] = &s;
		ilosc_samolotow++;

		if (s.status == Samolot::ODLECIAL) s.laduj();

		return true;
	}

	return false;
}


   








