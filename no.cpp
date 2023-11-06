#include "no.h"

template<class T>
NO<T>::NO() :   proximo(0),
                anterior(0)
{}

template<class T>
NO<T>::NO(T newDado) :  dado(newDado),
                        proximo(0),
                        anterior(0)
{}

template<class T>
void NO<T>::setDado(T newDado){
    dado = newDado;
}

template<class T>
T NO<T>::getDado()const{
    return dado;
}

template<class T>
void NO<T>::setProximo(NO* newProximo){
    proximo = newProximo;
}

template<class T>
NO<T> *NO<T>::getProximo() const{
    return proximo;
}

template<class T>
NO<T>* NO<T>::getAnterior()const{
    return anterior;
}

template <class T>
void NO<T>::setAnterior(NO* newAnterior){
    anterior = newAnterior;
}