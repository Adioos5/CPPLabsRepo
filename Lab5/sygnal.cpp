#include "sygnal.h"

sygnal::sygnal(int ilosc_probek, int* probki): ilosc_probek(ilosc_probek) {
	if (ilosc_probek != 0 && !probki) {
		this->probki = new (nothrow) int[ilosc_probek];
		if (this->probki) for (int i = 0;i < ilosc_probek;i++) this->probki[i] = 0;
	}
	else if (ilosc_probek != 0 && probki) {
		this->probki = new (nothrow) int[ilosc_probek];
		if (this->probki) for (int i = 0;i < ilosc_probek;i++) this->probki[i] = probki[i];
	}
}

sygnal::sygnal(const sygnal& s) {
	ilosc_probek = s.ilosc_probek;

	probki = new (nothrow) int[ilosc_probek];

	if (probki) for (int i = 0;i < ilosc_probek;i++) probki[i] = s.probki[i];
}

sygnal::~sygnal() {
	delete[] probki;
}

sygnal operator+(const sygnal& s1, const sygnal& s2) {
	sygnal s3(s1.ilosc_probek + s2.ilosc_probek);

	for (int i = 0;i < s1.ilosc_probek;i++) s3.probki[i] = s1.probki[i];
	for (int i = 0;i < s2.ilosc_probek;i++) s3.probki[i + s1.ilosc_probek] = s2.probki[i];

	return s3;
}

ostream& operator<<(ostream& out, const sygnal& s) {
	out << "( ";
	for (int i = 0;i < s.ilosc_probek;i++) {
		out << s.probki[i] << " ";
	}
	out << ")";

	return out;
}