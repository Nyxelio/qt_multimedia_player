#include "player.h"
#include <QApplication>
#include <QTranslator>
#include <QDir>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("../qt_multimedia_player/languages/appli_fr");
    qDebug() << QDir::currentPath();
    a.installTranslator(&translator);

    Player w;
    w.show();

    return a.exec();
}
