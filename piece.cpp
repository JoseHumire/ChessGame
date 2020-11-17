#include "piece.h"
Piece::Piece(std::string _color, QWidget *parent) :
    QLabel(parent),
    color{_color}
{
    this->setScaledContents(true);
    this->setVisible(true);
}

bool Piece::isWhite(){
    return (color == "light");
}
