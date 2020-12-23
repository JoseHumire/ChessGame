#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "board.h"
bool whiteTurn = true;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->widget, &Board::turnChanged, this, &MainWindow::changeTurn);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeTurn(){
    if(whiteTurn){
        ui->turn1->setText("Turno Blancas");
        ui->turn2->setText("-");
    }else{
        ui->turn1->setText("-");
        ui->turn2->setText("Turno Negras");

    }
}

