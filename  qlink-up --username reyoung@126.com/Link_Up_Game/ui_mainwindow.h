/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jan 21 20:12:31 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionClose;
    QAction *actionMusic_On_Off;
    QAction *actionAbout_Me;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *newGameButton;
    QPushButton *promptButton;
    QPushButton *pauseButton;
    QSpacerItem *horizontalSpacer;
    QLabel *scoreLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QHBoxLayout *timeLineLayout;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *playWidgetLayout;
    QVBoxLayout *nameAndDescription;
    QMenuBar *menubar;
    QMenu *menuGame;
    QMenu *menuSetting;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 480);
        MainWindow->setStyleSheet(QString::fromUtf8("QLabel, QAbstractButton {\n"
"    font: bold;\n"
"	background-color:rgba(255, 255, 255, 200);\n"
"}\n"
""));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionMusic_On_Off = new QAction(MainWindow);
        actionMusic_On_Off->setObjectName(QString::fromUtf8("actionMusic_On_Off"));
        actionAbout_Me = new QAction(MainWindow);
        actionAbout_Me->setObjectName(QString::fromUtf8("actionAbout_Me"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newGameButton = new QPushButton(centralwidget);
        newGameButton->setObjectName(QString::fromUtf8("newGameButton"));

        horizontalLayout->addWidget(newGameButton);

        promptButton = new QPushButton(centralwidget);
        promptButton->setObjectName(QString::fromUtf8("promptButton"));

        horizontalLayout->addWidget(promptButton);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        horizontalLayout->addWidget(pauseButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scoreLabel = new QLabel(centralwidget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));

        horizontalLayout->addWidget(scoreLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        timeLineLayout = new QHBoxLayout();
        timeLineLayout->setObjectName(QString::fromUtf8("timeLineLayout"));

        horizontalLayout_2->addLayout(timeLineLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        playWidgetLayout = new QHBoxLayout();
        playWidgetLayout->setObjectName(QString::fromUtf8("playWidgetLayout"));

        verticalLayout->addLayout(playWidgetLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        nameAndDescription = new QVBoxLayout();
        nameAndDescription->setObjectName(QString::fromUtf8("nameAndDescription"));

        horizontalLayout_3->addLayout(nameAndDescription);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 23));
        menuGame = new QMenu(menubar);
        menuGame->setObjectName(QString::fromUtf8("menuGame"));
        menuSetting = new QMenu(menubar);
        menuSetting->setObjectName(QString::fromUtf8("menuSetting"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuGame->menuAction());
        menubar->addAction(menuSetting->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuGame->addAction(actionNew);
        menuGame->addAction(actionClose);
        menuSetting->addAction(actionMusic_On_Off);
        menuAbout->addAction(actionAbout_Me);

        retranslateUi(MainWindow);
        QObject::connect(actionClose, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "NewGame", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionMusic_On_Off->setText(QApplication::translate("MainWindow", "Music On/Off", 0, QApplication::UnicodeUTF8));
        actionAbout_Me->setText(QApplication::translate("MainWindow", "About Me", 0, QApplication::UnicodeUTF8));
        newGameButton->setText(QApplication::translate("MainWindow", "NewGame", 0, QApplication::UnicodeUTF8));
        promptButton->setText(QApplication::translate("MainWindow", "Prompt", 0, QApplication::UnicodeUTF8));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        scoreLabel->setText(QApplication::translate("MainWindow", "Score:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Time:", 0, QApplication::UnicodeUTF8));
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", 0, QApplication::UnicodeUTF8));
        menuSetting->setTitle(QApplication::translate("MainWindow", "Setting", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
