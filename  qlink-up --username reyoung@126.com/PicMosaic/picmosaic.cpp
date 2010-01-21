#include "picmosaic.h"
#include "ui_picmosaic.h"

PicMosaic::PicMosaic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PicMosaic)
{
    this->pixmap = new QPixmap;
    this->thread = new mosaicThread(this);
    ui->setupUi(this);
    this->ui->label->setPixmap(*this->pixmap);
    this->connect(this->thread,SIGNAL(throwBlock(Block)),this,SLOT(handleBlock(Block)));
    this->connect(this->thread,SIGNAL(finished()),this,SLOT(finishSlot()));
    this->ui->reset->setEnabled(false);
    this->ui->stop->setEnabled(false);
    this->connect(this->ui->stop,SIGNAL(clicked()),this->thread,SLOT(stop()));
}

PicMosaic::~PicMosaic()
{
    delete ui;
}

void PicMosaic::changeEvent(QEvent *e)
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

void PicMosaic::on_loadFile_clicked()
{
    do{
        this->currentFn = QFileDialog::getOpenFileName(this,tr("Open file"),QDir::currentPath(),"*.bmp *.png *.jpg");
    }while(this->currentFn.isEmpty());
    this->loadFile(this->currentFn);
}

void PicMosaic::loadFile(const QString &fn)
{
    delete this->pixmap;
    QImage image(fn);

    this->pixmap = new QPixmap(image.width()/2,image.height()/2);
    //this->pixmap->fill(QColor::fromRgb(255,255,255));
    this->thread->setImage(image);
    this->ui->reset->setEnabled(true);
    this->ui->stop->setEnabled(true);
}

void PicMosaic::handleBlock(Block a)
{
    QPainter painter(this->pixmap);
    painter.setBrush(QBrush(a.color()));
    painter.setPen(Qt::NoPen);
    painter.drawRect(a.rect());
    this->ui->label->setPixmap(*this->pixmap);
}

void PicMosaic::finishSlot()
{
    this->ui->reset->setEnabled(false);
    this->ui->stop->setEnabled(false);
}

void PicMosaic::on_reset_clicked()
{
    this->loadFile(this->currentFn);
}
