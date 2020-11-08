#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
    Queen()= delete;
    explicit Queen(std::string _color, QWidget *parent = nullptr);
};

#endif // QUEEN_H
