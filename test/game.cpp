#include"game.h"
#include "ui_game.h"
#include"QPushButton"
#include"qlabel.h"
#include"qstring.h"
#include<qmessagebox.h>
#include <QRandomGenerator>
#include <QPointer>




int game::Attack=130;
int game::Defend=130;
int game::Round=1;

struct item_menber
{
    QPoint pos;
    bool flag;
};
QVector<item_menber> labelCoordinates_enemy ={
    {QPoint(500,100),false},
    {QPoint(400,200),false}, {QPoint(650,200),false},
    {QPoint(850,250),false},
    {QPoint(250,300),false},
    {QPoint(350,400),false}

};
QVector<item_menber> labelCoordinates_adventure ={
    {QPoint(650,0),false},
    {QPoint(250,100),false},
    {QPoint(750,150),false},
    {QPoint(500,350),false},
    {QPoint(750,400),false},
    {QPoint(950,450),false}
};


bool isInCoordinates_barricade(const QVector<QPoint>& coordinates, const QPoint& target);
bool isInCoordinates_enemy(const QVector<item_menber>& coordinates, const QPoint& target);
bool isInCoordinates_adventure(const QVector<item_menber>& coordinates, const QPoint& target);
bool checkToF(QVector<item_menber>& coordinates, const QPoint& target);
void updateFlag(QVector<item_menber>& coordinates,QPoint& pos);
void resetCoordinate(QVector<item_menber>& emy, QVector<item_menber>& adv);






game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    emy=new enemy;
    adv = new adventure;
    ui->label_attack->setText("攻击 ="+QString::number(game::Attack));
    ui->label_defend->setText("防御 ="+QString::number(game::Defend));
    ui->label_round->setText("第"+QString::number(game::Round)+"轮");

connect(ui->pushButton, &QPushButton::clicked, this, &game::on_pushButton_clicked);
connect(ui->pushButton_2, &QPushButton::clicked, this, &game::on_pushButton_2_clicked);
connect(ui->pushButton_3, &QPushButton::clicked, this, &game::on_pushButton_3_clicked);
connect(ui->pushButton_4, &QPushButton::clicked, this, &game::on_pushButton_4_clicked);
connect(emy,&enemy::updatavalue,this,&game::showvalue);
connect(adv,&adventure::updatavalue,this,&game::showvalue);
connect(this,&game::TP,emy,&enemy::getTP);
connect(this,&game::TP,adv,&adventure::getTP);
connect(emy,&enemy::remove,this,&game::doremove_emy);
connect(adv,&adventure::remove,this,&game::doremove_adv);


// }
}

game::~game()
{
    delete ui;
}



void game::on_pushButton_clicked()
{



    QPoint pos = ui->label->pos();

    pos.setY(pos.y() - 50);           // 上

    if(pos.y()>=0&&isInCoordinates_barricade(labelCoordinates_barricade,pos)!=true)
    //
    {
        if(checkToF(labelCoordinates_enemy,pos)==false&&
            isInCoordinates_enemy(labelCoordinates_enemy,pos)==true){

            emy->show();
            emit TP(pos);


        }
        else if(checkToF(labelCoordinates_adventure,pos)==false&&
                   isInCoordinates_adventure(labelCoordinates_adventure,pos)==true){
          adv->show();
          emit TP(pos);

        }

        ui->label->move(pos);
        ui->label->raise();
    }



}

