#include "rook.h"
#include <QDebug>
Rook::Rook(std::string _color, QPoint _position, QWidget *parent) :
    Piece(_color, _position, parent)
{
    type = 'R';
    if (_color == "light")
        icon.load("../ChessGame/images/lightRook.png");
    else
        icon.load("../ChessGame/images/darkRook.png");
    this->setPixmap(icon);
}

void Rook::calcMoves(std::shared_ptr<Piece> pieces[8][8]){
    std::vector<QPoint> moves;
    int row = position.rx();
    int col = position.ry();
    int Xmoves[8] = { 1, -1, 0, 0 };
    int Ymoves[8] = { 0, 0,  1, -1};
    for (int i = 0; i < 4; ++i) {
       for(int j=1; j<8; ++j){
           int x = row + Xmoves[i]*j;
           int y = col + Ymoves[i]*j;
           if (x>=0 && y>=0 && x<8 && y<8){
               if(pieces[x][y]!=nullptr){
                   if(this->isWhite()!=pieces[x][y]->isWhite()){
                       moves.push_back(QPoint(x, y));
                   }
                   break;
               }
               moves.push_back(QPoint(x, y));
           }
       }
    }
    this->moves = moves;
}
