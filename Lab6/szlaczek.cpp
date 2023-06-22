#include "szlaczek.h"
#include "tab.h"

szlaczek::szlaczek(int sx, element el) : sx{sx}, el{el}
{ 
}

void szlaczek::rysuj(tab& t) const
{
	if (sx >= t.size() || sx < 0) return;

	for (int i = 0;i < t.size(); i++) {
		t(sx, i) = el;
	}
	
}

