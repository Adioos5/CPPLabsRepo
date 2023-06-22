#pragma once
#include "tab.h"

class historia
{
private: //wszystko prywatne

	
	static const int N = 4;		//maksymalna iloœæ obrazków w historii
	tab* h[N]{nullptr};
	int ile;		// 1<=ile<=N
					// zawsze w historii pozostaje co najmniej 1 obrazek (o indeksie 0)

	//-------------------------------------------------------------------------------------------------
	historia(const tab& obrazek);	// od razu na pocz¹tku do historii wpisujemy bie¿¹cy obrazek (indeks 0)
	

	// uzupe³nij
	// zabroniony konstruktor bezparametrowy, konstruktor kopiuj¹cy oraz operator=
	historia() = delete;
	historia(const historia&) = delete;
	historia& operator=(const historia&) = delete;

	void write(const tab& obrazek);	// na koniec tablicy wstawiamy bie¿¹cy obrazek, 
									// jeœli brakuje miejsca, to trzeba je zaplanowaæ (jak?)
	
	tab undo();		// jeœli w historii mamy tylko 1 obrazek (ile==1), to go zwracamy
					// wpp zwracamy przedostatni
					// (zawsze w historii pozostaje co najmniej 1 obrazek)
	
	void clear();  //czyszczenie historii
	
	~historia();

	friend class kartka;
};

