#include "piece.h"

Piece::Piece()
{
}

Piece::Piece(std::string _color, QWidget *parent) :
    QLabel(parent),
    color{_color}
{
    this->setScaledContents(true);
}

bool Piece::isWhite(){
    return (color == "light");
}
