#include "tabhashaluno.h"

TabHashAluno::TabHashAluno() : TabHash<Aluno>()
{
}

TabHashAluno::TabHashAluno(const int& TamanhoTabela, const int& colisao) : TabHash<Aluno>(TamanhoTabela, colisao)
{
}

int TabHashAluno::getChave(const Aluno& entrada) const
{
    return entrada.getChave();
}
