#include "piece.h"


Piece::Piece(std::string _color, QWidget *parent) :
    QLabel(parent),
    color{_color}
{

}
