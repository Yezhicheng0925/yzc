/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextBrowser *textBrowser;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(600, 600);
        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(160, 380, 256, 192));
        textBrowser->setAutoFillBackground(false);
        textBrowser->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgb(85, 255, 255);"));
        textBrowser->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(150, 110, 271, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);


        retranslateUi(Widget);
        QObject::connect(pushButton_3, &QPushButton::clicked, Widget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\346\216\242\347\264\242\350\277\267\345\256\253", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\277\231\346\230\257\344\270\200\346\256\265\350\257\264\346\230\216\346\226\207\345\255\227</p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\226\260\347\232\204\345\274\200\345\247\213", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
