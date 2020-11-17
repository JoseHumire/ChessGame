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
public:
    Piece() = delete;
    explicit Piece(std::string _color, QWidget *parent = nullptr);
    bool isWhite();
};

#endif // PIECE_H
