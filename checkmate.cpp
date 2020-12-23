#include "checkmate.h"
#include "ui_checkmate.h"

CheckMate::CheckMate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckMate)
{
    ui->setupUi(this);
}

CheckMate::~CheckMate()
{
    delete ui;
}
