#include <iostream>

using namespace std;


inline void Pause()
{
	cout<<"\n\n";
	system("pause");
}


inline void Fflush()
{
	cin.sync();
	cin.clear();
}


int checkup(int n)
{   int num;
cin>>num;

if(num>n || num<1)
	do 
	{   Fflush();
	cout<<"\n\n\1 Wrong number! Repeat entering: ";
	cin>>num;

	} while (num>n || num<1);

	return num;
}


char YesNo()
{
	char ch;

	do
	{
		fflush(stdin);
		ch=getchar();
	}
	while (ch!= 'y' && ch!='n' && ch!='Y' && ch!='N');

	return ch;
}