#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop()= delete;
    explicit Bishop(std::string _color, QWidget *parent = nullptr);
    std::vector<QPoint> getMoves(std::unique_ptr<Piece>[8][8], QPoint);
};

#endif // BISHOP_H
