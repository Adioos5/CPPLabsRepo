#pragma once
#include <iostream>
#include <Windows.h>

class element	//GOTOWA
{
		static const char znak='*';
		int kolor;

public:
	
	element(int kolor = 0, char znak = '*') : kolor{ kolor }
	{}

	friend std::ostream& operator<<(std::ostream& out, const element& e)
	{	
		//wypisuje znak w podanym kolorze
		HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hconsole,e.kolor+(15<<4));
		out<<e.znak;
		SetConsoleTextAttribute(hconsole,15);

		return out;
	}
};

