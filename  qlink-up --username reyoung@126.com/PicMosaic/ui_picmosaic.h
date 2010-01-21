/********************************************************************************
** Form generated from reading UI file 'picmosaic.ui'
**
** Created: Thu Jan 21 22:33:22 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICMOSAIC_H
#define UI_PICMOSAIC_H

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

class Ui_PicMosaic
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *loadFile;
    QPushButton *reset;
    QPushButton *stop;

    void setupUi(QWidget *PicMosaic)
    {
        if (PicMosaic->objectName().isEmpty())
            PicMosaic->setObjectName(QString::fromUtf8("PicMosaic"));
        PicMosaic->resize(299, 275);
        verticalLayout = new QVBoxLayout(PicMosaic);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(PicMosaic);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        loadFile = new QPushButton(PicMosaic);
        loadFile->setObjectName(QString::fromUtf8("loadFile"));

        horizontalLayout->addWidget(loadFile);

        reset = new QPushButton(PicMosaic);
        reset->setObjectName(QString::fromUtf8("reset"));

        horizontalLayout->addWidget(reset);

        stop = new QPushButton(PicMosaic);
        stop->setObjectName(QString::fromUtf8("stop"));

        horizontalLayout->addWidget(stop);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PicMosaic);

        QMetaObject::connectSlotsByName(PicMosaic);
    } // setupUi

    void retranslateUi(QWidget *PicMosaic)
    {
        PicMosaic->setWindowTitle(QApplication::translate("PicMosaic", "PicMosaic", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PicMosaic", "PicLabel", 0, QApplication::UnicodeUTF8));
        loadFile->setText(QApplication::translate("PicMosaic", "Load File", 0, QApplication::UnicodeUTF8));
        reset->setText(QApplication::translate("PicMosaic", "Reset", 0, QApplication::UnicodeUTF8));
        stop->setText(QApplication::translate("PicMosaic", "Stop", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PicMosaic: public Ui_PicMosaic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICMOSAIC_H
