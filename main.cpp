#include "mainwindow.h"

#include <QApplication>
#include "board.h"
#include "square.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
