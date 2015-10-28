#include "Template_Queue.h"


Businessman::Businessman(const Businessman &ob)
{
	this->Name=ob.Name;
	this->Sname=ob.Sname;
	this->Gender=ob.Gender;
	this->Profit=ob.Profit;
	this->Merchandise=ob.Merchandise;
	this->Age=ob.Age;
	this->Country=ob.Country;
}


Businessman Businessman::operator= (const Businessman &ob)
{
	this->Name=ob.Name;
	this->Sname=ob.Sname;
	this->Gender=ob.Gender;
	this->Profit=ob.Profit;
	this->Merchandise=ob.Merchandise;
	this->Age=ob.Age;
	this->Country=ob.Country;

	return *this;
}

istream & operator>> (istream &stream, Businessman &current)
{
	current.LoadHuman();
	current.LoadTrader();
	current.LoadTourist();

	return stream;
}

ostream & operator<< (ostream &stream, Businessman &current)
{
	return stream <<"\n\n\n\4 Initials          - "<<current.Name<<" "<<current.Sname<<"\n\4 Gender            - "<<current.Gender<< "\n\4 Profit            - "<<current.Profit<<" ($)\n\4 Merchandise       - "<<current.Merchandise<<"\n\4 Age               - "<<current.Age<<"\n\4 Favourite country - "<<current.Country;
}