/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLayout>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QFrame *frame;
    QLCDNumber *lcdNumber;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_3;
    QWidget *page_2;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QStringLiteral("MyWidget"));
        MyWidget->resize(400, 300);
        frame = new QFrame(MyWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(80, 60, 120, 80));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(5);
        frame->setMidLineWidth(10);
        lcdNumber = new QLCDNumber(MyWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(110, 10, 64, 23));
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setDigitCount(7);
        lcdNumber->setProperty("value", QVariant(456.123));
        toolBox = new QToolBox(MyWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(260, 80, 72, 140));
        toolBox->setFrameShape(QFrame::Box);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 70, 27));
        toolBox->addItem(page, QString::fromUtf8("\345\245\275\345\217\213"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        toolBox->addItem(page_3, QString::fromUtf8("\351\231\214\347\224\237\344\272\272"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 70, 27));
        toolBox->addItem(page_2, QString::fromUtf8("\351\273\221\345\220\215\345\215\225"));

        retranslateUi(MyWidget);

        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MyWidget", "\345\245\275\345\217\213", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("MyWidget", "\351\231\214\347\224\237\344\272\272", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MyWidget", "\351\273\221\345\220\215\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
