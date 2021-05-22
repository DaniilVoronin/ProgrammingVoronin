#include "Pair.h"

Pair::Pair(const int first, const int second) : first(first), second(second){}

void Pair::setFirst(const int t)
{
	this->first = t;
}

void Pair::setSecond(const int t)
{
	this->second = t;
}

int Pair::getFirst() const
{
	return this->first;
}

int Pair::getSecond() const
{
	return this->second;
}

bool operator>(const Pair& p1, const Pair& p2)
{
	return (p1.getFirst() > p2.getFirst()) ? (true) : ((p1.getFirst() == p2.getFirst()) ? (p1.getSecond() > p2.getSecond()) : (false));
}

bool operator<(const Pair& p1, const Pair& p2)
{
	return (p1.getFirst() < p2.getFirst()) ? (true) : ((p1.getFirst() == p2.getFirst()) ? (p1.getSecond() < p2.getSecond()) : (false));
}

bool operator==(const Pair& p1, const Pair& p2)
{
	return (p1.getFirst() == p2.getFirst() & p1.getSecond() == p2.getSecond()) ? (true) : (false);
}

bool operator!=(const Pair& p1, const Pair& p2)
{
	return (p1.getFirst() != p2.getFirst()) ? (true) : (p1.getSecond() != p2.getSecond());
}

std::istream& operator>>(std::istream& in, Pair& p)
{
	int first, second;
	in >> first >> second;
	p = Pair(first, second);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Pair& p)
{
	out << p.getFirst() << ", " << p.getSecond();
	return out;
}

bool operator>(const Fraction& f1, const Fraction& f2)
{
	if ((f1.getIntPart() >= 0) | (f2.getIntPart() >= 0)) 
		return (f1.getIntPart() > f2.getIntPart()) ? (true) : ((f1.getIntPart() == f2.getIntPart()) ? (f1.getMantis() > f2.getMantis()) : (false));
	else 
		return (f1.getIntPart() > f2.getIntPart()) ? (true) : ((f1.getIntPart() == f2.getIntPart()) ? (f1.getMantis() < f2.getMantis()) : (true));
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
	if ((f1.getIntPart() >= 0) | (f2.getIntPart() >= 0))
		return (f1.getIntPart() < f2.getIntPart()) ? (true) : ((f1.getIntPart() == f2.getIntPart()) ? (f1.getMantis() < f2.getMantis()) : (false));
	else
		return (f1.getIntPart() < f2.getIntPart()) ? (true) : ((f1.getIntPart() == f2.getIntPart()) ? (f1.getMantis() > f2.getMantis()) : (true));
}

bool operator==(const Fraction& f1, const Fraction& f2)
{
	return (f1.getIntPart() == f2.getIntPart() & f1.getMantis() == f2.getMantis()) ? (true) : (false);
}

bool operator!=(const Fraction& f1, const Fraction& f2)
{
	return (f1.getIntPart() != f2.getIntPart()) ? (true) : (f1.getMantis() != f2.getMantis());
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
	int intPart, mantis;
	in >> intPart >> mantis;
	f = Fraction(intPart, mantis);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
	out << f.getIntPart() << "," << f.getMantis();
	return out;
}

Fraction::Fraction(const int intPart, const int mantis)
{
	if (mantis < 0) throw "invalid_value";
	setIntPart(intPart);
	setMantis(mantis);
}

void Fraction::setIntPart(const int t)
{
	setFirst(t);
}

void Fraction::setMantis(const int t)
{
	setSecond(t);
}

int Fraction::getIntPart() const
{
	return getFirst();
}

int Fraction::getMantis() const
{
	return getSecond();
}
