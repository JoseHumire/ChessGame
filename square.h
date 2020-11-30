#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <QWidget>
#include <QLabel>
#include <memory>

class Square : public QLabel
{
    Q_OBJECT
public:
    Square();
    Square(QString, bool);
    void setColor(QString);
    void resetColor();
    bool isLight();
    static const QString dark;
    static const QString light;
protected:
    QString color;
    bool colorIsLight;
};
#endif // SQUARE_H
