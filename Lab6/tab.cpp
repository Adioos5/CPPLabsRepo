#include <iostream>
using namespace std;
#include "tab.h"
#include "element.h"


void tab::init(int m)
{
	this->m = m;
	t = new (nothrow) element[m * m];
	if (!t)  m = 0;
}

void tab::wypelnij(const element& el, const element* t)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			(*this)(i, j) = t? t[i*m+j] : el; 	
}

void tab::zwolnij()
{
	delete[] t;
	t = nullptr;
	m = 0;
}

tab::tab() :t{ nullptr }, m{ 0 }
{ }

tab::tab(int m, const element& el) : m{ m }
{
	init(m);
	wypelnij(el);
}

tab::tab(const tab& t)
{
	init(t.m);
	wypelnij(element(0),t.t);
}

tab& tab::operator=(const tab& t)
{
	if (this != &t)
	{
		if (m != t.m)
		{
			zwolnij();
			init(t.m);
		}

		wypelnij(element(0), t.t);
	}

	return *this;
}

int tab::size() const { return m; }

element& tab::operator()(int i, int j) { return t[i * m + j]; }
const element& tab::operator()(int i, int j) const { return t[i * m + j]; }

tab::~tab()
{
	zwolnij();
}




