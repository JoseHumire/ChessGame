#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
public:
    Rook() =delete;
    explicit Rook(std::string _color, QWidget *parent = nullptr);
    std::vector<QPoint> getMoves(std::shared_ptr<Piece>[8][8], QPoint);
};

#endif // ROOK_H
