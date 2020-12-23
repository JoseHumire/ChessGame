#include "promotionwindow.h"
#include "ui_promotionwindow.h"
PromotionWindow::PromotionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PromotionWindow)
{
    ui->setupUi(this);
}

PromotionWindow::~PromotionWindow()
{
    delete ui;
}


void PromotionWindow::on_queenB_clicked()
{
    setPiece('Q');
}

void PromotionWindow::on_knightB_clicked()
{
    setPiece('K');
}

void PromotionWindow::on_rookB_clicked()
{
    setPiece('R');
}

void PromotionWindow::on_bishopB_clicked()
{
    setPiece('B');
}

void PromotionWindow::setPiece(char p){
    piece = p;
    this->close();
}

void PromotionWindow::setColor(std::string _color){
    QPixmap qp;
    QPixmap rp;
    QPixmap np;
    QPixmap bp;
    if(_color == "light"){
        qp = QPixmap("../ChessGame/images/lightQueen.png");
        rp = QPixmap("../ChessGame/images/lightRook.png");
        np = QPixmap("../ChessGame/images/lightKnight.png");
        bp = QPixmap("../ChessGame/images/lightBishop.png");
    }else{
        qp = QPixmap("../ChessGame/images/darkQueen.png");
        rp = QPixmap("../ChessGame/images/darkRook.png");
        np = QPixmap("../ChessGame/images/darkKnight.png");
        bp = QPixmap("../ChessGame/images/darkBishop.png");
    }
    QIcon ButtonIcon(qp);
    ui->queenB->setIcon(ButtonIcon);
    ui->queenB->setIconSize(ui->queenB->size());

    ButtonIcon = QIcon(rp);
    ui->rookB->setIcon(ButtonIcon);
    ui->rookB->setIconSize(ui->rookB->size());

    ButtonIcon = QIcon(np);
    ui->knightB->setIcon(ButtonIcon);
    ui->knightB->setIconSize(ui->knightB->size());

    ButtonIcon = QIcon(bp);
    ui->bishopB->setIcon(ButtonIcon);
    ui->bishopB->setIconSize(ui->bishopB->size());

}
