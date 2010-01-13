#include "playwidget.h"
#include "ui_playwidget.h"

PlayWidget::PlayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayWidget)
{
    ui->setupUi(this);
    this->setMaximumSize(640,480);
    this->setMinimumSize(640,480);
}

PlayWidget::~PlayWidget()
{
    delete ui;
}

void PlayWidget::changeEvent(QEvent *e)
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
