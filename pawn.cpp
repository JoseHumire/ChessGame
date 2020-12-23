#include "pawn.h"
#include <QDebug>
Pawn::Pawn(std::string _color, QPoint _position, QWidget *parent) :
    Piece(_color, _position, parent)
{
    if (_color == "light")
        icon.load("../ChessGame/images/lightPawn.png");
    else
        icon.load("../ChessGame/images/darkPawn.png");
    this->setPixmap(icon);
}

void Pawn::calcMoves(std::shared_ptr<Piece> pieces[8][8], QPoint kingPos){
    std::vector<QPoint> moves;
    int r = position.rx();
    int c = position.ry();
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
    auto it = moves.begin();
    while (it != moves.end())
        {
            if (!isValidMove(pieces, *it, kingPos)) {
                it = moves.erase(it);
            }
            else {
                ++it;
            }
    }
    this->moves = moves;
}

std::vector<QPoint> Pawn::getControlledSquares(QPoint start, std::shared_ptr<Piece> pieces[8][8]){
    std::vector<QPoint> moves;
    int r = start.rx();
    int c = start.ry();
    int dir = (color == "light") ? -1:1;
    if(c-1>=0){
        moves.push_back(QPoint(r+dir*1, c-1));
    }
    if(c+1<8){
        moves.push_back(QPoint(r+dir*1, c+1));
    }
    return moves;
}

void Pawn::calcControlledSquares(std::shared_ptr<Piece> pieces[8][8], QPoint kingPos){
    this->controlledSquares = getControlledSquares(this->position, pieces);
}
