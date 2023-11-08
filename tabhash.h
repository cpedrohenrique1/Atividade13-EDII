#ifndef TABHASH_H
#define TABHASH_H

#include "lista.h"
#include <cmath>

template <class T>
class TabHash
{
private:
    Lista<T>* tabela;
    int tamanhoTabela;
    int nPrimo;
public:
    TabHash();
    TabHash(int tamanhoTabela);
    void IncluirDados(int chave, T entrada);
    void ExcluirDados(int chave);
    T Consultar(int chave);
    int calcularNPrimo(const int& entrada);
};

#endif // TABHASH_H
