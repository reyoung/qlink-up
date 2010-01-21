/********************************************************************************
** Form generated from reading UI file 'nameanddescriptionwidget.ui'
**
** Created: Thu Jan 21 20:12:31 2010
**      by: Qt User Interface Compiler version 4.6.1
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
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NameAndDescriptionWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *PicLabel;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *nameLabel;
    QSpacerItem *verticalSpacer_4;
    QTextBrowser *description;

    void setupUi(QWidget *NameAndDescriptionWidget)
    {
        if (NameAndDescriptionWidget->objectName().isEmpty())
            NameAndDescriptionWidget->setObjectName(QString::fromUtf8("NameAndDescriptionWidget"));
        NameAndDescriptionWidget->resize(353, 321);
        verticalLayout_3 = new QVBoxLayout(NameAndDescriptionWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        PicLabel = new QLabel(NameAndDescriptionWidget);
        PicLabel->setObjectName(QString::fromUtf8("PicLabel"));
        PicLabel->setMinimumSize(QSize(50, 80));
        PicLabel->setMaximumSize(QSize(50, 80));

        horizontalLayout->addWidget(PicLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(NameAndDescriptionWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAutoFillBackground(false);
        label->setFrameShape(QFrame::NoFrame);

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        nameLabel = new QLabel(NameAndDescriptionWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        verticalLayout_2->addWidget(nameLabel);

        verticalSpacer_4 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        description = new QTextBrowser(NameAndDescriptionWidget);
        description->setObjectName(QString::fromUtf8("description"));
        description->setAutoFillBackground(false);
        description->setStyleSheet(QString::fromUtf8("background-color:rgba(255, 255, 255, 200);"));

        verticalLayout_3->addWidget(description);


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
