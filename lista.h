#ifndef LISTA_H
#define LISTA_H

#include "no.h"
#include <iostream>
#include <QString>

template <class T>
class Lista
{
private:
    int quantidadeElementos;
    NO<T>* inicio;
    NO<T>* fim;
public:
    Lista();
    bool estaVazia() const;
    void inserirInicio(T entrada);
    T acessarInicio() const;
    T retirarInicio();
    void inserirFim(T entrada);
    T acessarFim() const;
    T retirarFim();
    void inserirPosicao(int posicao, T entrada);
    T acessarPosicao(int posicao) const;
    T retirarPosicao(int posicao);
    QString obterDados() const;
    int getQuantidadeElementos() const;
    void inserirOrdenado(T entrada);
};

#endif // LISTA_H
