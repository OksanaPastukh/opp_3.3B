#include "Money.h"
#include <sstream>

Money::Money() :Pair()
{}
Money::Money(long h, unsigned char k):Pair(h, k)
{}
Money::Money(const Money& m):Pair(m)
{}
double Money::MoneyToDoble() const
{
	return (double)GetHryvnia() + GetKopiyku() / 100.0;
}
void Money::DoubleToMoney(double value)
{
	SetHryvnia(trunc(value));
	SetKopiyku(trunc(abs((value - GetHryvnia())) * 100));
}
Money& Money::operator = (const Money& m)
{
	Pair::operator=(m);
	return *this;
}

istream& operator >> (istream& in, Money& m)
{
	double value;
	long hr;
	unsigned char kop;
	cout << " Summa = "; in >> value;
	do
	{
		hr = floor(value);
		kop = round((value - hr) * 100);
	} while (!(m.SetHryvnia(hr) && m.SetKopiyku(kop)));
	return in;
}
Money::operator string () const
{
	stringstream ss;
	ss << " Summa = " << GetHryvnia() << "," << (int)GetKopiyku() << " hrn " << endl;
	return ss.str();
}
ostream& operator << (ostream& out, const Money& p)
{
	out << string(p);
	return out;
}
Money operator - (const Money& x, const Money& y)
{
	Money result;
	result.DoubleToMoney(x.MoneyToDoble() - y.MoneyToDoble());
	return result;
}
Money operator * (const Money& x, const Money& y)
{
	Money result;
	result.DoubleToMoney(x.MoneyToDoble() * y.MoneyToDoble());
	return result;
}
bool operator < (const Money& x, const Money& y)
{
	return x.MoneyToDoble() < y.MoneyToDoble();
}
bool operator > (const Money& x, const Money& y)
{
	return (Pair)x > (Pair)y;
}
bool operator == (const Money& x, const Money& y)
{
	return x.MoneyToDoble() == y.MoneyToDoble();
}