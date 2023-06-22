#pragma once
#include <iostream>
#include <exception>

using namespace std;

class DivisionByZero : exception{
	int idx;

public:
	DivisionByZero(int i) : idx(i) {}
	void Message() const { cout << "Bad argument i=" << idx; }
};