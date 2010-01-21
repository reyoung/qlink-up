/********************************************************************************
** Form generated from reading UI file 'playwidget.ui'
**
** Created: Thu Jan 21 10:49:50 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYWIDGET_H
#define UI_PLAYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayWidget
{
public:

    void setupUi(QWidget *PlayWidget)
    {
        if (PlayWidget->objectName().isEmpty())
            PlayWidget->setObjectName(QString::fromUtf8("PlayWidget"));
        PlayWidget->resize(320, 240);
        PlayWidget->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(PlayWidget);

        QMetaObject::connectSlotsByName(PlayWidget);
    } // setupUi

    void retranslateUi(QWidget *PlayWidget)
    {
        PlayWidget->setWindowTitle(QApplication::translate("PlayWidget", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PlayWidget: public Ui_PlayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYWIDGET_H
