//*******************************************************************************//
//Name :      Reyoung
//School :      Tju
//QQ :      383147262
//licence :  LGPL
//*******************************************************************************//
#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include <QProcess>
#include <QStringList>

namespace Ui {
    class Window;
}

class Window : public QWidget {
    Q_OBJECT
public:
    Window(QWidget *parent = 0);
    ~Window();
    typedef enum{
        BN_PRO,BN_ERR
    }BaseNameType;
    static void makeProListFile(const QString fn);
protected:
    void changeEvent(QEvent *e);
private slots:
    void on_open_clicked();
    void on_save_clicked();
    void on_start_clicked();
private:
    int getLevel()const;
    QString getBaseName()const;
    BaseNameType getBaseNameType()const;
    void handleBaseNameType(BaseNameType a)const;
    QString getPath();
    Ui::Window *ui;
};

#endif // WINDOW_H
