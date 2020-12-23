#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn() = delete;
    explicit Pawn(std::string _color, QPoint _position, QWidget *parent = nullptr);
    void calcMoves(std::shared_ptr<Piece> pieces[8][8], QPoint kingPos) override;
    void calcControlledSquares(std::shared_ptr<Piece> pieces[8][8], QPoint kingPos) override;
    std::vector<QPoint> getControlledSquares(QPoint start, std::shared_ptr<Piece> pieces[8][8]);
};

#endif // PAWN_H
