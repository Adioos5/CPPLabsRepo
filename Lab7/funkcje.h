#pragma once

class kredyt;


bool cmp_wartosc(const kredyt& k1, const kredyt& k2);
bool cmp_wartosc_info(const kredyt& k1, const kredyt& k2);

void wypisz(kredyt** kr, int n, const char* opis);
void sortuj(kredyt** kr, int n, bool cmp(const kredyt&, const kredyt&) = cmp_wartosc);



