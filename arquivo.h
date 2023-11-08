#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "tabhash.h"
#include <QFile>
#include <QTextStream>

class Arquivo
{
private:
    TabHash<QString> *vetor;
public:
    Arquivo();
    Arquivo(TabHash<QString> *entrada);
    void abrir();
    void carregar_elementos(QTextStream &in);
};

#endif // ARQUIVO_H
