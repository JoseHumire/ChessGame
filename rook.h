#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
public:
    Rook() =delete;
    explicit Rook(std::string _color, QWidget *parent = nullptr);
};

#endif // ROOK_H
