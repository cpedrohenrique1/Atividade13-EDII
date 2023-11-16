#ifndef TABHASHALUNO_H
#define TABHASHALUNO_H

#include "tabhash.h"
#include "aluno.h"

class TabHashAluno : public TabHash<Aluno>
{
public:
    TabHashAluno();
    TabHashAluno(int TamanhoTabela, int colisao);
    ~TabHashAluno() override;
    Aluno Consultar(int chave) override;
    void IncluirDados(Aluno entrada) override;
    void ExcluirDados(int chave) override;
};

#endif // TABHASHALUNO_H
