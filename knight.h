#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
public:
    Knight() = delete;
    explicit Knight(std::string _color, QWidget *parent = nullptr);
    std::vector<QPoint> getMoves(std::unique_ptr<Piece>[8][8], QPoint);
};

#endif // KNIGHT_H
