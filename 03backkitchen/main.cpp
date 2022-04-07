#include "mainwindow.h"

#include <QApplication>
#include <QProcessEnvironment>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    页面重新加载

    int ret = a.exec();
    if (ret == 773) {
        QProcess::startDetached(qApp->applicationFilePath(), QStringList());
        return 0;
    }
    return ret;
}
