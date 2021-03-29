#include "Pair.h"
Pair::Pair()
{
	hryvnia = 0;
	kopiyku = 0;
}
Pair::Pair(long h, unsigned char k)
{
	SetHryvnia(h);
	SetKopiyku(k);
}
Pair::Pair(const Pair& m)
{
	hryvnia = m.hryvnia;
	kopiyku = m.kopiyku;
}
bool Pair::SetHryvnia(long value)
{
	if (value >= 0)
	{
		hryvnia = value;
		return true;
	}
	else
	{
		return false;
	}
}
bool Pair::SetKopiyku(unsigned char value)
{
	if (value >= 0 && value < 100)
	{
		kopiyku = value;
		return true;
	}
	else
	{
		return false;
	}
}
Pair& Pair::operator = (const Pair& m)
{
	hryvnia = m.hryvnia;
	kopiyku = m.kopiyku;
	return *this;
}
bool operator > (const Pair& x, const Pair& y)
{
	bool result = false;
	if (x.hryvnia > y.hryvnia)
	{
		result = true;
	}
	else if(x.hryvnia == y.hryvnia && x.kopiyku > y.kopiyku)
	{
		result = true;
	}
	return result;
}