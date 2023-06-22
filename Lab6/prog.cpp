			
#include <iostream>
using namespace std;
#include <ctime>

#include "kartka.h"
#include "szlaczek.h"


int main()
{
	const int M=40;		// wymiar kartki MxM

	int kolor_pisaka=kartka::ZOLTY;	
	srand((unsigned)time(NULL));
	
	kartka k(M);	//kartka z samym jajem
	
	int	w=0;
	do  {
				cout<<k;	//zobaczmy obrazek

                cout<<"\nMENU:"<<endl;
				cout<<"1 - SZLACZEK"<<endl;
				cout<<"2 - NOWA KARTKA Z JAJEM"<<endl;
                cout<<"3 - UNDO"<<endl;
                cout<<"0 - KONIEC"<<endl;

                cout<<"Podaj numer opcji: ";
                cin>>w;

                switch (w)
                {
					case 1:
					
						for (int i=0;i<k.size()/5;i++) // kilka szlaczków w ustalonym kolorze
							k.dodaj(szlaczek(rand()%k.size(),element(kolor_pisaka)));
							
						kolor_pisaka--;
						if (kolor_pisaka<kartka::NIEBIESKI) kolor_pisaka=kartka::ZOLTY;

						k.zapisz();		//etap 3
						
						break;
                   
					case 2: // nowa kartka (byæ mo¿e z nowym rozmiarem)
						{
							int m;

							do {
								cout << "Podaj wymiar nowego obrazka ("<<M<<" <= m <= "<<2*M<<") m=";
								cin >> m;
							} 
							while (m<M && m>2*M);


							k.resetuj(m);	//kolor jaja domyœlny
						}
						break;

                    case 3:
						k.cofnij();		//etap 3
						break;

                }//switch

                
            } while (w != 0);
 
	return 0;
}
			