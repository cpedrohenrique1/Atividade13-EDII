#include "no.h"

template<typename T>
NO<T>::NO() :   proximo(0),
                anterior(0)
{}

template<typename T>
NO<T>::NO(T newDado) :  dado(newDado),
                        proximo(0),
                        anterior(0)
{}

template<typename T>
void NO<T>::setDado(T newDado){
    dado = newDado;
}

template<typename T>
T NO<T>::getDado()const{
    return dado;
}

template<typename T>
void NO<T>::setProximo(NO* newProximo){
    proximo = newProximo;
}

template<typename T>
NO<T> *NO<T>::getProximo() const{
    return proximo;
}

template<typename T>
NO<T>* NO<T>::getAnterior()const{
    return anterior;
}

template <typename T>
void NO<T>::setAnterior(NO* newAnterior){
    anterior = newAnterior;
}