#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include "QLabel"
#include "QPixmap"
namespace Ui{
class Piece;
}
class Piece : public QLabel
{
    Q_OBJECT
protected:
    std::string color{};
    QPixmap icon{};
    bool hasMoved = false;
public:
    Piece();
    explicit Piece(std::string _color, QWidget *parent = nullptr);
    bool isWhite();
    virtual std::vector<QPoint> getMoves(std::unique_ptr<Piece>[8][8], QPoint) =0;
    void move(){hasMoved=true;};
};

#endif // PIECE_H
