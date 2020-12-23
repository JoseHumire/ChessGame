#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
    Queen()= delete;
    explicit Queen(std::string _color, QPoint _position, QWidget *parent = nullptr);
    void calcMoves(std::shared_ptr<Piece> pieces[8][8]);
};

#endif // QUEEN_H
