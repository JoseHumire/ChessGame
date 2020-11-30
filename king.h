#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
public:
    King() = delete;
    explicit King(std::string _color, QWidget *parent = nullptr);
    std::vector<QPoint> getMoves(std::unique_ptr<Piece>[8][8], QPoint);
};

#endif // KING_H
