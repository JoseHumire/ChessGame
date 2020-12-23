#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop()= delete;
    explicit Bishop(std::string _color, QPoint _position, QWidget *parent = nullptr);
    void calcMoves(std::shared_ptr<Piece> pieces[8][8]);
};

#endif // BISHOP_H
