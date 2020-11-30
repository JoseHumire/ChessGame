#include "square.h"
#include <QtGui>
#include <QSize>

const QString Square::dark = "#c56c00";
const QString Square::light = "#F8DFA1";

Square::Square()
{
}

Square::Square(QString _color, bool _isLight):
    color{_color},
    colorIsLight{_isLight}
{
    this->setColor(color);
}

void Square::setColor(QString _color){
    QString style = "QLabel { background-color : "+_color+"; }";
    this->setStyleSheet(style);
}

void Square::resetColor(){
    this->setColor(color);
}

bool Square::isLight(){
    return colorIsLight;
}
