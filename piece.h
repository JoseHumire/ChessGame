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
    virtual void calcMoves(std::shared_ptr<Piece> pieces[8][8], QPoint kingPos) =0;
    virtual void calcControlledSquares(std::shared_ptr<Piece> pieces[8][8], QPoint kingPos){
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

    virtual std::vector<QPoint> getControlledSquares(QPoint start, std::shared_ptr<Piece> pieces[8][8])=0;

    bool isControllingSquare(QPoint square){
        for(QPoint p : controlledSquares){
            if(p.rx() == square.rx() && p.ry() == square.ry()){
                return true;
            }
        }
        return false;
    };

    bool isControllingSquare(QPoint start, std::shared_ptr<Piece> pieces[8][8], QPoint square){
        std::vector<QPoint> possibleMoves;
        possibleMoves = pieces[start.rx()][start.ry()]->getControlledSquares(QPoint(start.rx(), start.ry()), pieces);
        for(QPoint p : possibleMoves){
            if(p.rx() == square.rx() && p.ry() == square.ry()){
                return true;
            }
        }
        return false;
    };

    void removeMove(QPoint move){
        auto it = moves.begin();
        while (it != moves.end())
        {
                if (move.rx() == it->rx() && move.ry() == it->ry()) {
                    it = moves.erase(it);
                    break;
                }
                else {
                    ++it;
                }
        }
    };

    bool isValidMove(std::shared_ptr<Piece> pieces[8][8], QPoint futurePos, QPoint kingPos){
        int fx = futurePos.rx();
        int fy = futurePos.ry();
        QPoint start = QPoint(this->position);
        std::shared_ptr<Piece> replaced = std::move(pieces[fx][fy]);
        pieces[fx][fy] = std::move(pieces[position.rx()][position.ry()]);
        pieces[fx][fy]->setPosition(futurePos);
        for(int i = 0; i<8; ++i){
            for(int j = 0; j<8; ++j){
                if(pieces[i][j]!=nullptr){
                    if(this->isWhite()!=pieces[i][j]->isWhite()){
                        if(pieces[i][j]->isControllingSquare(QPoint(i, j), pieces, kingPos)){
                            pieces[start.rx()][start.ry()] = std::move(pieces[fx][fy]);
                            pieces[start.rx()][start.ry()]->setPosition(start);
                            pieces[fx][fy] = std::move(replaced);
                            return false;
                        }
                    }
                }
            }
        }
        pieces[start.rx()][start.ry()] = std::move(pieces[fx][fy]);
        pieces[start.rx()][start.ry()]->setPosition(start);
        pieces[fx][fy] = std::move(replaced);
        return true;
    };

    QPoint getPosition(){
        return position;
    };
};

#endif // PIECE_H
