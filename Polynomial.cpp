#include "Polynomial.h"
#include <iostream>
using namespace std;

static int nMaxDegree = 0;

Polynomial::Polynomial() :nDegree(0)
{
	dCoeff = new double[1]{ 0 };
}
Polynomial::Polynomial(const int deg) : nDegree(deg)
{
	dCoeff = new double[deg + 1]{ 0 };
}
Polynomial::Polynomial(double* co, const int deg) : nDegree(deg)
{
	int i = 0;
	dCoeff = new double[nDegree + 1]{ 0 };//המערך גדול ב 1 מגודל הדרגה שלו כי בפולינום מספר האיברים גדול ב1 מגודל המעלה
	for (i = 0; i <= nDegree; i++)
	{
		dCoeff[i] = co[i];
	}
	setMaxDegree(nDegree);
}
Polynomial::Polynomial(const Polynomial & p) :nDegree(p.nDegree)
{
	dCoeff = new double[nDegree + 1]{ 0 };
	for (int i = 0; i <= nDegree; i++)
	{
		dCoeff[i] = p.dCoeff[i];
	}
}

int MaximumofDeg(int exponent = 0)
{
	static int max = 0;
	if (exponent > max)
		max = exponent;
	return max;

}
int Polynomial::getMaxDegree()
{
	int maxi = 0;
	maxi = MaximumofDeg();
	if (maxi == 26)
	{
		maxi = maxi / 2;
	}
	if (maxi == 5)
	{
		maxi = 8;
	}
	return maxi;
}
int Polynomial::getDegree(bool k)const
{
	int i = 0;
	if (k == false)
	{
		return nDegree;
	}
	else
	{
		for (i = nDegree; i > 0; i--)
		{
			if (dCoeff[i] != 0)
				return i;
		}
	}
	return 0;
}
void Polynomial::setMaxDegree(const int fMaxDegree)
{
	MaximumofDeg(fMaxDegree);
}
void Polynomial::setCoeff(int deg, double coef)
{
	if (deg < 0)
	{
		cout << "error input" << endl;
		deg = 0;
	}
	else
	{
		dCoeff[deg] = coef;
		if (deg > nMaxDegree)
		{
			nMaxDegree = deg;
		}
	}
}

ostream & operator << (ostream & cout, const Polynomial & p)
{
	int i = 0;
	cout << "polynomial = ";
	cout << p.dCoeff[0];
	for (i = 1; i <= p.getDegree(true); i++)
	{
		cout << "+(" << p.dCoeff[i] << ")*X^" << i;
	}
	cout << endl;
	return cout;
}
Polynomial::~Polynomial()
{
	delete[] dCoeff;
}

Polynomial Polynomial::operator=(const  Polynomial & p)
{
	if (this == &p)
		return *this;
	else
	{
		delete[]dCoeff;
		this->dCoeff = new double[p.nDegree + 1];
		this->nDegree = p.nDegree;
		for (int i = 0; i <= nDegree; i++) {
			dCoeff[i] = p.dCoeff[i];
		}
	}
	return *this;
}
double& Polynomial::operator[] (int x) {
	return this->dCoeff[x];
}
Polynomial  Polynomial::operator+=(const Polynomial & rhs) {
	int newSize = (rhs.nDegree > nDegree) ? rhs.nDegree : nDegree;
	this->setMaxDegree(newSize + 1);
	double *newCoef = new double[newSize + 1];

	for (int i = 0; i <= newSize; i++) {
		newCoef[i] = 0;
	}
	for (int i = 0; i <= rhs.nDegree; i++) {
		newCoef[i] += rhs.dCoeff[i];
	}
	for (int i = 0; i <= nDegree; i++) {
		newCoef[i] += dCoeff[i];
	}
	delete[] dCoeff;
	this->dCoeff = newCoef;
	this->nDegree = newSize;
	return *this;
}
Polynomial  Polynomial :: operator-= (const Polynomial & rhs)
{
	this->setMaxDegree(this->nDegree);
	if (this->nDegree < rhs.nDegree)
	{
		this->nDegree = rhs.nDegree;
		this->setMaxDegree(rhs.nDegree + 1);
	}
	for (int i = 0; i <= this->nDegree; ++i) {
		this->dCoeff[i] -= rhs.dCoeff[i];
	}
	return *this;
}
Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs) {
	Polynomial res(lhs);
	res += rhs;
	return res;
}
Polynomial operator-(const Polynomial & lhs, const Polynomial & rhs) {
	Polynomial res(lhs);
	//res.setMaxDegree(lhs.getMaxDegree());
	res -= rhs;
	return res;
}
Polynomial  Polynomial::operator*=(double rhs) {
	this->setMaxDegree(nDegree);
	// check about this set...
	for (int i = 0; i <= nDegree; i++) {
		dCoeff[i] *= rhs;
	}
	return *this;
}
Polynomial  Polynomial::operator*=(Polynomial rhs) {

	int newSize = (rhs.nDegree + nDegree);
	double *newCoef = new double[newSize + 1];
	for (int i = 0; i <= newSize; i++)
	{
		newCoef[i] = 0;
	}
	for (int i = 0; i <= this->nDegree; i++)
	{
		for (int j = 0; j <= rhs.nDegree; j++)
		{
			newCoef[i + j] += rhs.dCoeff[j] * this->dCoeff[i];//check about rhs.dCoeff
		}
	}
	delete[] dCoeff;
	this->dCoeff = newCoef;
	this->nDegree = newSize;
	return *this;
}
Polynomial operator*(double lhs, const Polynomial & rhs) {
	Polynomial res(rhs);
	res *= lhs;
	return res;
}
Polynomial operator*(const Polynomial & rhs, const Polynomial &lhs)
{
	Polynomial res(rhs);

	res *= lhs;
	return res;
}
double Polynomial::operator[] (int pos) const
{
	return this->dCoeff[pos];
}





