#include "tabhashaluno.h"

TabHashAluno::TabHashAluno() : TabHash<Aluno>()
{}

TabHashAluno::TabHashAluno(int TamanhoTabela, int colisao) : TabHash<Aluno>(TamanhoTabela, colisao)
{}

TabHashAluno::~TabHashAluno()
{
    for (int i = 0; i < tamanhoTabela; ++i){
        delete tabela[i];
    }
    delete[] tabela;
}

Aluno TabHashAluno::Consultar(int chave)
{
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
    NO<Aluno>* iterator = tabela[chave]->acessarInicio();
    for (int i = 0; i < tabela[chave]->getQuantidadeElementos(); ++i){
        if (iterator->getDado().getChave() == temp){
            return iterator->getDado();
        }
        iterator = iterator->getProximo();
    }
    return Aluno();
}

void TabHashAluno::IncluirDados(Aluno entrada)
{
    if (!tabela || tamanhoTabela <= 0){
        throw QString("Tabela nao alocada");
    }
    int chave = entrada.getChave();
    chave %= tamanhoTabela;
    if (chave >= tamanhoTabela){
        throw QString("Chave invalida");
    }
    tabela[chave]->inserirInicio(entrada);
}

void TabHashAluno::ExcluirDados(int chave)
{
    if (!tabela || tamanhoTabela <= 0){
        throw QString("Tabela nao alocada");
    }
    int temp = chave;
    chave %= tamanhoTabela;
    if (chave < 0 || chave >= tamanhoTabela){
        throw QString("Chave invalida");
    }
    NO<Aluno>* iterator = tabela[chave]->acessarInicio();
    for (int i = 0; i < tabela[chave]->getQuantidadeElementos(); ++i){
        if (iterator->getDado().getChave() == temp){
            tabela[chave]->retirarPosicao(i);
            return;
        }
        iterator = iterator->getProximo();
    }
}

