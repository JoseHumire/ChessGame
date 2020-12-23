#include "king.h"
#include <qdebug.h>
King::King(std::string _color, QPoint _position, QWidget *parent) :
    Piece(_color, _position, parent)
{
    type = 'K';
    if (_color == "light")
        icon.load("../ChessGame/images/lightKing.png");
    else
        icon.load("../ChessGame/images/darkKing.png");
    this->setPixmap(icon);
}

void King::calcMoves(std::shared_ptr<Piece> pieces[8][8], QPoint kingPos){
    std::vector<QPoint> moves;
    int row = position.rx();
    int col = position.ry();
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
    if(!this->hasMoved){
        if(pieces[row][0]!=nullptr && pieces[row][col-3]==nullptr && pieces[row][col-2]==nullptr && pieces[row][col-1]==nullptr){
            if(!pieces[row][0]->getState()){
                moves.push_back(QPoint(row, col-2));
            }
        }
        if(pieces[row][7]!=nullptr && pieces[row][col+2]==nullptr && pieces[row][col+1]==nullptr){
            if(!pieces[row][7]->getState()){
                moves.push_back(QPoint(row, col+2));
            }
        }
    }
    auto it = moves.begin();
    while (it != moves.end())
        {
            if (wouldBeInCheck(pieces, *it)) {
                it = moves.erase(it);
            }
            else {
                ++it;
            }
    }
    this->moves = moves;
}

bool King::wouldBeInCheck(std::shared_ptr<Piece> pieces[8][8], QPoint futurePos){
    for(int i = 0; i<8; ++i){
        for(int j = 0; j<8; ++j){
            if(pieces[i][j]!=nullptr){
                if(this->isWhite()!=pieces[i][j]->isWhite()){
                    if(pieces[i][j]->isControllingSquare(futurePos)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

std::vector<QPoint> King::getControlledSquares(QPoint start, std::shared_ptr<Piece> pieces[8][8]){
    std::vector<QPoint> moves;
    int row = start.rx();
    int col = start.ry();
    int Xmoves[8] = { 1, 1, -1, -1 , 1, -1, 0, 0 };
    int Ymoves[8] = { 1, -1,  1, -1, 0, 0,  1, -1};
    for (int i = 0; i < 8; ++i) {
        int x = row + Xmoves[i];
        int y = col + Ymoves[i];
        if (x>=0 && y>=0 && x<8 && y<8){
            moves.push_back(QPoint(x, y));
        }
    }
    return moves;
}

void King::calcControlledSquares(std::shared_ptr<Piece> pieces[8][8], QPoint kingPos){
    this->controlledSquares = getControlledSquares(this->position, pieces);
}
