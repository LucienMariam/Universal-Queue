#include "Template_Queue.h"


Human::Human(const Human &ob)
{
	this->Name=ob.Name;
	this->Sname=ob.Sname;
	this->Gender=ob.Gender;
}


Human Human::LoadHuman()
{
	int i;

	cout<<"\n\n\4 Name - ";
	Enter(Name);
	cout<<"\n\n\4 Second name - ";
	Enter(Sname);
	cout<<"\n\n\4 Choose gender: 1) - Male,\n                 2) - Female.\n\n\n\4 Choice - ";
	i=checkup(2);
	if(i==1)
		Gender.setString("Male");

	else Gender.setString("Female");

	return *this;
}


Human Human::operator= (const Human &ob)
{
	this->Name=ob.Name;
	this->Sname=ob.Sname;
	this->Gender=ob.Gender;

	return *this;
}


bool Human::operator! ()
{
	if(!this->Name && !this->Sname)
		return false;
}


bool Human::operator== (const Human &ob)
{
	if(this->Name==ob.Name && this->Sname==ob.Sname)
		return true;
	else return false;
}

istream& operator>> (istream &stream, Human &current)
{
	current.LoadHuman();

	return stream;
}

ostream& operator<< (ostream &stream, Human &current)
{

	return stream <<"\n\n\n\4 Initials          - "<<current.Name<<" "<<current.Sname<<"\n\4 Gender            - "<<current.Gender;
}