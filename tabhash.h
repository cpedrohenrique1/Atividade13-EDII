#ifndef TABHASH_H
#define TABHASH_H

#include "lista.h"
#include <cmath>

template <class L>
class TabHash
{
protected:
    Lista<L> **tabela;
    int tamanhoTabela;
public:
    TabHash() :     tabela(0),
                    tamanhoTabela(0)
    {}

    TabHash(int tamanhoTabela, int colisoes) :  tabela(0),
                                                tamanhoTabela(0)
    {
        if (tamanhoTabela <= 0 || colisoes < 0){
            throw QString("Nao foi possivel, tamanho invalido ou colisoes negativas");
        }
        this->tamanhoTabela = calcularNPrimo(tamanhoTabela, colisoes);
        try{
            tabela = new Lista<L>*[this->tamanhoTabela];
            
            for (int i = 0; i < this->tamanhoTabela; ++i){
                tabela[i] = new Lista<L>;
            }
        }catch(std::bad_alloc &e){
            throw QString("nao foi possivel alocar memoria");
        }
    }

    virtual ~TabHash() = 0;

    int getTamanhoTabela()const{
        return tamanhoTabela;
    }
    
    virtual void IncluirDados(L entrada) = 0;
    
    virtual void ExcluirDados(int chave) = 0;
    
    virtual L Consultar(int chave) = 0;
    
    int calcularNPrimo(const int& entrada, int colisoes){
        if (entrada <= 0){
            throw QString("Tamanho invalido");
        }
        if (colisoes == 0){
            throw QString("Nao foi possivel dividir por 0");
        }
        int divisao = entrada / colisoes;
        int max = 0;
        for(int i = 2 ; i <= entrada && max < divisao ; ++i){
            bool div = false;
            for(int j = 2 ; j <= sqrt(i) && !div ; ++j)
                if(i % j == 0)
                    div = true;
            if(!div){
                max = i;
            }
        }
        return max;
    }
};

#endif // TABHASH_H
