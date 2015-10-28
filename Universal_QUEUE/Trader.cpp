#include "Template_Queue.h"


Trader::Trader(const Trader &ob)
{   
	this->Name=ob.Name;
	this->Sname=ob.Sname;
	this->Gender=ob.Gender;
	this->Profit=ob.Profit;
	this->Merchandise=ob.Merchandise;
}


Trader Trader::LoadTrader()
{
	cout<<"\n\n\4 Profit ($) - ";
	Enter(Profit);
	cout<<"\n\n\4 Merchandise - ";
	Enter(Merchandise);

	return *this;
}


Trader Trader::operator= (const Trader &ob)
{
	this->Name=ob.Name;
	this->Sname=ob.Sname;
	this->Gender=ob.Gender;
	this->Profit=ob.Profit;
	this->Merchandise=ob.Merchandise;

	return *this;
}

istream& operator>> (istream &stream, Trader &current)
{
	current.LoadHuman();
	current.LoadTrader();

	return stream;
}

ostream& operator<< (ostream &stream, Trader &current)
{
	return stream << "\n\n\n\4 Initials          - "<<current.Name<<" "<<current.Sname<<"\n\4 Gender            - "<<current.Gender<< "\n\4 Profit            - "<<current.Profit<<" ($)\n\4 Merchandise       - "<<current.Merchandise;
}