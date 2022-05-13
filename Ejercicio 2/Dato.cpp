#include "Numero.h"

template <typename T >
void Numero<T>::setDato(T n)
{
	this->dat=n;
}

template <typename T >
T Numero<T>::getDato() const
{
	return this->dat;
}