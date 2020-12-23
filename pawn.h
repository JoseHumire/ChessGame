#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn() = delete;
    explicit Pawn(std::string _color, QPoint _position, QWidget *parent = nullptr);
    void calcMoves(std::shared_ptr<Piece> pieces[8][8]) override;
    void calcControlledSquares(std::shared_ptr<Piece> pieces[8][8]) override;
};

#endif // PAWN_H
