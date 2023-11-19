#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try{
        tabela = new Tabela(ui->tableWidget_saida_dados, 1000, 3);
        tabela->start();
        Arquivo arquivo(tabela->getVetor());
        arquivo.abrir();
        tabela->atualizar();
    }catch(std::bad_alloc &e){
        QMessageBox::information(this, "ERRO", "Erro ao alocar memoria");
    }
    catch(QString &e){
        QMessageBox::information(this, "ERRO", e);
    }
    catch(...){
        QMessageBox::information(this, "ERRO", "Erro desconhecido");
    }
}

MainWindow::~MainWindow()
{
    if (tabela)
        delete tabela;
    delete ui;
}

void MainWindow::on_pushButton_inserir_clicked()
{
    try
    {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        if (!ok)
            throw QString("matricula nao pode estar vazia");
        QString nomeCompleto = ui->lineEdit_nomeCompleto->text();
        tabela->inserirElemento(matricula, nomeCompleto);
        QMessageBox::about(this, "Concluido", "Elemento de matricula: " + QString::number(matricula) + "\nNome Completo:" + nomeCompleto +" inserido");
    }
    catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}


void MainWindow::on_pushButton_alterar_clicked()
{
    try
    {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        if (!ok)
            throw QString("n° matricula nao pode estar vazio");
        QString nomeCompleto = ui->lineEdit_nomeCompleto->text();
        tabela->alterarElemento(matricula, nomeCompleto);
        QMessageBox::about(this, "Concluido", "Elemento de matricula: " + QString::number(matricula) + " alterado");
    }
    catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}


void MainWindow::on_pushButton_remover_clicked()
{
    try
    {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        if (!ok)
            throw QString("n° matricula nao pode estar vazio");
        tabela->removerElemento(matricula);
        QMessageBox::about(this, "Concluido", "Elemento de matricula: " + QString::number(matricula) + " removido");
    }
    catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
    
}
void MainWindow::on_pushButton_consultar_clicked()
{
    try
    {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        if (ok){
            QString nomeCompleto = tabela->buscaElemento(matricula);
            if (nomeCompleto == "")
                throw QString("Elemento nao encontrado");
            else
                QMessageBox::about(this, "Concluido", "Matricula: " + QString::number(matricula) + "\nNome Completo: " + nomeCompleto);
        }else{
            throw QString("n° matricula invalido");
        }
    }
    catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}

