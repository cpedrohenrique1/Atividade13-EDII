#include "aluno.h"

Aluno::Aluno():     chave(0),
                    nome("")
{}

Aluno::Aluno(int chave, QString nome):  chave(0),
                                        nome("")
{
    if (chave < 0)
        throw QString("Chave invalida");
    if (nome.isEmpty())
        throw QString("Nome vazio");
    this->chave = chave;
    this->nome = nome.toUpper();
}

void Aluno::setChave(int chave){
    if (chave < 0)
        throw QString("chave invalida");
    this->chave = chave;
}

void Aluno::setNome(QString nome){
    if (nome.isEmpty())
        throw QString("Nome vazio");
    this->nome = nome;
}

int Aluno::getChave() const{
    return chave;
}

QString Aluno::getNome() const{
    return nome;
}