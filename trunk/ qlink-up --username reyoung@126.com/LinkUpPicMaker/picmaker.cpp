#include "picmaker.h"
#include "ui_picmaker.h"
#include <QDebug>

PicMaker::PicMaker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PicMaker)
{
    ui->setupUi(this);
    this->connect(this->ui->openButton,SIGNAL(clicked()),this,SLOT(openSlot()));
    this->pic=NULL;
    this->connect(this->ui->saveButton,SIGNAL(clicked()),this,SLOT(saveOnePic()));
    this->connect(this->ui->listWidget,SIGNAL(currentRowChanged(int))
                  ,this,SLOT(getInformation(int)));
    this->load();
}

PicMaker::~PicMaker()
{
    delete ui;
}

void PicMaker::changeEvent(QEvent *e)
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
void PicMaker::openSlot()
{
    this->ui->listWidget->setCurrentRow(-1);
    if(this->maybeSave())
    {
        QString fn =QFileDialog::getOpenFileName(this,tr("Open Pic"),QDir::currentPath(),tr("*.jpg *.png *.bmp"));
        QPixmap temp(fn);
        this->pic = temp.scaled(50,80);
        this->ui->PicLabel->setPixmap(pic);
    }
}
bool PicMaker::maybeSave()
{
    if(!ui->nameEdit->isModified()&&!ui->textEdit->document()->isModified())return true;
    else
    {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Application"),
                               tr("This picture\'s name and description has been modified.\n"
                                  "Do you want to save your changes?"),
                               QMessageBox::Save | QMessageBox::Discard
                               | QMessageBox::Cancel);
        if(ret==QMessageBox::Save)
        {
            this->saveOnePic();
            return true;
        }
        else if(ret==QMessageBox::Discard)
        {
            return true;
        }
        else return false;
    }
}
void PicMaker::saveOnePic()
{
    if(this->ui->listWidget->currentRow()==-1)
    {
        int index = this->ui->listWidget->count();
        this->pic.save(tr("PIC/%1.bmp").arg(index));
        QFile* file;
        file = new QFile(tr("PIC/%1.dat").arg(index),this);
        if(file->open(QFile::WriteOnly)){
            QTextStream fout(file);
            fout<<this->ui->nameEdit->text();
            fout<<"\n";
            fout<<this->ui->textEdit->document()->toPlainText();
        }
        else
        {
            QMessageBox::warning(this,"ERROR","ERROR");
        }
        this->ui->listWidget->addItem(tr("%1\t").arg(index)
                                      +this->ui->nameEdit->text());
        this->ui->textEdit->setText(tr("Description"));
        this->ui->textEdit->document()->setModified(false);
        this->ui->nameEdit->setText(tr("Name"));
        this->ui->nameEdit->setModified(false);
        this->ui->PicLabel->setPixmap(QPixmap());

    }
    else{
        int index =this->ui->listWidget->currentRow();
        this->pic.save(tr("PIC/%1.bmp").arg(index));
        QFile* file;
        file = new QFile(tr("PIC/%1.dat").arg(index),this);
        if(file->open(QFile::WriteOnly)){
            QTextStream fout(file);
            fout<<this->ui->nameEdit->text();
            fout<<"\n";
            fout<<this->ui->textEdit->document()->toPlainText();
        }
        else
        {
            QMessageBox::warning(this,"ERROR","ERROR");
        }
        this->ui->listWidget->currentItem()->setText(tr("%1\t").arg(index)+ui->nameEdit->text());
        this->ui->textEdit->setText(tr("Description"));
        this->ui->textEdit->document()->setModified(false);
        this->ui->nameEdit->setText(tr("Name"));
        this->ui->nameEdit->setModified(false);
        this->ui->PicLabel->setPixmap(QPixmap());
        delete file;
    }
}
void PicMaker::getInformation(int index)
{
    this->maybeSave();
    QPixmap temp(tr("PIC/%1.bmp").arg(index));
    this->pic = temp;
    QFile* file;
    file = new QFile(tr("PIC/%1.dat").arg(index),this);
    file->open(QFile::ReadOnly);
    QString name,description;
    QTextStream fin(file);
    name = fin.readLine();
    description = fin.readAll();
    this->ui->PicLabel->setPixmap(this->pic);
    this->ui->nameEdit->setText(name);
    this->ui->textEdit->setText(description);
    delete file;
}
void PicMaker::closeEvent(QCloseEvent *e)
{
    if(this->maybeSave())
        e->accept();
    else
        e->ignore();
}
void PicMaker::load()
{
    int i;
    for(i=0;;i++)
    {
        QFile* file;
        file = new QFile(tr("PIC/%1.dat").arg(i),this);
        if(file->open(QFile::ReadOnly))
        {
            QTextStream fin(file);
            QString name = fin.readLine();
            this->ui->listWidget->addItem(tr("%1\t").arg(i)
                                          +name);
            delete file;
        }
        else
        {
            delete file;
            break;
        }
    }
    this->ui->listWidget->setCurrentRow(this->ui->listWidget->count()-1);
}
