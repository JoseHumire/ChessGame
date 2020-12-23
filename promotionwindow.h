#ifndef PROMOTIONWINDOW_H
#define PROMOTIONWINDOW_H

#include <QDialog>

namespace Ui {
class PromotionWindow;
}

class PromotionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PromotionWindow(QWidget *parent = nullptr);
    ~PromotionWindow();
    char getPiece(){return piece;};
    std::string color;
    void setColor(std::string _color);

private slots:
    void on_queenB_clicked();

    void on_knightB_clicked();

    void on_rookB_clicked();

    void on_bishopB_clicked();

private:
    Ui::PromotionWindow *ui;
    char piece = 'Q';
    void setPiece(char);
};

#endif // PROMOTIONWINDOW_H
