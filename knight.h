#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
public:
    Knight() = delete;
    explicit Knight(std::string _color, QPoint _position, QWidget *parent = nullptr);
    void calcMoves(std::shared_ptr<Piece> pieces[8][8], QPoint kingPos);
    void calcControlledSquares(std::shared_ptr<Piece> pieces[8][8], QPoint kingPos);
    std::vector<QPoint> getControlledSquares(QPoint start, std::shared_ptr<Piece> pieces[8][8]);
};

#endif // KNIGHT_H
