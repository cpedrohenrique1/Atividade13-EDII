#include "tabela.h"

Tabela::Tabela() :  tabela(0),
                    vetor(0),
                    tamanho_tabela(0)
{}

Tabela::Tabela(QTableWidget *parent, int tamanho, int colisoes):    tabela(0),
                                                                    vetor(0),
                                                                    tamanho_tabela(0)
{
    if (!parent)
        throw QString("tabela nao criada");
    if (tamanho <= 0)
        throw QString("tamanho invalido");
    if (colisoes < 0)
        throw QString("numero de colisoes invalido");
    this->tamanho_tabela = tamanho;
    this->tabela = parent;
    try
    {
        vetor = new TabHash<QString>(tamanho, colisoes);
    }
    catch(const std::bad_alloc& e)
    {
        throw QString("Nao foi possivel alocar memoria");
    }
}

TabHash<QString> *Tabela::getVetor() const{
    return vetor;
}

int Tabela::getTamanhoTabela()const{
    if (!vetor){
        throw QString("vetor nao localizado {getTamanhoVetor}");
    }
    return vetor->getTamanhoTabela();
}

Tabela::~Tabela(){
    if (vetor)
        delete vetor;
}

void Tabela::start()
{
    if (!tabela)
        throw QString("tabela nao localizada {start}");
    
    tabela->setColumnCount(2);
    QStringList cabecalho = {"Matricula", "Nome Completo"};
    tabela->setHorizontalHeaderLabels(cabecalho);
    tabela->setColumnWidth(0, 100); // Matricula
    tabela->setColumnWidth(1, 650); // Nome
    tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabela->verticalHeader()->setVisible(false);
}

void Tabela::limpar()
{
    if (!tabela)
        throw QString("tabela nao localizada, {limpartabela}");

    tabela->setRowCount(0);
    tabela->clearContents();
    start();
}

void Tabela::atualizar()
{
    if (!tabela)
        throw QString("tabela nao localizada {atualizar}");
    
    if (!vetor)
        throw QString("vetor nao localizado {atualizar}");
    
    limpar();

    for (int i = 0; i < tamanho_tabela; ++i){
        tabela->insertRow(i);
        tabela->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        tabela->setItem(i, 1, new QTableWidgetItem(vetor->Consultar(i)));
    }
}

QString Tabela::buscaElemento(const int& matricula)
{
    if (matricula >= tamanho_tabela || matricula < 0)
        throw QString("Numero invalido, tem que ser entre 0 e 999");
        
    if (!vetor)
        throw QString("vetor nao localizado {buscaelemento}");
    return vetor->Consultar(matricula);
}

void Tabela::inserirElemento(int& matricula, QString& nomeCompleto)
{
    if (matricula < 0 || matricula >= tamanho_tabela)
        throw QString("numero de matricula nao condiz com os padroes {inserirElemento}");
    
    if (nomeCompleto.isEmpty())
        throw QString("Nome nao pode estar vazio, se deseja remover use o botao 'remover' {inserirElemento}");
    
    if (!vetor)
        throw QString("vetor nao localizado {inserirElemento}");
    
    if (vetor->Consultar(matricula) != "")
        throw QString("Este elemento ja existe, se deseja alterar, use o botao 'alterar' {inserirElemento}");
    
    vetor->IncluirDados(nomeCompleto.toUpper(), matricula);
    atualizar();
}

void Tabela::alterarElemento(int &matricula, QString &nomeCompleto)
{
    if (matricula < 0 || matricula >= tamanho_tabela)
        throw QString("numero de matricula nao condiz com os padroes {alterarElemento}");

    if (nomeCompleto.isEmpty())
        throw QString("Nome nao pode estar vazio, se deseja remover use o botao remover {alterarElemento}");

    if (!vetor)
        throw QString("vetor nao localizado {alterarElemento}");
    
    if (vetor->Consultar(matricula) == ""){
        throw QString("Elemento nao existe, se deseja adicionar use o botao 'inserir' {alterarElemento}");
    }else{
        vetor->ExcluirDados(matricula);
    }
    vetor->IncluirDados(nomeCompleto.toUpper(), matricula);
    atualizar();
}

void Tabela::removerElemento(int &matricula)
{
    if (!vetor)
        throw QString("vetor nao localizado {removerElemento}");
    if (matricula < 0 || matricula >= tamanho_tabela)
        throw QString("numero de matricula nao condiz com os padroes {removerElemento}");
    if (vetor->Consultar(matricula) == "")
        throw QString("elemento ja foi removido {removerElemento}");
    vetor->ExcluirDados(matricula);
    atualizar();
}
