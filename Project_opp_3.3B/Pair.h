#pragma once
class Pair
{
	long hryvnia;
	unsigned char kopiyku;
public:
	Pair();
	Pair(long, unsigned char);
	Pair(const Pair&);

	bool SetHryvnia(long);
	bool SetKopiyku(unsigned char);
	long GetHryvnia() const { return hryvnia; }
	unsigned char GetKopiyku() const { return kopiyku; }
	Pair& operator = (const Pair&);
	friend bool operator > (const Pair&, const Pair&);

};

