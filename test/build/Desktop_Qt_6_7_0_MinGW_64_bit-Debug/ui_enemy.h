/********************************************************************************
** Form generated from reading UI file 'enemy.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENEMY_H
#define UI_ENEMY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_enemy
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *enemy)
    {
        if (enemy->objectName().isEmpty())
            enemy->setObjectName("enemy");
        enemy->resize(600, 450);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(enemy->sizePolicy().hasHeightForWidth());
        enemy->setSizePolicy(sizePolicy);
        enemy->setAutoFillBackground(false);
        enemy->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        label = new QLabel(enemy);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 40, 200, 200));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/img/Enemy .png")));
        label->setScaledContents(true);
        label_2 = new QLabel(enemy);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(430, 40, 120, 90));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(enemy);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(430, 150, 120, 90));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_3->setScaledContents(true);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(true);
        pushButton_3 = new QPushButton(enemy);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(250, 260, 80, 28));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(enemy);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(170, 320, 70, 70));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/img/attack.png);\n"
"background-color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(enemy);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(340, 320, 70, 70));
        pushButton_2->setStyleSheet(QString::fromUtf8("image: url(:/icons/img/run.png);"));

        retranslateUi(enemy);

        QMetaObject::connectSlotsByName(enemy);
    } // setupUi

    void retranslateUi(QWidget *enemy)
    {
        enemy->setWindowTitle(QCoreApplication::translate("enemy", "\346\210\230\346\226\227", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("enemy", "\344\276\246\345\257\237", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class enemy: public Ui_enemy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENEMY_H
