#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <QWidget>
#include <QLabel>
#include <memory>
#include "piece.h"

class Square : public QWidget
{
    Q_OBJECT
public:
    Square();
    Square(QBrush*, int, QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *) override;
    QBrush* brush;
    std::unique_ptr<Piece> piece;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};
#endif // SQUARE_H
