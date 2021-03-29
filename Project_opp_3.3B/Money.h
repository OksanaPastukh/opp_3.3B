#pragma once
#include "Pair.h"
#include <iostream>
#include <string>
using namespace std;

class Money:public Pair
{
private:
	double MoneyToDoble() const;
	void DoubleToMoney(double);
public:
	Money();
	Money(long, unsigned char);
	Money(const Money&);
	friend istream& operator >> (istream&, Money&);
	Money& operator = (const Money&);
	operator string() const;
	friend ostream& operator << (ostream&, const Money&);
	friend Money operator - (const Money&, const Money&);
	friend Money operator * (const Money&, const Money&);
	friend bool operator <(const Money&, const Money&);
	friend bool operator >(const Money&, const Money&);
	friend bool operator == (const Money&, const Money&);

};

