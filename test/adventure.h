#ifndef ADVENTURE_H
#define ADVENTURE_H

#include <QWidget>


namespace Ui {
class adventure;
}

class adventure : public QWidget
{
    Q_OBJECT

public:
    explicit adventure(QWidget *parent = nullptr);
    ~adventure();

    void try_pushbutton();
    void close_pushbutton();

    struct item_menber
    {
        QPoint pos;
        bool flag;
    };
    QVector<item_menber> labelCoordinates_adventure ={
        {QPoint(650,0),false},
        {QPoint(250,100),false},
        {QPoint(750,150),false},
        {QPoint(500,350),false},
        {QPoint(750,400),false},
        {QPoint(950,450),false}
    };

 QPoint m_target;

private:
    Ui::adventure *ui;



signals:
    int updatavalue(int attack,int defend);
    void remove(QPoint pos);

public slots:
    void getTP(const QPoint& target);
};

#endif // ADVENTURE_H
