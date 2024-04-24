#include "enemy.h"
#include "game.h"
#include"ui_enemy.h"
#include <QRandomGenerator>
#include <QDateTime>
#include<qmessagebox.h>
#include<QPoint>


    int enemy::up=0;
struct item_menber
{
    QPoint pos;
    bool flag;
};
// QVector<item_menber> labelCoordinates_enemy ={
//     {QPoint(500,100),false},
//     {QPoint(400,200),false}, {QPoint(650,200),false},
//     {QPoint(850,250),false},
//     {QPoint(250,300),false},
//     {QPoint(350,400),false}

// };

enemy::enemy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::enemy)
{


    ui->setupUi(this);


    ui->label_2->setText("攻击 = ???");
    ui->label_3->setText("防御 = ???");

    connect(ui->pushButton,&QPushButton::clicked,this,&enemy::attack_pushbutton);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&enemy::close_pushbutton);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&enemy::detection_pushbutton);




}

enemy::~enemy()
{


    delete ui;

}




void enemy::detection_pushbutton(){
    QRandomGenerator::securelySeeded();


    attack = QRandomGenerator::global()->bounded(100+enemy::up,151+enemy::up);
    defend = QRandomGenerator::global()->bounded(100+enemy::up,151+enemy::up);

    ui->label_2->setText("攻击 = "+QString::number(attack));
    ui->label_3->setText("防御 = "+QString::number(defend));
    ui->pushButton_3->setEnabled(false);

    detect_click=true;
    ui->pushButton->setEnabled(true);
}

void enemy::attack_pushbutton() {
    QMessageBox msgBox(QMessageBox::Question,
                       "战斗",
                       "是否挑战？",
                       QMessageBox::Yes | QMessageBox::No);
    msgBox.setStyleSheet("background-color: white;");
    int reply = msgBox.exec();

    if (reply == QMessageBox::Yes) {
        if(game::Attack > attack && game::Defend > defend) {
            QMessageBox winMsg(QMessageBox::Information,
                               "战斗",
                               "大获全胜，攻击、防御+10",
                               QMessageBox::Ok);
            game::Attack+=10;
            game::Defend+=10;
            enemy::up+=8;
            winMsg.setStyleSheet("background-color: white;");
            winMsg.exec();
        }
        if(game::Attack >= attack && game::Defend < defend) {

        QMessageBox  winMsg2(QMessageBox::Information,
                           "战斗",
                           "胜利,攻击+10，防御-10",
                           QMessageBox::Ok);
            game::Attack+=10;
            game::Defend-=10;
            enemy::up+=5;
        winMsg2.setStyleSheet("background-color: white;");
        winMsg2.exec();

        }
        if(game::Attack < attack && game::Defend >= defend) {
            QMessageBox  winMsg3(QMessageBox::Information,
                                "战斗",
                                "战斗胜利,攻击-10，防御+10",
                                QMessageBox::Ok);
            game::Attack-=10;
            game::Defend+=10;
            enemy::up+=5;
            winMsg3.setStyleSheet("background-color: white;");
            winMsg3.exec();
        }
        if(game::Attack < attack && game::Defend < defend) {
            QMessageBox  winMsg4(QMessageBox::Information,
                                "战斗",
                                "战斗失败,攻击-10，防御-10",
                                QMessageBox::Ok);
            game::Attack-=10;
            game::Defend-=10;
            winMsg4.setStyleSheet("background-color: white;");
            winMsg4.exec();
        }

        attack_click=true;
    }
        ui->pushButton_3->setEnabled(true);

   emit remove(m_target);





}


void enemy::close_pushbutton(){

    if(detect_click==true&&attack_click==false)
        close();
    if(detect_click==true&&attack_click==true)
    {
    ui->label_2->setText("攻击 = ???");
    ui->label_3->setText("防御 = ???");

    emit updatavalue(game::Attack,game::Defend);
    detect_click=false;
    attack_click=false;
    close();
    }
    close();
}

void enemy::getTP(const QPoint& target){
    this->m_target=target;
}
