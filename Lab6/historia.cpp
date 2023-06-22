#include <iostream>
#include "historia.h"

using namespace std;

historia::historia(const tab& obrazek)
{
	h[0] = new (nothrow) tab(obrazek);
	ile = 1;


}
	
void historia::write(const tab& obrazek)
{
	if (ile < N) {
		if (!h[ile]) h[ile] = new (nothrow) tab(obrazek);
		else *h[ile] = tab(obrazek);
		
		ile++;
	}
	else {

		for (int i = 0;i < N - 1;i++) h[i] = h[i + 1];
		*h[N-1] = tab(obrazek);
	}
	
}
		
tab historia::undo()
{
	if (ile == 1) {
		return *h[0];
	}
	else {
		ile--;

		return *h[ile - 1];

	}

}

void historia::clear()
{

	for (int i = 0;i < ile;i++) {
		delete h[i];
	}
	

}

historia::~historia()
{
	clear();
}
