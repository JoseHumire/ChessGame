#include "square.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "rook.h"
#include <QtGui>
#include <QSize>
extern bool whiteTurn;
Square::Square()
{
}

Square::Square(QBrush* brush, int i, QWidget *parent):
    QWidget(parent),
    brush{brush}
{
    piece = nullptr;
    setAcceptDrops(true);
    std::string color = "light";
    if (i<20)
        color = "dark";

    if (i==0 || i ==7 || i==56 || i==63){
        piece = std::make_unique<Rook>(color, this);
    }
    else if (i==1 || i==6 || i==57 || i==62){
        piece = std::make_unique<Knight>(color, this);
    }
    else if (i==2 || i==5 || i==58 || i==61){
        piece = std::make_unique<Bishop>(color, this);
    }
    else if (i==3 || i==59){
        piece = std::make_unique<Queen>(color, this);
    }
    else if (i==4 || i==60){
        piece = std::make_unique<King>(color, this);
    }
    else if ((i>=8 && i<=15) || (i>=48 && i<=55)){
        piece = std::make_unique<Pawn>(color, this);
    }
    if (piece != nullptr){
        piece->show();
    }
}

void Square::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    double height = this->height();
    double width = this->width();
    painter.setBrush(*brush);
    QPen pen;
    pen.setStyle(Qt::NoPen);
    painter.setPen(pen);
    painter.drawRect(0, 0, width, height);
    QSize s(width, height);
    this->setMinimumSize(s);
    this->setMaximumSize(s);
    if (piece != nullptr){
        piece->setMaximumSize(s);
        piece->setMinimumSize(s);
    }
}

void Square::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if(child == nullptr){
        return;
    }
    if(piece->isWhite() != whiteTurn)
        return;
    QPixmap pixmap = child->pixmap(Qt::ReturnByValue);
    QByteArray data;
    QDataStream dataStream(&data, QIODevice::WriteOnly);
    dataStream<<QPoint(event->pos());
    QMimeData* mimeData = new QMimeData();
    mimeData->setData("application/x-dnditemdata",data);

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());
    drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);

}



void Square::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;
        Square* s = static_cast<Square *>(event->source());
        if(this->piece!=nullptr){
            if(s->piece->isWhite() != this->piece->isWhite()){
                this->piece = std::move(s->piece);
                this->piece->setParent(this);
                this->piece->show();
                whiteTurn = !whiteTurn;
            }
        }else{
            this->piece = std::move(s->piece);
            this->piece->setParent(this);
            this->piece->show();
            whiteTurn = !whiteTurn;
        }
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

void Square::dragEnterEvent(QDragEnterEvent *event)
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

void Square::dragMoveEvent(QDragMoveEvent *event)
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
