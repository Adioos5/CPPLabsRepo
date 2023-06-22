#pragma once
#include <iostream>
#include <string>


//------------------------------------------------------

class Operation
{

private:
	const std::string name; 

protected:
	const int n;	//liczba argumentów dzia³ania

public:
	Operation(int n, const std::string& name);
	virtual ~Operation(){ };

	int N() const { return n; }

	virtual double Result(double* arg ) const = 0;
	virtual Operation* Clone() const = 0;

	virtual void Print(std::ostream& out) const;

	friend std::ostream& operator << (std::ostream& out, const Operation& op);

};
 
//----------------------------------------------------------
class Addition : public Operation
{
public:
	Addition(int n = 2);

	virtual double Result(double* arg) const override;
	virtual Operation* Clone() const override;

};

class Subtraction : public Operation
{
public:
	Subtraction(int n = 2);

	virtual double Result(double* arg) const override;
	virtual Operation* Clone() const override;

};

class Multiplication : public Operation
{
public:
	Multiplication(int n = 2);

	virtual double Result(double* arg) const override;
	virtual Operation* Clone() const override;

};

class Division : public Operation
{

public:
	Division(int n = 2);

	virtual double Result(double* arg) const throw(...) override;
	virtual Operation* Clone() const override;

};

class Power : public Operation 
{
	int p;
public:
	Power(int p = 2);
	virtual double Result(double* arg) const override;
	virtual Operation* Clone() const override;
	virtual void Print(std::ostream& out) const override;

};

//----------------------------------------------------------
