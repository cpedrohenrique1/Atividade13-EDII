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
    Aluno(const int &chave, const QString &nome);
    void setChave(const int &chave);
    void setNome(const QString &nome);
    int getChave() const;
    QString getNome() const;
};

#endif // ALUNO_H
