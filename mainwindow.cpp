#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TabHash<QString> tabela;
    tabela.calcularNPrimo(1000, 3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

