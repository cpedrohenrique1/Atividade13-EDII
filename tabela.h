#ifndef TABELA_H
#define TABELA_H

#include "QTableWidget"
#include "QHeaderView"
#include "tabhash.h"

class Tabela
{
private:
    QTableWidget *tabela;
    TabHash<QString> *vetor;
    int tamanho_tabela;

public:
    Tabela();
    Tabela(QTableWidget *parent, int tamanho, int colisoes);
    ~Tabela();
    void start();
    void limpar();
    void atualizar();
    QString buscaElemento(const int& matricula);
    void inserirElemento(int& matricula, QString& nomeCompleto);
    void alterarElemento(int& matricula, QString& nomeCompleto);
    void removerElemento(int& matricula);
    TabHash<QString> *getVetor()const;
    int getTamanhoTabela()const;
};

#endif // TABELA_H
