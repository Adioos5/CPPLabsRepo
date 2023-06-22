#include <iostream>
#include <math.h>
#include "sygnal.h"
#include "wykres.h"

int main()
{
	std::cout << "===================== ETAP 1 =====================" << std::endl;

	// Konstruktor bezargumentowy
	sygnal sygnal_1;
	// Konstruktor z sygna³em zerowym
	sygnal* sygnal_2 = new sygnal(10);
	// Konstruktor z sygna³em prostokatnym
	int s3[20] = {0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5};
	sygnal sygnal_3(20,s3);
	// Konstruktor z sygna³em sinusoidalnym
	int s4[50];
	for (int i = 0; i < 50; i++) s4[i] = (int)(10*sin(2*3.14*0.5*i/10));
	sygnal sygnal_4(50, s4);

	cout << "Pusty sygnal - nic sie nie wyswietla" << endl;
	cout << sygnal_1 << endl;
	cout << "Sygnal zerowy - same zera" << endl;
	cout << *sygnal_2 << endl;
	cout << "Sygnal prostokatny" << endl;
	cout << sygnal_3 << endl;

	cout << "Sygnal sinusoidalny" << endl;
	cout << sygnal_4 << endl;

	cout << "Konkatenacja sygnalow" << endl;
	cout << sygnal_3 + sygnal_4 << endl;

	int* p = sygnal_2->get_probki();
	delete sygnal_2;
	if (p[0] != 0) cout << "Etak 1 - OK" << endl;
	else cout << "Czegos jeszcze brakuje..." << endl;

	cout << endl;
	std::cout << "===================== ETAP 2 =====================" << std::endl;

	sygnal* sygnaly_1[] = { &sygnal_3 };
	sygnal* sygnaly_2[] = { &sygnal_3, &sygnal_4 };

	wykres wykres_1;
	wykres* wykres_2 = new wykres(1, sygnaly_1);
	wykres wykres_3(2, sygnaly_2);
	
	cout << "Pusty wykres - nic sie nie rysuje" << endl;
	cout << wykres_1 << endl;
	cout << "Wykres jednego sygnalu" << endl;
	cout << *wykres_2 << endl;
	cout << "Wykres dwoch sygnalow" << endl;
	cout << wykres_3 << endl;

	wykres wykres_4;
	wykres_4 = *wykres_2;
	delete wykres_2;
	cout << "Wykres sygnalu 4-tego" << endl;
	cout << wykres_4 << endl;

	return 0;
}