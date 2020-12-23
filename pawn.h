#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn() = delete;
    explicit Pawn(std::string _color, QWidget *parent = nullptr);
    std::vector<QPoint> getMoves(std::shared_ptr<Piece>[8][8], QPoint) override;
    std::vector<QPoint> getControlledSquares(std::shared_ptr<Piece>[8][8], QPoint) override;
};

#endif // PAWN_H
