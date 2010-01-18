#include "nameanddescriptionwidget.h"
#include "ui_nameanddescriptionwidget.h"
#include <QDebug>

NameAndDescriptionWidget::NameAndDescriptionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NameAndDescriptionWidget)
{
    ui->setupUi(this);
    this->init();
}

NameAndDescriptionWidget::~NameAndDescriptionWidget()
{
    delete ui;
}

void NameAndDescriptionWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void NameAndDescriptionWidget::init()
{
    this->setMinimumWidth(200);
    this->ui->description->setMinimumHeight(430);
    QFont temp;
    temp.setPixelSize(18);
    this->ui->description->setFont(temp);
    this->indexChange(-1);
    this->show();
}

void NameAndDescriptionWidget::indexChange(int index)
{
    this->ui->PicLabel->setPixmap(QPixmap(tr("PIC/%1.bmp").arg(index)));
    QFile* file;
    file =new QFile(tr("PIC/%1.dat").arg(index));
    file->open(QFile::ReadOnly);
    QTextStream fin(file);
    QString name,description;
    name = fin.readLine();
    description = fin.readAll();
    this->ui->nameLabel->setText(name);
    this->ui->description->setText(description);
    delete file;

}

void NameAndDescriptionWidget::paintEvent(QPaintEvent *e)
{
}
