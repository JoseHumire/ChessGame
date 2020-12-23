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

private:
    Ui::CheckMate *ui;
};

#endif // CHECKMATE_H
