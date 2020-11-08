#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
public:
    Knight() = delete;
    explicit Knight(std::string _color, QWidget *parent = nullptr);;
};

#endif // KNIGHT_H
