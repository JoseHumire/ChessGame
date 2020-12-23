#ifndef CHECKMATE_H
#define CHECKMATE_H

#include <QDialog>

namespace Ui {
class CheckMate;
}

class CheckMate : public QDialog
{
    Q_OBJECT

public:
    explicit CheckMate(QWidget *parent = nullptr);
    ~CheckMate();
    void setWinner(bool);

private:
    Ui::CheckMate *ui;
    bool whiteWins = false;
};

#endif // CHECKMATE_H
