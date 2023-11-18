#ifndef TABHASHALUNO_H
#define TABHASHALUNO_H

#include "tabhash.h"
#include "aluno.h"

class TabHashAluno : public TabHash<Aluno>
{
public:
    TabHashAluno();
    TabHashAluno(const int& TamanhoTabela, const int& colisao);
    int getChave(const Aluno& entrada) const override;
};

#endif // TABHASHALUNO_H
