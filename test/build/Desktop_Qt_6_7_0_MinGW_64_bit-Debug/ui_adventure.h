/********************************************************************************
** Form generated from reading UI file 'adventure.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVENTURE_H
#define UI_ADVENTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adventure
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QPushButton *pushButton_2;

    void setupUi(QWidget *adventure)
    {
        if (adventure->objectName().isEmpty())
            adventure->setObjectName("adventure");
        adventure->resize(650, 450);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(adventure->sizePolicy().hasHeightForWidth());
        adventure->setSizePolicy(sizePolicy);
        label = new QLabel(adventure);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 650, 300));
        label->setAutoFillBackground(true);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/img/suiji.jpg")));
        label->setScaledContents(true);
        pushButton = new QPushButton(adventure);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 370, 80, 60));
        label_2 = new QLabel(adventure);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 310, 311, 40));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);
        pushButton_2 = new QPushButton(adventure);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(400, 370, 80, 60));

        retranslateUi(adventure);

        QMetaObject::connectSlotsByName(adventure);
    } // setupUi

    void retranslateUi(QWidget *adventure)
    {
        adventure->setWindowTitle(QCoreApplication::translate("adventure", "\345\245\207\351\201\207", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("adventure", "\350\257\225\350\257\225\346\211\213\346\260\224", nullptr));
        label_2->setText(QCoreApplication::translate("adventure", "\344\277\241\344\273\260\345\200\274\350\266\212\351\253\230\357\274\214\350\216\267\345\276\227\345\212\240\346\210\220\347\232\204\345\207\240\347\216\207\350\266\212\345\244\247(\347\234\237\347\232\204\345\220\227\357\274\237)", nullptr));
        pushButton_2->setText(QCoreApplication::translate("adventure", "\347\246\273\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adventure: public Ui_adventure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVENTURE_H
