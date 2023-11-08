#ifndef TABHASH_H
#define TABHASH_H

#include "lista.h"
#include <cmath>

template <typename T>
class TabHash
{
private:
    Lista<T>* tabela;
    int tamanhoTabela;
    int nPrimo;
public:
    TabHash() :     tamanhoTabela(0),
                    tabela(0),
                    nPrimo(0)
    {}

    TabHash(int tamanhoTabela) :    tamanhoTabela(0),
                                    tabela(0),
                                    nPrimo(0)
    {
        if (tamanhoTabela <= 0){
            throw QString("Nao foi possivel, tamanho invalido");
        }
        this->tamanhoTabela = tamanhoTabela;
        try{
            tabela = new Lista<T>[calcularNPrimo(tamanhoTabela)];
        }catch(std::bad_alloc &e){
            throw QString("nao foi possivel alocar memoria");
        }
    }
    
    void IncluirDados(int chave, T entrada)
    
    void ExcluirDados(int chave);
    
    T Consultar(int chave);
    
    int calcularNPrimo(const int& entrada){
        int divisao = entrada / 3;
        int max = 0;
        for (int i = tamanhoTabela; i <= sqrt(divisao); ++i){
            int div = 0;
            for (int j = 2; j < sqrt(i); ++j){
                if (i%j == 0){
                    ++div;
                }
            }
            if (!div){
                max = i;
            }
        }
        std::cout << max << "\n";
        nPrimo = max;
        return nPrimo;
    }
};

#endif // TABHASH_H
