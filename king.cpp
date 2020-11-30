#include "king.h"

King::King(std::string _color, QWidget *parent) :
    Piece(_color, parent)
{
    if (_color == "light")
        icon.load("../ChessGame/images/lightKing.png");
    else
        icon.load("../ChessGame/images/darkKing.png");
    this->setPixmap(icon);
}

std::vector<QPoint> King::getMoves(std::unique_ptr<Piece> pieces[8][8], QPoint start){
    std::vector<QPoint> moves;
    int row = start.rx();
    int col = start.ry();
    int Xmoves[8] = { 1, 1, -1, -1 , 1, -1, 0, 0 };
    int Ymoves[8] = { 1, -1,  1, -1, 0, 0,  1, -1};
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
    return moves;
}
