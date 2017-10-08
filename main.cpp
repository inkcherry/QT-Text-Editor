#include "mainwindow.h"
#include <QApplication>
#include "dialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    Dialog dlg;
//    if(dlg.exec()==QDialog::Accepted)
//        {
//        w.show();
//        return a.exec();
//    }
    w.show();

    return a.exec();
}
