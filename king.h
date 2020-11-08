#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
public:
    King() = delete;
    explicit King(std::string _color, QWidget *parent = nullptr);
};

#endif // KING_H
