#ifndef TABHASHALUNO_H
#define TABHASHALUNO_H

#include "tabhash.h"
#include "aluno.h"

class TabHashAluno : public TabHash<Aluno>
{
public:
    TabHashAluno();
    TabHashAluno(int TamanhoTabela, int colisao);
    int getChave(Aluno entrada) const override;
};

#endif // TABHASHALUNO_H
