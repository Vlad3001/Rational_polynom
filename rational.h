#pragma once
#include"Rational.h"
#include"Polynomial.h"
#include<iostream>
using namespace std;
class rational
{
	friend ostream & operator << (ostream &, const rational &);
	friend rational operator * (const rational &, const  rational &);
	friend rational operator + (const rational &, const  rational &);
public:
	rational();
	rational(Polynomial&, Polynomial&);
	rational(const rational & r);
	~rational();
	void print();
	Polynomial getNom();
	Polynomial getDenom();
	rational& operator=(const  rational &);
private:
	Polynomial pNom;
	Polynomial pDenom;
};
