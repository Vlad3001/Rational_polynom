#pragma once
#include<iostream>
using namespace std;


class Polynomial
{
	friend ostream & operator << (ostream &, const Polynomial &);
	friend Polynomial operator+(const Polynomial &, const Polynomial &);
	friend Polynomial operator-(const Polynomial &, const Polynomial &);
	friend Polynomial operator*(double, const Polynomial &);
	friend Polynomial operator*(const Polynomial &, const Polynomial &);
public:
	Polynomial(double*, const int);
	Polynomial();
	Polynomial(const int);
	Polynomial(const Polynomial&);
	static int getMaxDegree();
	int getDegree(bool)const;
	void setMaxDegree(const int);
	void setCoeff(int, double);
	Polynomial operator=(const Polynomial &);
	double& operator[] (int x);
	Polynomial operator+= (const Polynomial &);
	Polynomial operator-= (const Polynomial &);
	Polynomial operator*= (double);
	Polynomial operator*=(Polynomial);
	double operator[] (int) const;
	~Polynomial();

private:
	int nDegree;
	double* dCoeff = { 0 };

};






