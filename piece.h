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
    QPoint position;
    std::vector<QPoint> moves;
    std::vector<QPoint> controlledSquares;
public:
    Piece();
    explicit Piece(std::string _color, QPoint _position, QWidget *parent = nullptr);
    bool isWhite();
    virtual void calcMoves(std::shared_ptr<Piece> pieces[8][8]) =0;
    virtual void calcControlledSquares(std::shared_ptr<Piece> pieces[8][8]){
        controlledSquares = moves;
    };
    void move(){hasMoved=true;};
    bool getState(){return hasMoved;};
    char getType(){return type;};
    void setPosition(QPoint _position){position = _position;};

    std::vector<QPoint> getMoves(){
        return moves;
    };

    std::vector<QPoint> getControlledSquares(){
        return controlledSquares;
    };

    bool isControllingSquare(QPoint square){
        for(QPoint p : controlledSquares){
            if(p.rx() == square.rx() && p.ry() == square.ry()){
                return true;
            }
        }
        return false;
    };
};

#endif // PIECE_H
