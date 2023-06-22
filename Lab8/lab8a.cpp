#include <iostream> 
#include "Jaszczurka.h"
#include "Zaklecie.h"
#include "Bron.h"
#include "Zbroja.h"
#include "Artefakt.h"
#include "Mag.h"
using namespace std;

void spotkanie(Jaszczurka_Elektryczna* jaszczurka, Mag* mag);

int main()
{
	cout << endl << "-------------  ETAP 1 (2,5 pkt) --------------" << endl;
	
	{
	Jaszczurka_Zwyczjna jaszczurka;
	Jaszczurka_Elektryczna jaszczurka_elektryczna;

	cout << jaszczurka << jaszczurka_elektryczna << endl;

	cout << "Atakuje " << jaszczurka << "- trafia i zadaje " << jaszczurka.wykonaj_atak(1) << " obrazen" << endl;
	cout << "Atakuje " << jaszczurka << "- nie trafia i zadaje " << jaszczurka.wykonaj_atak(8) << " obrazen" << endl;
	cout << "Broni sie " << jaszczurka << "- trafiona za 20 obrazen!" << endl;
	jaszczurka.przyjmij_atak(20);
	if (!jaszczurka.czyZyje()) cout << jaszczurka << "- zabita!!! Huraaaa!!!" << endl << endl;

	cout << "Atakuje " << jaszczurka_elektryczna << "- trafia i zadaje " << jaszczurka_elektryczna.wykonaj_atak(1) << " obrazen" << endl;
	cout << "Atakuje " << jaszczurka_elektryczna << "- nie trafia i zadaje " << jaszczurka_elektryczna.wykonaj_atak(8) << " obrazen" << endl;
	Jaszczurka_Elektryczna jaszczurka_elektryczna2, jaszczurka_elektryczna3;
	cout << "Kolejne 2 jaszczurki dolaczaja do walki (sa juz 3 i wspolnie raza pradem)" << endl;
	cout << "Atakuje " << jaszczurka_elektryczna << "- (zawsze trafia) - trafia i zadaje " << jaszczurka_elektryczna.wykonaj_atak(100) << " obrazen" << endl;
	cout << "Broni sie " << jaszczurka_elektryczna << "- trafiona za 20 obrazen!" << endl;
	jaszczurka_elektryczna.przyjmij_atak(20);
	if (!jaszczurka_elektryczna.czyZyje()) cout << jaszczurka_elektryczna << "- zabita!!! Huraaaa!!!" << endl << endl;
	}
	
	cout << endl << "-------------  ETAP 2 (2 pkt) --------------" << endl;
	
	ZaklecieOfensywne zo("Widmowe Ostrza", "zadje 2 obrazenia", 1, 2);
	ZaklecieDefensywne zd("Leczniczy dotyk", "leczy 4 obrazenia", 1, 4);

	cout << zo << "Zadane obrazenia: " << zo.wypowiedz_zaklecie() << endl;
	cout << zd << "Odzyskane punkty zycia: " << zd.wypowiedz_zaklecie() << endl;
	
	cout << endl << "-------------  ETAP 3  (2 pkt) --------------" << endl;
	
	Bron* kij = new Bron("Kij", "klasyczny kij", 5);

	cout << *kij;
	cout << "Atak kijem - zadano " << kij->zadaj_obrazenia() << " obrazenia" << endl;

	Zbroja* kolczuga = new Zbroja("Kolczuga", "klasyczna kolczuga", 3);

	cout << *kolczuga;
	cout << "Noszenie kolczugi poprawia obrone o " << kolczuga->wykorzystaj_ochrone() << " punkty" << endl;

	Artefakt* amulet = new Artefakt("Amulet zielonego kamienia", "amulet zwiekszajacy poziom ochrony", Artefakt::typ_artefaktu::MODYFIKUJACY_OCHRONE, 3);

	cout << *amulet;
	cout << "Amulet na szyi poprawia poziom ochrony o " << amulet->wykorzystaj_artefakt() << " punkty" << endl;

	delete kij;
	delete kolczuga;
	delete amulet;
	
	cout << endl << "-------------  ETAP 4  (1,5 pkt) --------------" << endl;
	
	Mag Sleibhin("Sleibhin", 30, 5, 3, 3);
	cout << Sleibhin << endl;

	cout << "Sleibhin przygotowuje sie ...  zaklada amulet, bierze bron, medytuje ..." << endl << endl;
	Sleibhin.przygotowanie();
	cout << Sleibhin << endl;
	
	cout << endl << "-------------  ETAP 5  (2 pkt) --------------" << endl;
	
	cout << "Sleibhin - atakuje i rzuca zaklecie (Widmowe Ostrza; po uzyciu bedzie ono niedostepne) " << Sleibhin.wykonaj_atak(1) << " obrazen" << endl;
	cout << Sleibhin << endl;
	cout << "Broni sie Sleibhin - trafiony za 25 obrazen!" << endl;
	Sleibhin.przyjmij_atak(25);
	cout << Sleibhin << endl;
	cout << "Atakuje Sleibhin - teraz sie leczy (<10 PZ) zakleciem (Leczniczy dotyk; po uzyciu bedzie ono niedostepne) wiec zadaje " << Sleibhin.wykonaj_atak(1) << " obrazen" << endl;
	cout << Sleibhin << endl;
	cout << "Broni sie Sleibhin - trafiony za 5 obrazen!" << endl;
	Sleibhin.przyjmij_atak(5);
	cout << Sleibhin << endl;
	cout << "Atakuje Sleibhin - znowu sie leczy (<10 PZ) zakleciem (Powiew leczenia; po uzyciu bedzie ono niedostepne) wiec zadaje " << Sleibhin.wykonaj_atak(1) << " obrazen" << endl;
	cout << Sleibhin << endl;
	cout << "Sleibhin - atakuje i rzuca zaklecie (Ognista strzala; po uzyciu bedzie ono niedostepne) " << Sleibhin.wykonaj_atak(1) << " obrazen" << endl;
	cout << Sleibhin << endl;
	cout << "Broni sie Sleibhin - trafiony za 5 obrazen!" << endl;
	Sleibhin.przyjmij_atak(5);
	cout << Sleibhin << endl;
	cout << "Atakuje Sleibhin - chcialby sie leczyc (<10 PZ) ale nie ma juz zaklec ktore moze uzyc (pozostale dostepne maja za wysoki poziom), wiec atakuje ale zaklec ofensywnych ktore moze uzyc takze nie posiada; ostatecznie atakuje bronia, trafia i zadaje " << Sleibhin.wykonaj_atak(1) << " obrazenia" << endl;
	cout << Sleibhin << endl;
	
	cout << endl << "-------------  Symulacja --------------" << endl;
	
	Mag Summerled("Summerled", 30, 5, 3, 3);
	Jaszczurka_Elektryczna potwor;

	Summerled.przygotowanie();
	spotkanie(&potwor, &Summerled);
	
	return 0;
}


void spotkanie(Jaszczurka_Elektryczna* jaszczurka, Mag* mag)
{
	int i = 1;
	Jaszczurka_Elektryczna dodatkowa1, dodatkowa2;
	cout << "Witaj ! Musisz ocalic swiat przed atakiem Jaszczurek" << endl;
	while (jaszczurka->czyZyje() && mag->czyZyje())
	{
		cout << " ********** RUNDA " << i++ << " **********" << endl;
		cout << *mag << endl << *jaszczurka << endl;
		// atakuje mag
		jaszczurka->przyjmij_atak(mag->wykonaj_atak(jaszczurka->jaki_poziom_ochrony()));
		if (jaszczurka->czyZyje()) // atakuje jaszczurka
			mag->przyjmij_atak(jaszczurka->wykonaj_atak(mag->jaki_poziom_ochrony()));
	}
	cout << " ********** KONIEC WALKI **********" << endl;
	cout << *mag << endl << *jaszczurka << endl;
	if (jaszczurka->czyZyje())
		cout << "Polegles na polu chwaly" << endl;
	else
		cout << "Zwyciezyles !!! Swiat uratowany !! Dobrze, ze poszedles na nuki :)" << endl << endl;
}