#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QVector>
#include <QFileDialog>
#include <QTextStream>


struct FeatureVectorBool
{
    bool stage1;
    bool stage2[2][2];
    bool stage3[4][4];
};
struct FeatureVector
{
    qreal stage1;
    qreal stage2[2][2];
    qreal stage3[4][4];
    long long time;
    void addFeatureVectorBool(FeatureVectorBool a);
    FeatureVector();
};



namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent* e);
private slots:
    void createVectorSlot();
    void openFile();
private:
    void createVector(QImage image,int num);
    void loadImage(QString fn);
    Ui::Widget *ui;
    QVector<FeatureVector> featureVectors;
    QImage* num[4];
};

#endif // WIDGET_H
