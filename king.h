#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
public:
    King() = delete;
    explicit King(std::string _color, QPoint _position, QWidget *parent = nullptr);
    void calcMoves(std::shared_ptr<Piece> pieces[8][8]);
    bool wouldBeInCheck(std::shared_ptr<Piece> pieces[8][8], QPoint futurePos);
};

#endif // KING_H
