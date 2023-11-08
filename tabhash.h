#ifndef TABHASH_H
#define TABHASH_H

#include "lista.h"
#include <cmath>

template <class L>
class TabHash
{
private:
    Lista<L>* tabela;
    int tamanhoTabela;
public:
    TabHash() :     tamanhoTabela(0),
                    tabela(0)
    {}

    TabHash(int tamanhoTabela, int colisoes) :  tamanhoTabela(0),
                                                tabela(0)
    {
        if (tamanhoTabela <= 0 || colisoes < 0){
            throw QString("Nao foi possivel, tamanho invalido ou colisoes negativas");
        }
        try{
            tabela = new Lista<L>[calcularNPrimo(tamanhoTabela, colisoes)];
        }catch(std::bad_alloc &e){
            throw QString("nao foi possivel alocar memoria");
        }
    }

    ~TabHash(){
        if (tabela){
            delete[] tabela;
        }
    }
    
    void IncluirDados(L entrada, int chave){
        if (!tabela || tamanhoTabela <= 0){
            throw QString("Tabela nao alocada");
        }
        if (chave < 0){
            throw QString("Chave invalida");
        }
        int temp = chave;
        chave %= tamanhoTabela;
        if (chave >= tamanhoTabela){
            throw QString("Chave invalida");
        }
        tabela[chave].inserirInicio(entrada, temp);
    }
    
    void ExcluirDados(int chave){
        if (!tabela || tamanhoTabela <= 0){
            throw QString("Tabela nao alocada");
        }
        int temp = chave;
        chave %= tamanhoTabela;
        if (chave < 0 || chave >= tamanhoTabela){
            throw QString("Chave invalida");
        }
        NO<L>* iterator = tabela[chave].acessarInicio();
        for (int i = 0; i < tabela[chave].getQuantidadeElementos(); ++i){
            if (iterator->getChave() == temp){
                tabela[chave].retirarPosicao(i);
                return;
            }
            iterator = iterator->getProximo();
        }
    }
    
    L Consultar(int chave){
        if (!tabela || tamanhoTabela <= 0){
            throw QString("Tabela nao alocada");
        }
        if (chave < 0){
            throw QString("Chave invalida");
        }
        int temp = chave;
        chave %= tamanhoTabela;
        if (chave >= tamanhoTabela){
            throw QString("Chave invalida");
        }
        NO<L>* iterator = tabela[chave].acessarInicio();
        for (int i = 0; i < tabela[chave].getQuantidadeElementos(); ++i){
            if (iterator->getChave() == temp){
                return iterator->getDado();
            }
            iterator = iterator->getProximo();
        }
    }
    
    int calcularNPrimo(const int& entrada, int colisoes){
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
        tamanhoTabela = max;
        return tamanhoTabela;
    }
};

#endif // TABHASH_H
