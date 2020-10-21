#pragma once
#include <iostream>
#include <QWidget>

class Square : public QWidget
{
public:
    Square();
    Square(QBrush*);
protected:
    void paintEvent(QPaintEvent *);
    QBrush* brush;
};
