#include "board.h"
#include "ui_board.h"
#include <QGridLayout>
#include <QtWidgets>
#include "square.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "rook.h"
extern bool whiteTurn;
QPoint beingDragged;
std::unique_ptr<Piece> piece = nullptr;
std::vector<QPoint> moves;
Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    QGridLayout *layout = new QGridLayout();
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->setVerticalSpacing(0);
    layout->setHorizontalSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    int index;
    QString color;
    bool isLight;
    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            if((i+j)%2==0){
                color = Square::light;
                isLight = true;
            }else{
                color = Square::dark;
                isLight=false;
            }
            Square *sq = new Square(color, isLight);
            squares[i].push_back(sq);
            layout->addWidget(sq, i, j);
            std::string color = "light";
            index = i*8+j;
            if (index<20)
                color = "dark";

            if (index==0 || index ==7 || index==56 || index==63){
                piece = std::make_unique<Rook>(color, sq);
            }
            else if (index==1 || index==6 || index==57 || index==62){
                piece = std::make_unique<Knight>(color, sq);
            }
            else if (index==2 || index==5 || index==58 || index==61){
                piece = std::make_unique<Bishop>(color, sq);
            }
            else if (index==3 || index==59){
                piece = std::make_unique<Queen>(color, sq);
            }
            else if (index==4 || index==60){
                piece = std::make_unique<King>(color, sq);
            }
            else if ((index>=8 && index<=15) || (index>=48 && index<=55)){
                piece = std::make_unique<Pawn>(color, sq);
            }
            pieces[i][j]=std::move(piece);
            if(piece!=nullptr){
                piece->show();
            }
        }
    }
    this->setLayout(layout);
}

Board::~Board()
{
    delete ui;
}
void Board::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int w = width();
    int h = height();
    double squareWidth = w/8;
    double squareHeight = h/8;
    QSize s(squareWidth, squareHeight);
    for(unsigned i=0; i<8; ++i){
        for(unsigned j=0; j<8; ++j){
            if(pieces[i][j]!=nullptr){
                pieces[i][j]->setMaximumSize(s);
                pieces[i][j]->setMinimumSize(s);
            }
        }
    }

}

void Board::mousePressEvent(QMouseEvent *event)
{
    int col = event->pos().rx()/(width()/8);
    int row = event->pos().ry()/(height()/8);
    auto child = childAt(event->pos());
    if(pieces[row][col] == nullptr){
        return;
    }
    if(pieces[row][col]->isWhite() != whiteTurn)
        return;
    beingDragged = QPoint(row, col);
    qDebug()<<beingDragged;
    moves = pieces[row][col]->getMoves(pieces, beingDragged);
    QPixmap pixmap = pieces[row][col]->pixmap(Qt::ReturnByValue);
    QByteArray data;
    QDataStream dataStream(&data, QIODevice::WriteOnly);
    dataStream<<pixmap<<QPoint(child->pos());
    QMimeData* mimeData = new QMimeData();
    mimeData->setData("application/x-dnditemdata",data);
    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(child->pos());
    qDebug()<<moves;
    for(QPoint p : moves){
        Square * current = squares[p.rx()][p.ry()];
        if(current->isLight()){
            current->setColor("#86B8FD");
        }else{
            current->setColor("#4A94FC");
        }
    }
    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        for(QPoint p : moves){
            squares[p.rx()][p.ry()]->resetColor();
        }
    } else {
        squares[row][col]->show();
    }
}



void Board::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {

        if (event->source() == this) {
            QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
            QDataStream dataStream(&itemData, QIODevice::ReadOnly);
            int c = std::min(event->pos().rx()/(width()/8), 7);
            int r = std::min(event->pos().ry()/(height()/8), 7);
            int r2 = beingDragged.rx();
            int c2 = beingDragged.ry();
            Square *sq = squares[r][c];
            QPixmap pixmap;
            QPoint offset;
            dataStream >> pixmap >> offset;
            bool allowedMove = false;
            for(QPoint p: moves){
                if(c == p.ry() && r == p.rx()){
                    allowedMove = true;
                    break;
                }
            }
            if(pieces[r][c]!=nullptr && allowedMove){
                allowedMove = false;
                if(pieces[r][c]->isWhite() != pieces[r2][c2]->isWhite()){
                    allowedMove = true;
                }
            }
            if(allowedMove){
                pieces[r][c] = std::move(pieces[r2][c2]);
                pieces[r][c]->setParent(sq);
                pieces[r][c]->show();
                pieces[r][c]->move();
                whiteTurn = !whiteTurn;
            }
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}


void Board::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Board::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

