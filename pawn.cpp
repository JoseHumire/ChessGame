#include "pawn.h"

Pawn::Pawn(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("../ChessGame/images/lightPawn.png");
    else
        icon.load("../ChessGame/images/darkPawn.png");
    this->setPixmap(icon);
}

std::vector<QPoint> Pawn::getMoves(std::unique_ptr<Piece> pieces[8][8], QPoint start){
    std::vector<QPoint> moves;
    int r = start.rx();
    int c = start.ry();
    int dir = (color == "light") ? -1:1;
    if(pieces[r+dir*1][c] == nullptr){
        moves.push_back(QPoint(r+dir*1, c));
    }
    if(c-1>=0){
        if(pieces[r+dir*1][c-1]!=nullptr){
            if(pieces[r+dir*1][c-1]->isWhite() != this->isWhite()){
                moves.push_back(QPoint(r+dir*1, c-1));
            }
        }
    }
    if(c+1<8){
        if(pieces[r+dir*1][c+1]!=nullptr){
            if(pieces[r+dir*1][c+1]->isWhite() != this->isWhite()){
                moves.push_back(QPoint(r+dir*1, c+1));
            }
        }
    }
    if(!hasMoved){
        if(pieces[r+dir*2][c] == nullptr){
            moves.push_back(QPoint(r+dir*2, c));
        }
    }
    return moves;
}
