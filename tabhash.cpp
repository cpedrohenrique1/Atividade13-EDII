#include "tabhash.h"

template <class T>
TabHash<T>::TabHash() :     tamanhoTabela(0),
                            tabela(0),
                            nPrimo(0)
{}

template <class T>
TabHash<T>::TabHash(int tamanhoTabela):     tamanhoTabela(0),
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

template <class T>
int TabHash<T>::calcularNPrimo(const int& entrada){
    int divisao = entrada / 3;
    int max = 0;
    for (int i = 2; i <= sqrt(divisao); ++i){
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

template <class T>
void TabHash<T>::IncluirDados(int chave, T entrada){

}