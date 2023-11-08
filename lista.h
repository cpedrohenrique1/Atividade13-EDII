#ifndef LISTA_H
#define LISTA_H

#include "no.h"
#include <iostream>
#include <QString>

template <typename T>
class Lista
{
private:
    int quantidadeElementos;
    NO<T>* inicio;
    NO<T>* fim;
public:
    Lista() :   inicio(0),
                fim(0),
                quantidadeElementos(0)
    {}
    
    bool estaVazia() const{
        return !(bool(quantidadeElementos));
    }
    
    void inserirInicio(T entrada){
        try{
            NO<T>* newElemento = new NO<T>(entrada);
            if (estaVazia()){
                inicio = fim = newElemento;
                ++quantidadeElementos;
                return;
            }
            inicio->setAnterior(newElemento);
            newElemento->setProximo(inicio);
            inicio = newElemento;
            ++quantidadeElementos;
        }catch(std::bad_alloc &e){
            throw QString("Erro ao inserir no inicio, nao foi possivel alocar memoria");
        }
    }
    
    T acessarInicio() const{
        return inicio;
    }
    
    T retirarInicio(){
        if (estaVazia()){
            throw QString("Lista ja vazia, nao foi possivel retirar");
        }
        NO<T>* aux = inicio;
        if (quantidadeElementos == 1){
            quantidadeElementos = 0;
            inicio = fim = 0;
            T valor = aux->getDado();
            delete aux;
            return valor;
        }
        T valor = inicio->getDado();
        inicio = inicio->getProximo();
        inicio->setAnterior(0);
        delete aux;
        --quantidadeElementos;
        return valor;
    }
    
    void inserirFim(T entrada){
        if (estaVazia()){
            inserirInicio(entrada);
            return;
        }
        try{
            NO<T>* newElemento = new NO<T>(entrada);
            newElemento->setAnterior(fim);
            fim->setProximo(newElemento);
            fim = newElemento;
            ++quantidadeElementos;
        }catch(std::bad_alloc &e){
            throw QString("Erro ao inserir no fim, nao foi possivel alocar memoria");
        }
    }
    
    T acessarFim() const{
        return fim;
    }
    
    T retirarFim(){
        if (estaVazia()){
            throw QString("Lista ja vazia, nao foi possivel retirar");
        }
        if (quantidadeElementos == 1){
            retirarInicio();
            return;
        }
        NO<T>* aux = fim;
        T valor = fim->getDado();
        fim = fim->getAnterior();
        fim->setProximo(0);
        delete aux;
        --quantidadeElementos;
        return valor;
    }
    
    void inserirPosicao(int posicao, T entrada){
        if (posicao < 0 || posicao > quantidadeElementos){
            throw QString("Posicao invalida, nao pode ser menor que 0 ou maior que a quantidade de elementos");
        }
        if (posicao == 0 || estaVazia()){
            inserirInicio(entrada);
            return;
        }
        if (posicao == quantidadeElementos){
            inserirFim(entrada);
            return;
        }
        try{
            NO<T>* newElemento = new NO<T>(entrada);
            NO<T>* aux;
            if (posicao < quantidadeElementos / 2){
                aux = inicio;
                for (int i = 0; i < posicao; ++i){
                    aux = aux->getProximo();
                }
            }else{
                aux = fim;
                for (int i = quantidadeElementos - 1; i > posicao; --i){
                    aux = aux->getAnterior();
                }
            }
            NO<T>* anterior = aux->getAnterior();
            anterior->setProximo(newElemento);
            newElemento->setProximo(aux);
            newElemento->setAnterior(anterior);
            aux->setAnterior(newElemento);
            ++quantidadeElementos;
        }catch(std::bad_alloc &e){
            throw QString("Erro ao inserir no inicio, nao foi possivel alocar memoria");
        }
    }
    
    T acessarPosicao(int posicao) const{
        if (posicao < 0 || posicao >= quantidadeElementos){
            throw QString("A posicao nao pode ser maior que a quantidade de elementos e nem menor que 0");
        }
        NO<T>* elemento = inicio;
        for (int i = 0; i < posicao; ++i){
            elemento = elemento->getProximo();
        }
        return elemento->getDado();
    }
    
    T retirarPosicao(int posicao){
        if (estaVazia()){
            throw QString("Lista ja vazia, nao foi possivel retirar");
        }
        if (posicao < 0 || posicao >= quantidadeElementos){
            throw QString("Posicao invalida, nao pode ser menor que 0 ou maior igual que a quantidade de elementos");
        }
        if (quantidadeElementos == 1 || posicao == 0){
            retirarInicio();
            return;
        }
        if (posicao == quantidadeElementos - 1){
            retirarFim();
            return;
        }
        NO<T>* aux;
        if (posicao < quantidadeElementos / 2){
            aux = inicio;
            for (int i = 0; i < posicao; ++i){
                aux = aux->getProximo();
            }
        }else{
            aux = fim;
            for (int i = 0; i > posicao; --i){
                aux = aux->getAnterior();
            }
        }
        NO<T>* anterior = aux->getAnterior();
        NO<T>* proximo = aux->getProximo();
        anterior->setProximo(proximo);
        proximo->setAnterior(anterior);
        T valor = aux->getDado();
        delete aux;
        --quantidadeElementos;
        return valor;
    }
    
    int getQuantidadeElementos() const{
        return quantidadeElementos;
    }
};

#endif // LISTA_H
