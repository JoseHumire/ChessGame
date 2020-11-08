#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn() = delete;
    explicit Pawn(std::string _color, QWidget *parent = nullptr);
};

#endif // PAWN_H
