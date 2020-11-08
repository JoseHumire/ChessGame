#include "square.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "rook.h"
#include <QtGui>

Square::Square()
{
}

Square::Square(QBrush* brush, int i):
    brush{brush}
{
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

    if (piece != nullptr)
        piece->show();
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
}

