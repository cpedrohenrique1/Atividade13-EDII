#ifndef ALUNO_H
#define ALUNO_H

#include <QString>

class Aluno
{
private:
    int chave;
    QString nome;

public:
    Aluno();
    Aluno(int chave, QString nome);
    void setChave(int chave);
    void setNome(QString nome);
    int getChave() const;
    QString getNome() const;
};

#endif // ALUNO_H
