#include <iostream>
using namespace std;
#include "kredyt.h"
#include "kredytF.h"
#include "funkcje.h"


//-------------------------------------------
int main()
{
	
	cout<<"ETAP 1 - test klasy kredyt"<<endl<<endl;
	{
		kredyt k1(1000,9,5,12,"P 23/2017"), k2(k1), k3;
		
		k3=k2;

		cout<<"KREDYTY:"<<endl;
		cout<<"k1: "<<k1<<endl<<"k2: "<<k2<<endl<<"k3: "<<k3<<endl;

		kredyt k4(500, 3, 2, 20, "P 10/2021");

		k2 = k4;

		cout << "k2=k4" << k2 << endl;

	}
	
	
	cout << "--------------------------------------------------------------" << endl;
	cout<<"ETAP 2 - test klasy kredytF"<<endl<<endl;
	{
		kredytF kF1( 10000, 4., 2, 3, "K 45/2017"), kF2(kF1), kF3;

		kF3 = kF2;

		cout << "KREDYTY \"F\":" << endl;
		cout << "kF1: " << kF1 << endl << "kF2: " << kF2 << endl << "k3: " << kF3 << endl;
		
		kredyt* p = new kredytF(20000, 4., 2, 3, "K 50/2021");
		cout << "*p: " << *p << endl;
		delete p;	//czy poprawne?

	}
		


	/*
	cout << "---------------------------------------------------------------"<<endl;
	cout<<endl<<"ETAP 3"<<endl<<endl;

	const int N = 10;
	kredyt* kredyty[N]={
			 new kredytF( 10000, 3, 2, 3, "K 23/2021"),
			 new kredytF( 1000, 4, 1, 4, "R 15/2021"),
			 new kredyt( 10000, 7.5, 2, 4),
			 new kredytF( 1000, 3, 1, 12, "K 37/2021"),
			 new kredytF( 50000, 4.5, 4, 2),
			 new kredyt( 5000, 5, 2, 4, "R 50/2021"),
			 new kredytF( 1000, 3, 3, 2, "K 35/2021"),
			 new kredyt( 1000, 4, 2, 3, "K 10/2021"),
			 new kredytF( 100, 9, 1, 4, "K 20/2021"),
			 new kredyt( 1000, 7, 2, 3, "P 22/2021")
	};

	wypisz(kredyty, N, "KREDYTY:");
	
	*/

	/*
	cout << "---------------------------------------------------------------" << endl;
	cout<<endl<<"ETAP 4 - sortowanie"<<endl<<endl;

	sortuj(kredyty, N, cmp_wartosc);
	wypisz(kredyty, N, "KREDYTY posortowane wg wartosci:");
	
	sortuj(kredyty, N, cmp_wartosc_info);
	wypisz(kredyty, N, "KREDYTY posortowane wg wartosc kredytu, info:");

	sortuj(kredyty, N);
	wypisz(kredyty, N, "KREDYTY posortowane wg wartosci:");

	
	
	//------------------------------------------------
	cout<<endl<<"USUWAM KREDYTY"<<endl;
	for (int i=0;i<N;i++) delete kredyty[i];
	
	*/

	return 0;
}