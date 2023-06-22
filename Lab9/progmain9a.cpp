#include <iostream>
using namespace std;
   
#include "Calculator.h"

int main()
{
	cout << "ETAP 1 --------------------------" << endl;
	
	// definiujemy operacje dla kalkulatora
	Addition		A2, A3(3);
	Subtraction		S2, S3(3);
	Multiplication	M2, M4(4);
	Division		D2, D4(4);
	Power			P2, P3(3); 

	//wykonaj przyk³adowe testy
	double arg[] = { 18,3,2,2 };
	
	cout << "A2: " << A2 << "RESULT= " << A2.Result(arg) << endl;
	cout << "A3: " << A3 << "RESULT= " << A3.Result(arg) << endl;
	cout << "S2: " << S2 << "RESULT= " << S2.Result(arg) << endl;
	cout << "S3: " << S3 << "RESULT= " << S3.Result(arg) << endl;
	cout << "M2: " << M2 << "RESULT= " << M2.Result(arg) << endl;
	cout << "M4: " << M4 << "RESULT= " << M4.Result(arg) << endl;
	cout << "D2: " << D2 << "RESULT= " << D2.Result(arg) << endl;
	cout << "D4: " << D4 << "RESULT= " << D4.Result(arg) << endl;
	cout << "P2: " << P2 << "RESULT= " << P2.Result(arg) << endl;
	cout << "P3: " << P3 << "RESULT= " << P3.Result(arg) << endl;
	

	cout << "ETAP 2 --------------------------" << endl;
	
	Calculator calculator;

	//programujemy kalkulator
	calculator.AddOperation(Addition(2));
	calculator.AddOperation(Addition(3));
	calculator.AddOperation(Subtraction(2));
	calculator.AddOperation(Multiplication(2));
	calculator.AddOperation(Multiplication(3));
	calculator.AddOperation(Division(2));
	calculator.AddOperation(Division(3));
	calculator.AddOperation(Division(4));
	calculator.AddOperation(Power(2));
	calculator.AddOperation(Power(3));
	calculator.AddOperation(Power(4));		//to ju¿ o jeden za du¿o...


	calculator.Start();
	

	cout << endl << endl;
	
	return 0;
}