/********************************************************************************
** Form generated from reading UI file 'nameanddescriptionwidget.ui'
**
** Created: Sun Jan 17 11:12:14 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAMEANDDESCRIPTIONWIDGET_H
#define UI_NAMEANDDESCRIPTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NameAndDescriptionWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *PicLabel;
    QLabel *label;
    QLabel *nameLabel;
    QTextBrowser *description;

    void setupUi(QWidget *NameAndDescriptionWidget)
    {
        if (NameAndDescriptionWidget->objectName().isEmpty())
            NameAndDescriptionWidget->setObjectName(QString::fromUtf8("NameAndDescriptionWidget"));
        NameAndDescriptionWidget->resize(353, 321);
        verticalLayout = new QVBoxLayout(NameAndDescriptionWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        PicLabel = new QLabel(NameAndDescriptionWidget);
        PicLabel->setObjectName(QString::fromUtf8("PicLabel"));

        horizontalLayout->addWidget(PicLabel);

        label = new QLabel(NameAndDescriptionWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        nameLabel = new QLabel(NameAndDescriptionWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        horizontalLayout->addWidget(nameLabel);


        verticalLayout->addLayout(horizontalLayout);

        description = new QTextBrowser(NameAndDescriptionWidget);
        description->setObjectName(QString::fromUtf8("description"));

        verticalLayout->addWidget(description);


        retranslateUi(NameAndDescriptionWidget);

        QMetaObject::connectSlotsByName(NameAndDescriptionWidget);
    } // setupUi

    void retranslateUi(QWidget *NameAndDescriptionWidget)
    {
        NameAndDescriptionWidget->setWindowTitle(QApplication::translate("NameAndDescriptionWidget", "Form", 0, QApplication::UnicodeUTF8));
        PicLabel->setText(QString());
        label->setText(QApplication::translate("NameAndDescriptionWidget", "Name:", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NameAndDescriptionWidget: public Ui_NameAndDescriptionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAMEANDDESCRIPTIONWIDGET_H
