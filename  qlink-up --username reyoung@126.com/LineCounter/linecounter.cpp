//*******************************************************************************//
//Name :      Reyoung
//School :      Tju
//QQ :      383147262
//licence :  LGPL
//*******************************************************************************//
#include "linecounter.h"
#include "ui_linecounter.h"
#include <QDebug>
LineCounter::LineCounter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LineCounter)
{
    ui->setupUi(this);
    this->manager = new fileManager(this);
    this->ui->horizontalLayout->addWidget(this->manager);
    this->connect(this->ui->countButton,SIGNAL(clicked()),this,SLOT(countStart()));
}

LineCounter::~LineCounter()
{
    delete ui;
}

void LineCounter::changeEvent(QEvent *e)
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

void LineCounter::countStart()
{
    unsigned long long count =0;
    QString fn=manager->getCurrentFileName();
    do{
        Window::makeProListFile(fn);

        QFile *file;
        file = new QFile("list.txt",this);
        file->open(QFile::ReadOnly);
        QTextStream fin(file);
        while(!fin.atEnd())
        {
            QFile* file2;
            file2 = new QFile(fin.readLine(),this);
            if(file2->open(QFile::ReadOnly))
            {
                QTextStream fin2(file2);
                QString str = fin2.readAll();
                for(int i=0;i<str.size();i++)
                {
                    if(str[i]=='\n')
                        count++;
                }
            }
            delete file2;
        }
        delete file;
        fn = manager->getNextFileName();
    }while(!fn.isEmpty());
    this->ui->numLabel->setText(tr("%1").arg(count));
}
