#include "widget.h"
#include"QSqlDatabase"
#include<QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();

    // QSqlDatabase database;
    // database=QSqlDatabase::addDatabase("QSQLITE");
    // database.setDatabaseName("qtsqlite");

    // if(!database.open()){
    //     qDebug()<<"链接不成功";

    // }


}
