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
    char type = 'p';
public:
    Piece();
    explicit Piece(std::string _color, QWidget *parent = nullptr);
    bool isWhite();
    virtual std::vector<QPoint> getMoves(std::shared_ptr<Piece>[8][8], QPoint) =0;
    virtual std::vector<QPoint> getControlledSquares(std::shared_ptr<Piece> pieces[8][8], QPoint start){
        return getMoves(pieces, start);
    };
    void move(){hasMoved=true;};
    bool getState(){return hasMoved;};
    char getType(){return type;};
};

#endif // PIECE_H
