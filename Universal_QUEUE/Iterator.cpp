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
