#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
public:
    Rook() =delete;
    explicit Rook(std::string _color, QPoint _position, QWidget *parent = nullptr);
    void calcMoves(std::shared_ptr<Piece> pieces[8][8], QPoint kingPos);
    void calcControlledSquares(std::shared_ptr<Piece> pieces[8][8], QPoint kingPos);
    std::vector<QPoint> getControlledSquares(QPoint start, std::shared_ptr<Piece> pieces[8][8]);
};

#endif // ROOK_H
