#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QVector>
#include "square.h"
namespace Ui {
    class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();
    static bool whiteTurn;

private:
    Ui::Board *ui;
    QVector<Square*> squares;
protected:
};

#endif // BOARD_H
