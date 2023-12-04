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
    int colisoes;

public:
    TabHash() : tabela(0),
                tamanhoTabela(0),
                colisoes(0)
    {
    }

    TabHash(const int &tamanhoTabela, const int &colisoes) : tabela(0),
                                                             tamanhoTabela(0),
                                                             colisoes(0)

    {
        if (tamanhoTabela <= 0 || colisoes <= 0)
        {
            throw QString("Nao foi possivel, tamanho invalido ou colisao invalida");
        }
        this->colisoes = colisoes;
        this->tamanhoTabela = calcularNPrimo(tamanhoTabela, colisoes);
        try
        {
            tabela = new Lista<L> *[this->tamanhoTabela];

            for (int i = 0; i < this->tamanhoTabela; ++i)
            {
                tabela[i] = new Lista<L>;
            }
        }
        catch (std::bad_alloc &e)
        {
            throw QString("nao foi possivel alocar memoria");
        }
    }

    int getColisoes() const
    {
        return colisoes;
    }

    Lista<L> **getVetor() const
    {
        return tabela;
    }

    ~TabHash()
    {        
        if (tabela)
        {
            for (int i = 0; i < tamanhoTabela; ++i)
            {
                if (tabela[i])
                {
                    delete tabela[i];
                    tabela[i] = 0;
                }
            }
            delete[] tabela;
            tabela = 0;
        }
    }

    int getTamanhoTabela() const
    {
        return tamanhoTabela;
    }

    virtual int getChave(const L &entrada) const = 0;

    int calcPosicao(const int &entrada) const
    {
        if (entrada < 0)
        {
            throw QString("Chave invalida");
        }
        return entrada % tamanhoTabela;
    }

    void IncluirDados(const L &entrada)
    {
        if (!tabela || tamanhoTabela <= 0)
        {
            throw QString("Tabela nao alocada");
        }
        int chave = calcPosicao(getChave(entrada));
        if (chave >= tamanhoTabela)
        {
            throw QString("Chave invalida");
        }
        tabela[chave]->inserirInicio(entrada);
    }

    void ExcluirDados(const int& chave)
    {
        if (!tabela || tamanhoTabela <= 0)
        {
            throw QString("Tabela nao alocada");
        }
        int temp = calcPosicao(chave);
        if (temp < 0 || temp >= tamanhoTabela)
        {
            throw QString("Chave invalida");
        }
        NO<L> *iterator = tabela[temp]->acessarInicio();
        for (int i = 0; i < tabela[temp]->getQuantidadeElementos(); ++i)
        {
            if (getChave(iterator->getDado()) == chave)
            {
                tabela[temp]->retirarPosicao(i);
                return;
            }
            iterator = iterator->getProximo();
        }
    }

    L Consultar(const int& chave)
    {
        if (!tabela || tamanhoTabela <= 0)
        {
            throw QString("Tabela nao alocada");
        }
        if (chave < 0)
        {
            throw QString("Chave invalida");
        }
        int temp = calcPosicao(chave);
        if (temp >= tamanhoTabela)
        {
            throw QString("Chave invalida");
        }
        NO<L> *iterator = tabela[temp]->acessarInicio();
        for (int i = 0; i < tabela[temp]->getQuantidadeElementos(); ++i)
        {
            if (getChave(iterator->getDado()) == chave)
            {
                return iterator->getDado();
            }
            iterator = iterator->getProximo();
        }
        return L();
    }

    int calcularNPrimo(const int &entrada, const int &colisoes)
    {
        if (entrada <= 0)
        {
            throw QString("Tamanho invalido");
        }
        if (colisoes == 0)
        {
            throw QString("Nao foi possivel dividir por 0");
        }
        int divisao = entrada / colisoes;
        int max = 0;
        for (int i = 2; i <= entrada && max < divisao; ++i)
        {
            bool div = false;
            for (int j = 2; j <= sqrt(i) && !div; ++j)
                if (i % j == 0)
                    div = true;
            if (!div)
            {
                max = i;
            }
        }
        return max;
    }
};

#endif // TABHASH_H
