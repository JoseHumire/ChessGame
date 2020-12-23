#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QVector>
#include "square.h"
#include "piece.h"
namespace Ui {
    class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

private:
    Ui::Board *ui;
    std::shared_ptr<Piece> whiteKing;
    std::shared_ptr<Piece> darkKing;
    QVector<QVector<Square*>> squares{8};
    std::shared_ptr<Piece> pieces[8][8];
protected:
    void paintEvent(QPaintEvent *) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void move(std::shared_ptr<Piece>, QPoint, QPoint);
    void fakeMove(std::shared_ptr<Piece>, QPoint, QPoint);
    void calcPiecesMoves();
};

#endif // BOARD_H
