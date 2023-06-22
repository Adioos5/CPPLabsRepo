#include <iostream> 
#include "sygnal.h"
#include "wykres.h"
#include <cmath>

wykres::wykres(int ilosc_sygnalow, sygnal** sygnaly) {

	if (sygnaly) {
		this->sygnaly = new (nothrow) sygnal * [ilosc_sygnalow];
		for (int i = 0 ; i < ilosc_sygnalow ; i++) this->sygnaly[i] = new (nothrow) sygnal;
	
		int max_val = sygnaly[0]->probki[0], min_val = sygnaly[0]->probki[0], max_c = 0;

		for (int i = 0;i < ilosc_sygnalow;i++) {
			for (int k = 0;k < sygnaly[i]->ilosc_probek;k++) {
				max_val = max(max_val, sygnaly[i]->probki[k]);
				min_val = min(min_val, sygnaly[i]->probki[k]);
				max_c = max(max_c, k+1);
			}
		}

		ilosc_wierszy = abs(max_val - min_val) + 1;
		ilosc_kolumn = max_c;

		uklad_wspolrzednych = new (nothrow) char* [ilosc_wierszy];
		for (int i = 0;i < ilosc_wierszy;i++) {
			uklad_wspolrzednych[i] = new (nothrow) char[ilosc_kolumn];
		}

		for (int i = 0;i < ilosc_wierszy;i++) {
			for (int j = 0;j < ilosc_kolumn;j++) {
				uklad_wspolrzednych[i][j] = ' ';
			}
		}

		for (int i = 0;i < ilosc_sygnalow;i++) {
			for (int k = 0;k < sygnaly[i]->ilosc_probek;k++) {
				uklad_wspolrzednych[max_val - sygnaly[i]->probki[k]][k] = '*';
			}
		}
	}
}

wykres::~wykres() {
	for (int i = 0;i < ilosc_sygnalow;i++) {
		delete sygnaly[i];
	}
	delete[] sygnaly;

	for (int i = 0;i < ilosc_wierszy;i++) {
		delete[] uklad_wspolrzednych[i];
	}

	delete[] uklad_wspolrzednych;
}

ostream& operator<<(ostream& out, const wykres& w) {
	for (int i = 0;i < w.ilosc_kolumn;i++) {
		out << "-";
	}
	out << endl;

	for (int i = 0;i < w.ilosc_wierszy;i++) {
		for (int j = 0;j < w.ilosc_kolumn;j++) {
			out << w.uklad_wspolrzednych[i][j];
		}
		out << endl;
	}
	for (int i = 0;i < w.ilosc_kolumn;i++) {
		out << "-";
	}

	return out;

}

wykres& wykres::operator=(const wykres& w) {
	if (sygnaly) {
		for (int i = 0;i < ilosc_sygnalow;i++) delete sygnaly[i];
		delete[] sygnaly;
	}

	if (uklad_wspolrzednych) {
		for (int i = 0;i < ilosc_wierszy;i++) {
			delete[] uklad_wspolrzednych[i];
		}

		delete[] uklad_wspolrzednych;
	}

	ilosc_wierszy = w.ilosc_wierszy;
	ilosc_kolumn = w.ilosc_kolumn;
	ilosc_sygnalow = w.ilosc_sygnalow;

	sygnaly = new (nothrow) sygnal * [ilosc_sygnalow];
	for (int i = 0;i < ilosc_sygnalow;i++) sygnaly[i] = new (nothrow) sygnal;

	for (int i = 0;i < ilosc_sygnalow;i++) sygnaly[i] = w.sygnaly[i];

	uklad_wspolrzednych = new (nothrow) char* [ilosc_wierszy];
	for (int i = 0;i < ilosc_wierszy;i++) {
		uklad_wspolrzednych[i] = new (nothrow) char[ilosc_kolumn];
	}

	for (int i = 0;i < ilosc_wierszy;i++) {
		for (int j = 0;j < ilosc_kolumn;j++) {
			uklad_wspolrzednych[i][j] = w.uklad_wspolrzednych[i][j];
		}
	}

	return *this;
}