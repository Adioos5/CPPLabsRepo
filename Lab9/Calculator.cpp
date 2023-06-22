
#include <iostream>
using namespace std;
#include "Calculator.h"
#include "DivisionByZero.h"
    
//-----------------------------------------------------
//uzupe³nij implementacjê brakuj¹cych sk³adowych klasy Calculator
Calculator::Calculator() : value(0), n(0) {
	for (int i = 0; i < N;i++) {
		operation[i] = nullptr;
	}
}

Calculator::~Calculator() {
	for (int i = 0; i < N;i++) {
		delete operation[i];
	}
}

bool Calculator::AddOperation(const Operation& op) {
	if (n < N) {
		operation[n++] = op.Clone();
		return true;
	}

	return false;
}

void Calculator::Running() {

	cout << "Operations:\n";

	for (int i = 0;i < n;i++) {
		cout << i << ". " << *operation[i];
	}

	int choice;
	do {
		cin >> choice;
	} while (choice > n-1 || choice < 0);

	double* data = new (nothrow) double[operation[choice]->N()];
	data[0] = value;

	if (operation[choice]->N() > 1) {
		cout << "input missing " << operation[choice]->N() - 1 << " argument (arguments)\n";
		for (int i = 1;i < operation[choice]->N();i++)
			cin >> data[i];
	}

	try {
		value = operation[choice]->Result(data);
	}
	catch (const DivisionByZero& e) {
		e.Message();
	}

	delete[] data;

}

//-----------------------------------------------------

void Calculator::Start()
{
	int what;
	while(true)
	{
		cout << "VALUE: " << value << endl;
		
		cout << "MENU" << std::endl;
		cout << "1 - Set new VALUE" << std::endl;
		cout << "2 - Reset (zero)" << std::endl;
		cout << "3 - Select Operation" << std::endl;
		cout << "4 - END" << std::endl;

		cin >> what;
		switch(what)
		{
		case 1:
			{
				double k;
				cout << "Input new VALUE: " << endl;
				cin >> k;
				value = k;
			}
			break;
		case 2:
			value = 0;
			break;
		case 3:
			Running();
			break;
		case 4:
			cout << "END ... " << endl;
			return;
		default:
			cout << "Bad selection" << endl;
		}
	}
}
