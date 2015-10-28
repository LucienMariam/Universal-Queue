#include "Template_Queue.h"

void main()
{
	int q;

	Queue<int> ob1;
	Queue<double> ob2;
	Queue<Strings> ob3;
	Queue<Businessman> ob4;

	do 
	{ system("cls");
	cout<<"\4 Menu:\n\n";
	cout<<"1) Int.\n\n2) Double.\n\n3) String.\n\n4) Businessman.\n\n\n\1 Choice: ";
	q=checkup(4);

	switch(q)
	{
	case 1: { ob1.Switch(1);

			} break;

	case 2: { ob2.Switch(1);

			} break;

	case 3: { ob3.Switch(1);

			} break;

	case 4: { ob4.Switch(2);

			} break;
	}
	} while (1);
}