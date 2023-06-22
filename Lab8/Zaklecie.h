#pragma once
#include <iostream> 
#include <string>
using namespace std;

class Mag;

class Zaklecie
{
	friend class Mag;
protected:
	string nazwa;
	string opis;
	int poziom_trudnosci;
	bool dostepnosc = false;
public:
	Zaklecie(string nazwa, string opis, int poziom_trudnosci);
	virtual ~Zaklecie() {};
	virtual int wypowiedz_zaklecie() = 0;

	virtual void info(ostream&) const;
	friend ostream& operator<<(ostream&, const Zaklecie&);

};

class ZaklecieOfensywne : public Zaklecie
{
protected:
	int obrazenia;
public:
	ZaklecieOfensywne(string nazwa, string opis, int poziom_trudnosci, int obrazenia);

	virtual int wypowiedz_zaklecie() override;
	virtual void info(ostream&) const override;
};

class ZaklecieDefensywne : public Zaklecie
{
protected:
	int odzyskane_punkty_zycia;
public:
	ZaklecieDefensywne(string nazwa, string opis, int poziom_trudnosci, int odzyskane_punkty_zycia);

	virtual int wypowiedz_zaklecie() override;
	virtual void info(ostream&) const override;
};

