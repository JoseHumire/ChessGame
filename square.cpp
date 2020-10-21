#include "square.h"
#include <QtGui>

Square::Square()
{
}

Square::Square(QBrush* brush):
    brush{brush}
{
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
