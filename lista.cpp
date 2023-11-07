#include "lista.h"

template<class T>
Lista<T>::Lista() : inicio(0),
                    fim(0),
                    quantidadeElementos(0)
{}

template<class T>
bool Lista<T>::estaVazia() const{
    return !(bool(quantidadeElementos));
}

template<class T>
int Lista<T>::getQuantidadeElementos() const{
    return quantidadeElementos;
}

template<class T>
T Lista<T>::acessarFim()const{
    return fim;
}

template<class T>
T Lista<T>::acessarInicio()const{
    return inicio;
}

template<class T>
T Lista<T>::acessarPosicao(int posicao)const{
    T<T>* elemento = inicio;
    for (int i = 0; i < quantidadeElementos; ++i){
        elemento
    }
}