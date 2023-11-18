#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "tabhashaluno.h"
#include <QFile>
#include <QTextStream>
#include "aluno.h"

class Arquivo
{
private:
    TabHashAluno *vetor;

public:
    Arquivo();
    Arquivo(TabHashAluno *entrada);
    void abrir();
    void carregar_elementos(QTextStream &in);
};

#endif // ARQUIVO_H
