#include "window.h"
#include "ui_window.h"
#include <QDebug>

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    ui->radioButton_5->setChecked(true);
}

Window::~Window()
{
    delete ui;
}

void Window::changeEvent(QEvent *e)
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

void Window::on_open_clicked()
{
    this->ui->openFileName->setText(
            QFileDialog::getOpenFileName(this,tr("Open File"),QDir::currentPath(),"*.pro")
            );
}

void Window::on_save_clicked()
{
    this->ui->saveFileName->setText(
            QFileDialog::getSaveFileName(this,tr("Save File"),QDir::currentPath(),"*.7z")
            );
}

void Window::on_start_clicked()
{
    this->handleBaseNameType(this->getBaseNameType());
    QProcess t;
    QStringList env = QProcess::systemEnvironment();
    env << "TMPDIR=C:\\MyApp\\temp"; // Add an environment variable
    env.replaceInStrings(QRegExp("^PATH=(.*)", Qt::CaseInsensitive), "PATH=\\1;"+QDir::currentPath());
    t.setEnvironment(env);
    QString path,name;
    path = this->ui->saveFileName->text();
    for(int i = path.size()-1;i>=0;i--)
    {
        if(path[i]=='/')
        {
            path.remove(path.size()-1,1);
            break;
        }
        else
        {
            name.push_front(path[i]);
            path.remove(path.size()-1,1);
        }
    }

    t.start(tr("7z.exe a -t7z %1 @list.txt -mx%2").arg(name).arg(this->getLevel()));
    t.waitForFinished(-1);
    this->ui->processBrowser->setText(t.readAllStandardOutput());
    for(int i=0;i<path.size();i++)
    {
        if(path[i] == '/')path[i]=QDir::separator();
    }
    QFile::copy(name,this->ui->saveFileName->text());
    QFile::remove(name);
    QFile::remove("list.txt");
}


inline int Window::getLevel()const
{
    if(this->ui->radioButton_5->isChecked())return 9;
    else if(this->ui->radioButton_4->isChecked())return 7;
    else if(this->ui->radioButton_3->isChecked())return 5;
    else if(this->ui->radioButton_2->isChecked())return 3;
    else if(this->ui->radioButton->isChecked())return 1;
    else return 0;
}

inline QString Window::getBaseName()const
{
    QString str=this->ui->openFileName->text();
    QString ret;
    for(int i=str.size()-1;i>=0;i--)
    {
        if(str[i]=='.')break;
        ret.push_front(str[i]);
    }
    return ret;
}

inline Window::BaseNameType Window::getBaseNameType()const
{
    QString bn= this->getBaseName();
    if(bn=="prO"||bn=="PRO"||bn=="PRo"||bn=="Pro"||bn=="pRO"||bn=="pRo"||bn=="pro"||bn=="PrO")
    {
        return Window::BN_PRO;
    }
    else
    {
        return Window::BN_ERR;
    }
}

inline void Window::handleBaseNameType(BaseNameType a) const
{
    switch(a)
    {
    case Window::BN_PRO:
        this->makeProListFile(this->ui->openFileName->text());
        break;
    case Window::BN_ERR:
        qDebug()<<"ERROR";
        break;
    default:
        qDebug()<<"What's this state?";
    }
}

void Window::makeProListFile(QString fn)
{
    QString path = fn;
    for(int i = path.size()-1;i>=0;i--)
    {
        if(path[i]!='/')path.remove(path.size()-1,1);
        else
        {
            break;
        }
    }
    typedef enum{
        T_SOURCES,T_HEADERS,T_FORMS,T_OTHER
    }Type;
    Type type = T_OTHER;
    QFile* file;
    file = new QFile(fn);
    if(file->open(QFile::ReadOnly));
    else
    {
        qDebug()<<"File Cannot Open";
        return ;
    }
    QString output;
    QTextStream fin(file);
    while(!fin.atEnd())
    {
        QString line = fin.readLine();
        QRegExp source("SOURCES");
        QRegExp header("HEADERS");
        QRegExp form("FORMS");
        if(source.indexIn(line)!=-1)type = T_SOURCES;
        else if(header.indexIn(line)!=-1)type = T_HEADERS;
        else if(form.indexIn(line)!=-1)type = T_FORMS;
        switch(type)
        {
        case T_OTHER:break;
        case T_SOURCES:
        case T_HEADERS:
        case T_FORMS:
            int i;
            for(i=line.size()-1;i>=0;i--)
            {
                if(line[i].isSpace())continue;
                else if(line[i]=='\\')break;
                else
                {
                    i++;
                    type = T_OTHER;
                    break;
                }
            }
            QRegExp equal("=");
            if(equal.indexIn(line)==-1)
            {
                QString tempLine;
                for(int j=0;j<i;j++)
                {
                    if(line[j].isSpace())continue;
                    tempLine.append(line[j]);
                }
                int j=0;
                for(;j<tempLine.size();j++)
                {
                    if(!tempLine[j].isSpace())break;
                }
                if(j!=tempLine.size())
                {
                    output.append(tempLine);
                    output.append("\r\n");
                }
            }
            else
            {
                QString tempLine;
                for(int j=equal.indexIn(line)+1;j<i;j++)
                {
                    if(line[j].isSpace())continue;
                    tempLine.append(line[j]);
                }
                int j=0;
                for(;j<tempLine.size();j++)
                {
                    if(!tempLine[j].isSpace())break;
                }
                if(j!=tempLine.size())
                {
                    output.append(tempLine);
                    output.append("\r\n");
                }
            }
            break;
        }
    }
    QFile* outFile;
    outFile = new QFile("list.txt");
    outFile->open(QFile::WriteOnly);
    QTextStream fout(outFile);
    output.push_front(path);
    for(int i=0;i<output.size()-1;i++)
    {
        if(output[i]=='\n'&&output[i-2]!='\n')
        {
            i++;
            output.insert(i,path);
            i+=path.size();
        }
    }
    output.append("\r\n"+fn);
    fout<<output;
    delete outFile;
    delete file;
}

QString Window::getPath()
{
    QString path = this->ui->openFileName->text();
    for(int i = path.size()-1;i>=0;i--)
    {
        if(path[i]!='/')path.remove(path.size()-1,1);
        else
        {
            path.remove(path.size()-1,1);
            break;
        }
    }
    return path;
}
