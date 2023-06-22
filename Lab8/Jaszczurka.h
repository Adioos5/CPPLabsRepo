#pragma once
#include <iostream> 
#include <string>
using namespace std;

class Jaszczurka
{	
protected:
	int punktyZycia = 5;
	int sila_ataku = 2;
	int poziom_ochrony = 1;

public:
	virtual ~Jaszczurka() {};
	bool czyZyje() const { return punktyZycia > 0; }
	int jaki_poziom_ochrony() const { return poziom_ochrony; }

	virtual int wykonaj_atak(int poziom_ochrony_przeciwnika) const = 0;
	void przyjmij_atak(int obrazenia);

	virtual void info(ostream&) const = 0;
	friend ostream& operator<<(ostream&, const Jaszczurka&);
};

class Jaszczurka_Zwyczjna : public Jaszczurka
{
protected:
	int ugryzienie() const;
public:
	virtual int wykonaj_atak(int poziom_ochrony_przeciwnika) const override;
	virtual void info(ostream&) const override;
};

class Jaszczurka_Elektryczna : public Jaszczurka_Zwyczjna
{
	static int ile_jaszczurek;
protected:
	int porazenie() const;
public:
	Jaszczurka_Elektryczna();
	~Jaszczurka_Elektryczna();

	virtual int wykonaj_atak(int poziom_ochrony_przeciwnika) const override;
	virtual void info(ostream&) const override;
};