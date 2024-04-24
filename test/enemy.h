#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>


namespace Ui {
class enemy;
}

class enemy : public QWidget
{
    Q_OBJECT

public:
    explicit enemy(QWidget *parent = nullptr);
    ~enemy();

    int attack;
    int defend;
    static int up;

    bool attack_click=false;
    bool detect_click=false;
    bool run_click=false;

     QPoint m_target;

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

public slots:

    void attack_pushbutton();
    void detection_pushbutton();
    void close_pushbutton();
    void getTP(const QPoint& target);

signals:
    int updatavalue(int attack,int defend);
    void remove(QPoint pos);



private:
    Ui::enemy *ui;







};

#endif // ENEMY_H
