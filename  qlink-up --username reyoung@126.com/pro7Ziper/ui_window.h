/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created: Fri Jan 22 12:20:28 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *openFileName;
    QPushButton *open;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *saveFileName;
    QPushButton *save;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *start;
    QTextBrowser *processBrowser;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(600, 400);
        verticalLayout_3 = new QVBoxLayout(Window);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        openFileName = new QLineEdit(Window);
        openFileName->setObjectName(QString::fromUtf8("openFileName"));

        horizontalLayout->addWidget(openFileName);

        open = new QPushButton(Window);
        open->setObjectName(QString::fromUtf8("open"));

        horizontalLayout->addWidget(open);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        saveFileName = new QLineEdit(Window);
        saveFileName->setObjectName(QString::fromUtf8("saveFileName"));

        horizontalLayout_2->addWidget(saveFileName);

        save = new QPushButton(Window);
        save->setObjectName(QString::fromUtf8("save"));

        horizontalLayout_2->addWidget(save);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(Window);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        verticalLayout->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));

        verticalLayout->addWidget(radioButton_5);


        horizontalLayout_3->addWidget(groupBox);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        start = new QPushButton(Window);
        start->setObjectName(QString::fromUtf8("start"));

        horizontalLayout_4->addWidget(start);


        verticalLayout_3->addLayout(horizontalLayout_4);

        processBrowser = new QTextBrowser(Window);
        processBrowser->setObjectName(QString::fromUtf8("processBrowser"));

        verticalLayout_3->addWidget(processBrowser);


        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", 0, QApplication::UnicodeUTF8));
        open->setText(QApplication::translate("Window", "open", 0, QApplication::UnicodeUTF8));
        save->setText(QApplication::translate("Window", "save", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Window", "Compress Level", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("Window", "1", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("Window", "2", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("Window", "3", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("Window", "4", 0, QApplication::UnicodeUTF8));
        radioButton_5->setText(QApplication::translate("Window", "5", 0, QApplication::UnicodeUTF8));
        start->setText(QApplication::translate("Window", "start", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
