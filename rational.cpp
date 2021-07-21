#include<iostream>
#include "rational.h"
#include"Polynomial.h"

using namespace std;

rational::rational()
{
	pNom.setCoeff(0, 0.0);
	pDenom.setCoeff(0, 1.0);
};

rational::rational(Polynomial& p1, Polynomial& p2) :pNom(p1), pDenom(p2)
{
};
rational::rational(const rational & r) : pNom(r.pNom), pDenom(r.pDenom)
{
};
void rational::print()
{
	cout << pNom << "--------------------------" << endl;
	cout << pDenom;
}
Polynomial rational::getNom()
{
	return pNom;
}
Polynomial rational::getDenom()
{
	return pDenom;
}
ostream & operator << (ostream & cout, const rational & r)
{
	cout << r.pNom << "--------------------------" << endl;
	cout << r.pDenom;
	return cout;
}
rational operator * (const rational &rhs, const rational &lhs)
{
	Polynomial resNm, resDenom;
	resNm = rhs.pNom*lhs.pNom;
	resDenom = rhs.pDenom*lhs.pDenom;
	rational res(resNm, resDenom);
	return res;
}
rational operator + (const rational &rhs, const rational &lhs)
{
	Polynomial resNm, resDenom;
	resNm = rhs.pNom*lhs.pDenom + lhs.pNom*rhs.pDenom;
	resDenom = lhs.pDenom*rhs.pDenom;
	rational res(resNm, resDenom);
	return res;
}
rational::~rational()
{
}
rational& rational::operator=(const  rational & rhs)
{
	this->pNom = rhs.pNom;
	this->pDenom = rhs.pDenom;
	return *this;
}
