#pragma once
#include "Operation.h"


//-------------------------------------------------------------

class Calculator
{
	double value;		//bie¿¹ca wartoœæ na wyœwietlaczu kalkulatora

	static const int N = 10;
	Operation* operation[N];	//tablica zaprogramowanych operacji kalkulatora
	int n;						//liczba operacji w tablicy (1<=n<=N)

	void Running();

public:
	Calculator();
	~Calculator();

	bool AddOperation(const Operation& op);	//wykonaj kopiê 

	void Start();	//"w³¹czenie" kalkulatora
	
};
