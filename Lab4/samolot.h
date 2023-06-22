#pragma once
#include <iostream>
using std::ostream;

class Lotnisko;

class Samolot
{
private:
	static int ilosc_samolotow_w_powietrzu;
	static int max_id; 

	const int id;

	int ilosc_startow;
	int ilosc_pasazerow;

	enum status_samolotu { GOTOWY, ODLECIAL, WYLADOWAL} status;
	
	static const int NAZWA = 100;
	char port_docelowy[NAZWA];

public:
	Samolot();

	int start();
	void laduj();
	void przygotuj_do_startu(int ,int , const char *);

	int pobierz_starty() const;
	int pobierz_ilosc_w_powietrzu() const;

	friend ostream& operator<<(ostream& out, const Samolot&);

	friend class Lotnisko;

};