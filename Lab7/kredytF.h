
#include "kredyt.h"


class kredytF: public kredyt
{
	double* prognoza;	//rozliczenie kredytu: kolejne elementy dynamicznej tablicy to wartoœci
	int ile_rat;		//ile kredytu jest jeszcze do sp³acenia po dokonaniu kolejnych rat
	
	void init_prognoza(int ile_rat=0, double* prognoza=nullptr);
	
public:
	kredytF():ile_rat(0),prognoza(nullptr){ }
	kredytF(double wartosc, double oproc, int ile_lat , int ile_rat_rok, const char* info = "xxxxxxxxxx");

	kredytF(const kredytF& k);				//zdefiniuj, je¿eli uwa¿asz ¿e jest potrzebne
	kredytF& operator=(const kredytF& k);		//zdefiniuj, je¿eli uwa¿asz ¿e jest potrzebne
	~kredytF();								//zdefiniuj, je¿eli uwa¿asz ¿e jest potrzebne
		
	void rozlicz() const;

	void wypisz(ostream& out) const;
	
};
