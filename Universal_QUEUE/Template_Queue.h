extern int checkup(int n);
extern void Inform();
extern char YesNo();
extern void Fflush();

#include "Strings.h"
#include "Multiple_Inheritance.h"


template <class X>          // <-----------------------  ÓÇÅË
struct Elementt
{
	X info;

	Elementt *next;
};


template <class X>
class Queue;


template <class X>                             // <--------------------- ÈÒÅÐÀÒÎÐ
class Iterator
{
	Elementt<X> *p;
	friend class Queue<X>;

public:
	Iterator(): p(0) {}
	Iterator(Elementt<X> *kk): p(kk) {}
	Iterator(const Iterator &ob): p(ob.p) {}

	bool operator== (const Iterator &ob);
	bool operator!= (const Iterator &ob);
	bool operator< (const Iterator &Ob);
	bool operator> (const Iterator &Ob);
	Iterator& operator++ ();
	Iterator operator++ (int);
	Iterator& operator= (const Iterator &ob);
	X& operator*();
};


template <class X>
bool Iterator<X>::operator==(const Iterator<X> &ob)
{
	return (p == ob.p);
}


template <class X>
bool Iterator<X>::operator!=(const Iterator<X> &ob)
{
	return (!(p == ob.p));
}


template <class X>
bool Iterator<X>::operator< (const Iterator<X> &Ob)
{
	if(this->p<Ob.p)
		return true;

	else return false;
}


template <class X>
bool Iterator<X>::operator> (const Iterator<X> &Ob)
{
	if(this->p>Ob.p)
		return true;

	else return false;
}


template <class X>
Iterator<X> Iterator<X>::operator++(int)
{
	Iterator<X> temp = *this;
	p=p->next;
	return temp;
}


template<class X>
Iterator<X>& Iterator<X>::operator++ ()
{
	p=p->next;
	return *this;
}


template <class X>
Iterator<X>& Iterator<X>::operator=(const Iterator<X> &ob)
{
	p = ob.p;
	return *this;
}


template <class X>
X& Iterator<X>::operator*()
{
	return p->info;
}



template <class X>                    // <--------------------   Î×ÅÐÅÄÜ (ãëàâíûé êëàññ)
class Queue
{
private:
	Elementt<X> *h, *t;
	void add();
	void del();
	void show(int n);

public: 
	Queue()
	{
		h=0; t=0;
	}
	~Queue() {}

	friend class Iterator<X>;

	void Switch(int n);
	X Enter();
};


template <class X>
void Queue<X>::Switch(int n)
{
	int z;
	char ch='y';

	do { 
		system("cls");
		cout<<"Choose action:"<<endl;
		cout<<"1) Add element."<<endl<<"2) Show queue."<<endl;
		cout<<"3) Delete some element.\n-----------------------"<<endl;
		z=checkup(3);
		switch(z)
		{
		case 1: { add();
			      continue;

				} break;

		case 2: { show(n);

				} break;

		case 3: { del();

				} break;
		}

		cout<<endl<<"Continue? [y/n] ";
		ch=YesNo();

	} while(ch=='y' || ch=='Y');
}


template <class X>
X Queue<X>::Enter()
{ 
	X a;

	do
	{
		Fflush();
	} while(!(cin>>a));

	return a;	        
}


template <class X>
void Queue<X>::add()
{
	Elementt<X> *n;
	char ch;

	do
	{	
		system("cls");
		cout<<"Enter the element:"<<endl;

		n=new Elementt<X>;
		n->info = Enter();
		n->next=NULL;

		if(!h)
		{	h=n;
		    t=n;
		}
		else
		{	t->next=n;
		    t=n;
		    t->next=NULL;
		}

		cout<<endl<<"Next? [y/n] ";
		ch=YesNo();

	} while(ch=='y' || ch=='Y');
}


template <class X> 
void Queue<X>::show(int n)
{   char ch=NULL;
    system("cls");

if(!h) 
	cout<<"Queue hasn't been created yet!"<<endl;
else 
{
	cout<<"Queue elements:"<<endl;
	Iterator<X> point(h);

	if(n==1)
	{
		while(point!=NULL)
		{
			cout<<*point;
			cout<<"\n";
			point++;
		}
	}
	else {
		while(point!=NULL)
		{
			cout<<*point;
			cout<<"\n";
			fflush(stdin);
			ch=getchar();
			point++;
		}
	}
}
}


template <class X>
void Queue<X>::del()
{
	int fl=0;
	system("cls");

	if(!h) 
		cout<<"Queue hasn't been created yet!"<<endl;
	else
	{
		Elementt<X> *s=h, *s1;
		X a;
		cout<<"Enter the element you want to delete: ";
		a=Enter();

		while(s->info == a)
		{
			if(h!=t)
			{
				h=h->next;
				cout<<"Removing has been performed successfully."<<endl;
				s=h;
			}
			else {
				h=t=NULL;
				cout<<"Removing has been performed successfully."<<endl;
				delete s;
				s=NULL;
				return;
			}
		}

		while(s->next) 
		{            
			if(s->next->info == a)
			{
				s1=s->next;
				if(t==s->next)
				{
					t=s;
					t->next=NULL;
					cout<<"Removing has been performed successfully."<<endl;
					return;
				}
				s->next=s1->next;
				delete s1;
				s1=NULL;
				cout<<"Removing has been performed successfully."<<endl;
				fl=1;
			}

			if(!fl)
				s=s->next;

			else fl=0;
		}
	}
}