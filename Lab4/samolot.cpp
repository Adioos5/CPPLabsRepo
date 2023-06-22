//implementacja klasy Samolot
#include "samolot.h"

int Samolot::ilosc_samolotow_w_powietrzu;
int Samolot::max_id;

Samolot::Samolot() : id(++max_id), ilosc_pasazerow(0), ilosc_startow(0), status(GOTOWY), port_docelowy("port nieznany") {}

int Samolot::start() {

	static int ilosc_startow;

	if (status == GOTOWY) {
		status = ODLECIAL;

		this->ilosc_startow++;
		ilosc_samolotow_w_powietrzu++;

		ilosc_startow++;
	}
	return ilosc_startow;
}

void Samolot::laduj() {
	if (status == ODLECIAL) {
		status = WYLADOWAL;
		ilosc_samolotow_w_powietrzu--;
	}
}

int Samolot::pobierz_starty() const {
	return ilosc_startow;
}

int Samolot::pobierz_ilosc_w_powietrzu() const {
	return ilosc_samolotow_w_powietrzu;
}

void Samolot::przygotuj_do_startu(int wysiada, int wsiada, const char* port) {

	if (wysiada > ilosc_pasazerow) ilosc_pasazerow = 0;
	else ilosc_pasazerow -= wysiada;

	ilosc_pasazerow += wsiada;

	strcpy_s(port_docelowy, port);
	status = GOTOWY;
}

ostream& operator<<(ostream& out, const Samolot& s) {
	out << "Samolot nr " << s.id << " do " << s.port_docelowy << " z " << s.ilosc_pasazerow << " pasazerami na pokladzie " << ((s.status == s.GOTOWY) ? "przygotowany do startu" : ((s.status == s.WYLADOWAL) ? "wyladowal" : "odlecial"));

	return out;
}

















