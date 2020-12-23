#include "knight.h"

Knight::Knight(std::string _color, QPoint _position, QWidget *parent) :
    Piece(_color, _position, parent)
{
    type = 'N';
    if (_color == "light")
        icon.load("../ChessGame/images/lightKnight.png");
    else
        icon.load("../ChessGame/images/darkKnight.png");
    this->setPixmap(icon);
}

void Knight::calcMoves(std::shared_ptr<Piece> pieces[8][8]){
    std::vector<QPoint> moves;
    int Xmoves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int Ymoves[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int row = position.rx();
    int col = position.ry();
    for (int i = 0; i < 8; ++i) {
       int x = row + Xmoves[i];
       int y = col + Ymoves[i];
       if (x>=0 && y>=0 && x<8 && y<8){
           if(pieces[x][y]!=nullptr){
               if(this->isWhite()==pieces[x][y]->isWhite()){
                   continue;
               }
           }
           moves.push_back(QPoint(x, y));
       }
    }
    this->moves = moves;
}
