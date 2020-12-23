#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
    Queen()= delete;
    explicit Queen(std::string _color, QWidget *parent = nullptr);
    std::vector<QPoint> getMoves(std::shared_ptr<Piece>[8][8], QPoint);
};

#endif // QUEEN_H
