#pragma once


class element;

class tab   //GOTOWA
{
	element* t;		// dynamiczna tablica o wymiarze m*m reprezentuj�ca tablic� kwadratow�
	int	m;			// wymiar tablicy

	//-----------------------------------------------------------------------
	void init(int m);	// tylko przydziela pami�� na dynamiczn� talic� t
	void wypelnij(const element& el, const element* t=nullptr);	// wype�nia podan� warto�ci�
	void zwolnij();		// zwolnienie pami�ci po tablicy t

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