void game::on_pushButton_2_clicked()
{
    QPoint pos = ui->label->pos();    
      pos.setY(pos.y() + 50);
    if(pos.y()<=450&&isInCoordinates_barricade(labelCoordinates_barricade,pos)!=true)
                                                                      //下
      {
          if(checkToF(labelCoordinates_enemy,pos)==false&&
            isInCoordinates_enemy(labelCoordinates_enemy,pos)==true)
        {

            emy->show();
            emit TP(pos);

        }
          else  if(checkToF(labelCoordinates_adventure,pos)==false&&
                     isInCoordinates_adventure(labelCoordinates_adventure,pos)==true)
          {
              adv->show();
              emit TP(pos);

          }

          ui->label->move(pos);
         ui->label->raise();
      }

}
void game::on_pushButton_3_clicked()
{


    QPoint pos = ui->label->pos();

    pos.setX(pos.x() + 50);           //右
    if(pos.x()<=950&&isInCoordinates_barricade(labelCoordinates_barricade,pos)!=true){

        if(checkToF(labelCoordinates_enemy,pos)==false&&
            isInCoordinates_enemy(labelCoordinates_enemy,pos)==true)
        {

            emy->show();
            emit TP(pos);

        }
        else if(checkToF(labelCoordinates_adventure,pos)==false&&
                   isInCoordinates_adventure(labelCoordinates_adventure,pos)==true)
        {
            adv->show();
            emit TP(pos);

        }
        ui->label->move(pos);
        ui->label->raise();

    }

}

void game::on_pushButton_4_clicked()
{
    QPoint pos = ui->label->pos();

    pos.setX(pos.x() - 50);          //左
    if(pos.x()>=200&&isInCoordinates_barricade(labelCoordinates_barricade,pos)!=true){

        if(checkToF(labelCoordinates_enemy,pos)==false&&
            isInCoordinates_enemy(labelCoordinates_enemy,pos)==true)
        {

            emy->show();
            emit TP(pos);

        }
        else if(checkToF(labelCoordinates_adventure,pos)==false&&
                   isInCoordinates_adventure(labelCoordinates_adventure,pos)==true)
     {
         adv->show();
         emit TP(pos);

     }
    if(pos.y()==450&&pos.x()==200){
         if(game::Attack<999&&game::Defend<999){

         QMessageBox::information(this,"终点","下一关,返回起点！");

        pos.setX(950);
        pos.setY(0);
        ui->label->move(pos);
        resetCoordinate(labelCoordinates_enemy,labelCoordinates_adventure);
        game::Round+=1;

        ui->label_round->setText("第"+QString::number(game::Round)+"轮");
        ui->label->move(pos);
        ui->label->raise();
      }else{
          QMessageBox::information(this,"终点","恭喜通关，您的成绩为: "+QString::number(game::Round)+" 轮");

      }

    }


      ui->label->move(pos);
      ui->label->raise();


    }
}

void game::showvalue(int attack, int defend)
{
    ui->label_attack->setText("攻击 ="+QString::number(attack));
    ui->label_defend->setText("防御 ="+QString::number(defend));
}



bool isInCoordinates_barricade(const QVector<QPoint>& labelCoordinates_barricade, const QPoint& target) {
    for (const auto& coord : labelCoordinates_barricade) {
        if (coord == target) {
            return true;
        }
    }
    return false;
}
bool isInCoordinates_enemy(const QVector<item_menber>& coordinates, const QPoint& target) {
    for (const item_menber& item : coordinates) {
        if (item.pos == target) {
            return true;
        }
    }
    return false;
}


bool isInCoordinates_adventure(const QVector<item_menber>& labelCoordinates_adventure, const QPoint& target){

    for (const item_menber& item : labelCoordinates_adventure) {
        if (item.pos == target) {
            return true;
        }
    }
    return false;

}


bool checkToF(QVector<item_menber> &coordinates, const QPoint &target){

    bool TF=false;
    for (auto& item : coordinates) {
        if (item.pos == target&&item.flag==true) {
            TF=true;
            break;
        }
    }
    return TF;
}


void game::doremove_emy(QPoint pos){

     updateFlag(labelCoordinates_enemy, pos);

}
void game::doremove_adv(QPoint pos){

    updateFlag(labelCoordinates_adventure, pos);

}

void updateFlag(QVector<item_menber> &coordinates, QPoint &pos){
        for (auto& item : coordinates) {
            if (item.pos == pos) {
                item.flag = true;
                break;
            }
        }
}


void resetCoordinate(QVector<item_menber>& emy, QVector<item_menber>& adv){
    for (auto& item : emy) {
        item.flag = false;
    }
    for (auto& item : adv) {
        item.flag = false;
    }

}
