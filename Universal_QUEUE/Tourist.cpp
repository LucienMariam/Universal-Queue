#include "Template_Queue.h"


Tourist::Tourist(const Tourist &ob)
{    
	this->Name=ob.Name;
	this->Sname=ob.Sname;
	this->Gender=ob.Gender;
	this->Age=ob.Age;
	this->Country=ob.Country;
}


Tourist Tourist::LoadTourist()
{
	cout<<"\n\n\4 Age - ";
	Enter(Age);
	cout<<"\n\n\4 Favourite country - ";
	Enter(Country);

	return *this;
}


Tourist Tourist::operator= (const Tourist &ob)
{
	this->Name=ob.Name;
	this->Sname=ob.Sname;
	this->Gender=ob.Gender;
	this->Age=ob.Age;
	this->Country=ob.Country;

	return *this;
}


istream& operator>> (istream &stream, Tourist &current)
{
	current.LoadHuman();
	current.LoadTourist();

	return stream;
}

ostream& operator<< (ostream &stream, Tourist &current)
{
	return stream << "\n\n\n\4 Initials          - "<<current.Name<<" "<<current.Sname<<"\n\4 Gender            - "<<current.Gender<<"\n\4 Age               - "<<current.Age<<"\n\4 Favourite country - "<<current.Country;
}