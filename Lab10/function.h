#pragma once

#include <iostream>

template <typename T = double>
class Function
{

public:
	Function() = default;
	Function(const Function&) = delete;
	Function& operator=(const Function&) = delete;

	virtual T value(T x) const = 0;
	virtual T prim(T x) const = 0;

	virtual ~Function() { }
};

//---------------------------------------------------
template <typename T>
class Const :public Function<T>
{
	T val;
public:
	Const(T val) : val(val) {}
	
	virtual T value(T x) const override { return val; }
	virtual T prim(T x) const override { return 0; }

};

template <typename T>
class X :public Function<T>
{
public:

	virtual T value(T x) const override { return x; }
	virtual T prim(T x) const override { return 1; }



};

template <typename T>
class Plus : public Function<T>
{
	Function<T>* f1, * f2;

public:

	Plus(Function<T>* f1, Function<T>* f2) : f1(f1), f2(f2) {}
	~Plus() { delete f1; delete f2; }
	virtual T value(T x) const override { return f1->value(x) + f2->value(x); }
	virtual T prim(T x) const override { return f1->prim(x) + f2->prim(x); }


};

template <typename T>
class Minus : public Function<T>
{
	Function<T>* f1, * f2;

public:

	Minus(Function<T>* f1, Function<T>* f2) : f1(f1), f2(f2) {}
	~Minus() { delete f1; delete f2; }
	virtual T value(T x) const override { return f1->value(x) - f2->value(x); }
	virtual T prim(T x) const override { return f1->prim(x) - f2->prim(x); }


};

template <typename T>
class Iloczyn : public Function<T>
{
	Function<T>* f1, * f2;

public:

	Iloczyn(Function<T>* f1, Function<T>* f2) : f1(f1), f2(f2) {}
	~Iloczyn() { delete f1; delete f2; }
	virtual T value(T x) const override { return f1->value(x) * f2->value(x); }
	virtual T prim(T x) const override { return (f1->prim(x) * f2->value(x)) + (f1->value(x) * f2->prim(x)); }



};

//--------------------------------------------------------------------------

template <typename T>
class Wielomian : public Function<T>
{
	Function<T>* w;

public:
	Wielomian() : w(nullptr) {}
	~Wielomian() { delete w; }

	virtual T value(T x) const override { return w->value(x); }
	virtual T prim(T x) const override { return w->prim(x); }

	void generuj1(T* tab, int n) {
		w = new Const<T>(tab[n - 1]);
		for (int i = n - 2;i >= 0;i--) {
			w = new Plus<T>(new Iloczyn<T>(w, new X<T>()), new Const<T>(tab[i]));
		}
	}

	void generuj2(T* tab, int n) {
		w = new Minus<T>(new X<T>(), new Const<T>(tab[0]));
		for (int i = 1;i < n;i++) {
			w = new Iloczyn<T>(w, new Minus<T>(new X<T>(), new Const<T>(tab[i])));
		}
	}
	
	
};

template<typename T>
T pierwiastek(const Function<T>& f, T x, int& it) throw(...) {
	double eps = pow(10,-15);
	int max_it = 50;

	it = 0;

	while (it++ < max_it) {
		if (abs(f.prim(x)) < eps)
			throw "Brak zbieznosci.";
		x = x - f.value(x) / f.prim(x);
		if (abs(f.value(x)) < eps)
			return x;
	}

	throw "Brak zbieznosci.";
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


