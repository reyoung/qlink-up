/********************************************************************************
** Form generated from reading UI file 'testwindows.ui'
**
** Created: Thu Jan 21 15:43:20 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWINDOWS_H
#define UI_TESTWINDOWS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWindows
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestWindows)
    {
        if (TestWindows->objectName().isEmpty())
            TestWindows->setObjectName(QString::fromUtf8("TestWindows"));
        TestWindows->resize(600, 400);
        menuBar = new QMenuBar(TestWindows);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        TestWindows->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestWindows);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TestWindows->addToolBar(mainToolBar);
        centralWidget = new QWidget(TestWindows);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TestWindows->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TestWindows);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TestWindows->setStatusBar(statusBar);

        retranslateUi(TestWindows);

        QMetaObject::connectSlotsByName(TestWindows);
    } // setupUi

    void retranslateUi(QMainWindow *TestWindows)
    {
        TestWindows->setWindowTitle(QApplication::translate("TestWindows", "TestWindows", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestWindows: public Ui_TestWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWINDOWS_H
