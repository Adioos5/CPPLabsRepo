#pragma once
#include "element.h"
#include "tab.h"

class szlaczek	{	
	int sx;			// pozioma wspó³rzêdna szlaczka (0<=sx<m)
	element el;		// element u¿yty do rysowania szlaczka

public:
	szlaczek(int sx, element el);
	void rysuj(tab& t) const;	// "rysuje" szlaczek w tablicy obrazka
};


