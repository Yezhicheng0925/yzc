#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include"QSqlDatabase"
#include<QDebug>
#include "game.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    QSqlDatabase database;
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("qtsqlite");

    if(!database.open()){
        qDebug()<<"链接不成功";

    }else{
        qDebug()<<"链接成功";
    }


    this->ppge2=new game;

    connect(ui->pushButton,&QPushButton::clicked,[=](){

        this->hide();
        this->ppge2->show();
    });
}

Widget::~Widget()
{
    delete ui;
}
