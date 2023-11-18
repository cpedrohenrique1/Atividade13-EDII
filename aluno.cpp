#include "aluno.h"

Aluno::Aluno() : chave(0),
                 nome("")
{
}

Aluno::Aluno(const int &chave, const QString &nome) : chave(0),
                                                      nome("")
{
    if (chave < 0)
        throw QString("Chave invalida");
    if (nome.isEmpty())
        throw QString("Nome vazio");
    this->chave = chave;
    this->nome = nome.toUpper();
}

void Aluno::setChave(const int &chave)
{
    if (chave < 0)
        throw QString("chave invalida");
    this->chave = chave;
}

void Aluno::setNome(const QString &nome)
{
    if (nome.isEmpty())
        throw QString("Nome vazio");
    this->nome = nome;
}

int Aluno::getChave() const
{
    return chave;
}

QString Aluno::getNome() const
{
    return nome;
}