#include "tabhashaluno.h"

TabHashAluno::TabHashAluno() : TabHash<Aluno>()
{}

TabHashAluno::TabHashAluno(int TamanhoTabela, int colisao) : TabHash<Aluno>(TamanhoTabela, colisao)
{}

int TabHashAluno::getChave(Aluno entrada)const{
    return entrada.getChave();
}

