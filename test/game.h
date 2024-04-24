#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include"qlabel.h"
#include <QPointer>
#include"qvector.h"
#include"enemy.h"
#include"adventure.h"



namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();




     static int Attack;

     static int Defend;

     static int Round;

     struct item_menber
     {
         QPoint pos;
         bool flag;
     };

     enemy *emy;
     adventure *adv;

private:
    Ui::game *ui;

signals:

    void TP(const QPoint& target);
public slots :


    void showvalue(int attack,int defend);
    void doremove_emy(QPoint pos);
    void doremove_adv(QPoint pos);



public:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();



    QVector<QPoint> labelCoordinates_barricade = {
        {200, 0},{250, 0},{450, 0},{500, 0}, {550, 0},{600, 0},{800, 0},{850, 0},
        {200, 50},{350, 50},{450, 50},{650, 50},{750, 50},{950, 50},
        {200, 100},{400, 100},{750, 100},{850, 100},{900, 100},{950, 100},
        {300, 150},{550, 150},{600, 150},{700, 150},{850, 150},
        {200, 200},{250, 200},{300, 200},{450, 200},{850, 200},
        {200, 250},{450, 250},{550, 250},{700, 250},{750, 250},
        {300, 300},{450, 300},{550, 300},{600, 300},{750, 300},{900, 300},
        {300, 350},{450, 350},{550, 350},{600, 350},{750, 350},{900, 350},
        {200, 400},{300, 400},{400, 400},{600, 400},{800, 400},{850, 400},
        {300, 450},{500, 450},{650, 450},{800, 450}

    };


};




#endif // GAME_H
