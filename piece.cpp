#include "piece.h"

Piece::Piece()
{
}

Piece::Piece(std::string _color, QPoint _position, QWidget *parent) :
    QLabel(parent),
    color{_color},
    position{_position}
{
    this->setScaledContents(true);
}

bool Piece::isWhite(){
    return (color == "light");
}
