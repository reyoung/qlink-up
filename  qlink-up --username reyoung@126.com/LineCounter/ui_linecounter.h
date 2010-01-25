/********************************************************************************
** Form generated from reading UI file 'linecounter.ui'
**
** Created: Sun Jan 24 23:32:50 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINECOUNTER_H
#define UI_LINECOUNTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LineCounter
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *fileManagerLayout;
    QVBoxLayout *verticalLayout;
    QLabel *numLabel;
    QPushButton *countButton;

    void setupUi(QWidget *LineCounter)
    {
        if (LineCounter->objectName().isEmpty())
            LineCounter->setObjectName(QString::fromUtf8("LineCounter"));
        LineCounter->resize(395, 347);
        horizontalLayout = new QHBoxLayout(LineCounter);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fileManagerLayout = new QVBoxLayout();
        fileManagerLayout->setSpacing(6);
        fileManagerLayout->setObjectName(QString::fromUtf8("fileManagerLayout"));

        horizontalLayout->addLayout(fileManagerLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        numLabel = new QLabel(LineCounter);
        numLabel->setObjectName(QString::fromUtf8("numLabel"));

        verticalLayout->addWidget(numLabel);

        countButton = new QPushButton(LineCounter);
        countButton->setObjectName(QString::fromUtf8("countButton"));

        verticalLayout->addWidget(countButton);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(LineCounter);

        QMetaObject::connectSlotsByName(LineCounter);
    } // setupUi

    void retranslateUi(QWidget *LineCounter)
    {
        LineCounter->setWindowTitle(QApplication::translate("LineCounter", "LineCounter", 0, QApplication::UnicodeUTF8));
        numLabel->setText(QApplication::translate("LineCounter", "TextLabel", 0, QApplication::UnicodeUTF8));
        countButton->setText(QApplication::translate("LineCounter", "count", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LineCounter: public Ui_LineCounter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINECOUNTER_H
