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
        if (tamanhoTabela <= 0){
            throw QString("Nao foi possivel, tamanho invalido");
        }
        try{
            tabela = new Lista<L>[calcularNPrimo(tamanhoTabela, colisoes)];
        }catch(std::bad_alloc &e){
            throw QString("nao foi possivel alocar memoria");
        }
    }
    
    void IncluirDados(int chave, L entrada);
    
    void ExcluirDados(int chave);
    
    L Consultar(int chave);
    
    int calcularNPrimo(const int& entrada, int colisoes){
        int divisao = entrada / colisoes;
        int max = 0;
        for (int i = divisao; i <= sqrt(divisao); ++i){
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
        tamanhoTabela = max;
        return tamanhoTabela;
    }
};

#endif // TABHASH_H
