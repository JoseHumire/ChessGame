#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "board.h"
bool whiteTurn = true;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}

