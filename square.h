#pragma once
#include <iostream>
#include <QWidget>
#include <memory>
#include "piece.h"

class Square : public QWidget
{
public:
    Square();
    Square(QBrush*, int);
protected:
    void paintEvent(QPaintEvent *);
    QBrush* brush;
    std::unique_ptr<Piece> piece;
};
