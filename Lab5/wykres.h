#pragma once
#include <iostream> 
using namespace std;

class wykres
{
private:
	sygnal** sygnaly;
	int ilosc_sygnalow;
	int ilosc_wierszy;
	int ilosc_kolumn;
	char** uklad_wspolrzednych;

public:
	wykres(int ilosc_sygnalow = 0, sygnal** sygnaly = nullptr); //3 pkt
	~wykres(); //0.5 pkt

	wykres& operator=(const wykres&); //1.5 pkt
	friend ostream& operator<<(ostream&, const wykres&); //1 pkt
};