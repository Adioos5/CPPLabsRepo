
#include "Operation.h"
#include "DivisionByZero.h"
using namespace std;
   

Operation::Operation(int n, const string& name): n(n), name(name)
{ }

void Operation::Print(ostream& out) const
{
	out << name << ", number of arguments: " << n;
}

ostream& operator << (ostream& out , const Operation& O)
{
	O.Print(out);
	return out << endl;
}

//----------------------------------------------------------
//implementacja klasy Addition

Addition::Addition(int n): Operation(n, "Addition") {}

double Addition::Result(double* arg) const {
	double x = arg[0];
	for (int i = 1;i < n ;i++) x += arg[i];

	return x;
}

Operation* Addition::Clone() const {
	return new Addition(*this);
}

//----------------------------------------------------------
//implementacja klasy Subtraction
Subtraction::Subtraction(int n) : Operation(n, "Subtraction") {}

double Subtraction::Result(double* arg) const {
	double x = arg[0];
	for (int i = 1;i < n;i++) x -= arg[i];

	return x;
}

Operation* Subtraction::Clone() const {
	return new Subtraction(*this);
}


//----------------------------------------------------------
//implementacja klasy Multiplication
Multiplication::Multiplication(int n) : Operation(n, "Multiplication") {}

double Multiplication::Result(double* arg) const {
	double x = arg[0];
	for (int i = 1;i < n;i++) x *= arg[i];

	return x;
}

Operation* Multiplication::Clone() const {
	return new Multiplication(*this);
}


//----------------------------------------------------------
//implementacja klasy Division
Division::Division(int n) : Operation(n, "Division") {}

double Division::Result(double* arg) const throw(...) {
	double x = arg[0];

	for (int i = 1;i < n;i++) {
		if (arg[i] == 0) throw DivisionByZero(i);
		x /= arg[i];
	}
	return x;
}

Operation* Division::Clone() const {
	return new Division(*this);
}


//----------------------------------------------------------
//implementacja klasy Power
Power::Power(int p) : Operation(1, "Power"), p(p) {}

double Power::Result(double* arg) const throw(...) {
	double x = arg[0];

	for (int i = 1;i < p;i++) x *= arg[0];

	return x;
}

Operation* Power::Clone() const {
	return new Power(*this);
}

void Power::Print(std::ostream& out) const {
	Operation::Print(out);
	out << ", power p=" << p;
}

//----------------------------------------------------------




