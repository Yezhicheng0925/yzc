#include "adventure.h"
#include"game.h"
#include "ui_adventure.h"
#include <QRandomGenerator>
#include <QDateTime>
#include<qmessagebox.h>




adventure::adventure(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::adventure)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&adventure::try_pushbutton);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&adventure::close_pushbutton);




}

adventure::~adventure()
{
    delete ui;
}

void adventure::try_pushbutton(){

        QRandomGenerator::securelySeeded();
    int flag=QRandomGenerator::global()->bounded(1,6);

        switch (flag) {
    case 1:{
            game::Attack-=5;
            QMessageBox::information(this,"奇遇","倒霉，攻击-5");
            break;
    }
    case 2:{
            game::Defend-=5;
            QMessageBox::information(this,"奇遇","倒霉，防御-5");
            break;
    }
    case 3:{
            game::Attack+=5;
            QMessageBox::information(this,"奇遇","惊喜，攻击+5");
            break;
    }
    case 4:{
            game::Defend+=5;
            QMessageBox::information(this,"奇遇","惊喜，防御+5");
            break;
    }
    case 5:{
            game::Attack+=10;
            QMessageBox::information(this,"奇遇","天赐，攻击+10");
            break;
    }
    case 6:{
            game::Defend+=10;
            QMessageBox::information(this,"奇遇","天赐，防御+10");
            break;
    }
        default:
            break;
        }
        emit updatavalue(game::Attack,game::Defend);

        emit remove(m_target);



        ui->pushButton->setEnabled(false);
}

void adventure::close_pushbutton(){

    ui->pushButton->setEnabled(true);
    close();
}

void adventure::getTP(const QPoint& target){
    this->m_target=target;

}
