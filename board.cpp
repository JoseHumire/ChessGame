#include "board.h"
#include "pawn.h"
#include "ui_board.h"
#include <QGridLayout>

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    QGridLayout *layout = new QGridLayout();
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->setVerticalSpacing(0);
    layout->setHorizontalSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    QBrush* dark = new QBrush("#c56c00");
    QBrush* light = new QBrush("#F8DFA1");
    QBrush* brush;
    for(int i=0; i<64; i++){
        if((i+i/8)%2==0){
            brush = dark;
        }else{
            brush = light;
        }
        Square *sq = new Square(brush, i);
        squares.push_back(sq);
        layout->addWidget(sq, i/8, i%8);
    }
    this->setLayout(layout);
}

Board::~Board()
{
    delete ui;
}
