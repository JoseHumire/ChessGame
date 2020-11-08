#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop()= delete;
    explicit Bishop(std::string _color, QWidget *parent = nullptr);
};

#endif // BISHOP_H
