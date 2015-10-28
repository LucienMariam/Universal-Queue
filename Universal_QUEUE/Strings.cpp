#include "Strings.h"


Strings::Strings(char *s)
{	
	n=strlen(s);
	st=new char[n+1];
	strcpy_s(st, (n+1)*sizeof(char), s);
}

Strings::~Strings()
{	
	delete [] st;
	n=0;
}

Strings::Strings(const Strings &another)
{	
	n=another.n;
	this->st=new char [n+1];
	strcpy_s(st, (n+1)*sizeof(char), another.st);
}

void Strings::setString(char *s)
{
	delete [] st;
	n=strlen(s);
	st=new char[n+1];
	strcpy_s(st, (n+1)*sizeof(char), s);
}

Strings Strings::operator=(const Strings &ob)
{	
	delete [] st;
	st=new char[ob.n+1];
	n=ob.n;
	strcpy_s(st, (n+1)*sizeof(char), ob.st);

	return *this;
}


bool Strings::operator! ()
{
	if(this->st==NULL)
		return true;

	else return false;
}


bool Strings::operator==(const Strings &ob)
{	
	if(!strcmp(this->st, ob.st))
		return true;

	else return false;
}


bool Strings::operator< (const Strings &Obj2)
{
	int s;

	s=strcmp(this->st, Obj2.st);

	if(s<0)
		return true;

	else return false;
}


bool Strings::operator> (const Strings &Obj2)
{
	int s;

	s=strcmp(this->st, Obj2.st);

	if(s>0)
		return true;

	else return false;
}


ostream& operator<< (ostream &stream, Strings &current)
{
	return stream << current.st;
}

istream& operator>> (istream &stream, Strings &current)
{
	char str[81];

	cin.getline(str,81);
	current.st=new char [strlen(str)+1];
	strcpy_s(current.st, (strlen(str)+1)*sizeof(char), str);
	current.n=strlen(current.st);

	return stream;
}