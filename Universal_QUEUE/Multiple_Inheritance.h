#ifndef MULTIPLE_INHERITANCE_H
#define MULTIPLE_INHERITANCE_H

#include "Strings.h"

class Human
{
protected:
	Strings Name, 
		    Sname,
		    Gender;

	Human LoadHuman();
	template <class T> void Enter(T &obj);

public:
	Human() {}
	~Human() {}
	Human(const Human &);

	bool operator! ();
	bool operator== (const Human &ob);
	Human operator= (const Human &ob);
	friend istream& operator >> (istream &, Human &);
	friend ostream& operator << (ostream &, Human &);
};


template <class T>
void Human::Enter(T &obj)
{
	do
	{
	  Fflush();
	} while(!(cin>>obj));
}


class Tourist : virtual public Human
{
protected:
	int Age;
	Strings Country;

	Tourist LoadTourist();

public:
	Tourist() {}
	~Tourist() {}
	Tourist(const Tourist &);

	Tourist operator= (const Tourist &ob);
	friend istream& operator >> (istream &, Tourist &);
	friend ostream& operator << (ostream &, Tourist &);
};


class Trader : virtual public Human
{
protected:
	double Profit;
	Strings Merchandise;

	Trader LoadTrader();                     

public:
	Trader() {}
	~Trader() {}
	Trader(const Trader &);

	Trader operator= (const Trader &ob);
	friend istream& operator >> (istream &,Trader &);
	friend ostream& operator << (ostream &,Trader &);
};


class Businessman : public Trader, public Tourist
{
public:
	Businessman() {}
	~Businessman() {}
	Businessman(const Businessman &);

	Businessman operator= (const Businessman &ob);
	friend istream & operator >> (istream &, Businessman &);
	friend ostream & operator << (ostream &, Businessman &);
};

#endif