#ifndef STRINGS_H
#define STRINGS_H

#include <iostream>

using namespace std;


class Strings
{	
private:

	char* st;
	int n;

public:
	Strings(char *s="");
	~Strings();
	Strings(const Strings &);

	void setString(char *s);
	Strings operator= (const Strings &ob);
	bool operator! ();
	bool operator== (const Strings &ob);
	bool operator< (const Strings &ob);
	bool operator> (const Strings &ob);
	friend istream & operator >> (istream &,Strings &);
	friend ostream & operator << (ostream &,Strings &);
};

#endif