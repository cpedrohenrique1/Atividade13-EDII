#ifndef LISTA_H
#define LISTA_H

#include "no.h"

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
    void inserirInicio(int entrada);
    int acessarInicio() const;
    int retirarInicio();
    void inserirFim(int entrada);
    int acessarFim() const;
    int retirarFim();
    void inserirPosicao(int posicao, int entrada);
    int acessarPosicao(int posicao) const;
    int retirarPosicao(int posicao);
    QString obterDados() const;
    int getQuantidadeElementos() const;
    void inserirOrdenado(int entrada);
};

#endif // LISTA_H
