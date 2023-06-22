#include "samolot.h"
#include "lotnisko.h"

using namespace std;


int main()
{
	const int MAX_ILOSC_STARTOW = 100;

	/*******************************************************************/
	cout << "ETAP 1" << endl;
	cout << "*****************************************************************" << endl << endl;

	cout << "Samolot 1: " << endl;
	Samolot s1;
	cout << s1 << endl;
	s1.przygotuj_do_startu(0, 20, "Radom");
	cout << s1 << endl;
	s1.start();
	cout << s1 << endl;
	s1.laduj();
	cout << s1 << endl;
	s1.przygotuj_do_startu(22, 49, "Krakow");
	cout << s1 << endl;
	s1.start();
	cout << s1 << endl;
	cout << endl << "Samolot 2: " << endl;
	Samolot s2,s3;
	s2.start();
	cout << s2 << endl;
	s3.przygotuj_do_startu(0,33,"Warszawa");
	cout << endl << "Samolot 3: " << endl;
	cout << s3 << endl;
	cout << endl << "Statystyka: " << endl;
	cout << "s1 wylatywal " << s1.pobierz_starty() << " razy" << endl;
	cout << "s2 wylatywal " << s2.pobierz_starty() << " razy" << endl;
	cout << "Wszystkich startow " << s1.start() << endl;
	cout << "Samolotow w powietrzu " << s1.pobierz_ilosc_w_powietrzu() << endl;

	/*******************************************************************/
/*	cout << endl << endl << "ETAP 2" << endl; 
	cout << "*****************************************************************" << endl << endl;
	s3.start();

	Lotnisko lot_1;
	lot_1 += s1;
	lot_1 += s2;
	lot_1 += s3;
	Samolot s4;
	lot_1 += s4;
	s4.przygotuj_do_startu(0,44,"Wroclaw");
	s1.przygotuj_do_startu(14, 33, "Katowice");
	s2.przygotuj_do_startu(0, 21, "Gdansk");
	cout << lot_1 << endl;
	cout << "Start samolotu s1 z lotniska 1:" << endl;
	if(lot_1.zezwol_na_start(s1))
		cout << s1 << " z lotniska nr 1" << endl;
	else
		cout << s1 << ", wiec nie moze wystartowac ponownie" << endl;
	cout << "Proba ponownego wystartowania samolotu s1 :" << endl;
	if (lot_1.zezwol_na_start(s1))
		cout << s1 << " z lotniska nr 1" << endl;
	else
		cout << s1 << " wiec nie moze wystartowac ponownie" << endl;

	cout << endl << "Przygotowanie samolotow na drugie lotnisko:" << endl;
	Samolot s5, s6, s7, s8, s9, s10, s11;
	s5.przygotuj_do_startu(0, 77, "Koluszki");
	s5.start();
	s6.przygotuj_do_startu(0, 45, "Modlin");
	s6.start();
	s7.przygotuj_do_startu(0, 73, "Rzeszow");
	s7.start();
	s8.przygotuj_do_startu(0, 99, "Suwalki");
	s8.start();
	s9.przygotuj_do_startu(0, 12, "Poznan");
	s9.start();
	s9.przygotuj_do_startu(0, 12, "Poznan");
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
	cout << s8 << endl;
	cout << s9 << endl;
	cout << s10 << endl;
	cout << s11 << endl;
	Lotnisko lot_2;
	lot_2 += s10;
	lot_2 += s11;
	if (!(lot_2 += s5)) lot_2.przekieruj(s5, "Warszawa");
	if (!(lot_2 += s6)) lot_2.przekieruj(s6, "Warszawa");
	if (!(lot_2 += s7)) lot_2.przekieruj(s7, "Warszawa");
	if (!(lot_2 += s8)) lot_2.przekieruj(s8, "Warszawa");
	cout << lot_2 << endl;
	cout << "Przekierowany: " << endl;
	cout << s8 << endl;

	cout << endl << "Statystyka: " << endl;
	cout << "Wszystkich startow " << s8.start() << endl;
	cout << "Samolotow w powietrzu " << s1.pobierz_ilosc_w_powietrzu() << endl;
*/

	/*******************************************************************/
/*	cout << endl << endl << "ETAP 3" << endl;
	cout << "*****************************************************************" << endl << endl;

	cout << s1 << endl;
	for (int i = 0; i < MAX_ILOSC_STARTOW; i++)
	{
		lot_1.zezwol_na_start(s1);
		lot_1 += s1;
		if (s1.pobierz_starty() >= MAX_ILOSC_STARTOW) break;
		s1.przygotuj_do_startu(0, 1, "Szczecin");
	}
	cout << s1 << endl;
	cout << "s1 wylatywal " << s1.pobierz_starty() << " razy" << endl;
	
	for (int i = 0; i < MAX_ILOSC_STARTOW; i++)
	{
		lot_1.zezwol_na_start(s4);
		lot_1 += s4;
		if (s4.pobierz_starty() >= MAX_ILOSC_STARTOW) break;
		s4.przygotuj_do_startu(0, 2, "Opole");
	}
	cout << s4 << endl;
	cout << "s4 wylatywal " << s4.pobierz_starty() << " razy" << endl;

	cout << endl << "Samoloty przed naprawa: ";
	cout << lot_1 << endl;
	////////////////////////////////////////////////////////////////////////////////////
	//TODO
	//Wyszukanie na lotnisku nr 1 samolotów przeznaczonych do naprawy i ich naprawa
	
	////////////////////////////////////////////////////////////////////////////////////
	cout << endl << "Samoloty po naprawie: ";
	cout << lot_1 << endl;
*/

	cout << endl;
	
}