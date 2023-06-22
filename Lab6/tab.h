#pragma once


class element;

class tab   //GOTOWA
{
	element* t;		// dynamiczna tablica o wymiarze m*m reprezentuj¹ca tablicê kwadratow¹
	int	m;			// wymiar tablicy

	//-----------------------------------------------------------------------
	void init(int m);	// tylko przydziela pamiêæ na dynamiczn¹ talicê t
	void wypelnij(const element& el, const element* t=nullptr);	// wype³nia podan¹ wartoœci¹
	void zwolnij();		// zwolnienie pamiêci po tablicy t

public:
	tab();
	tab(int m, const element& el);

	tab(const tab& t);
	tab& operator=(const tab& t);
	~tab();

	int size() const; 

	element& operator()(int i, int j);
	const element& operator()(int i, int j) const;

};



